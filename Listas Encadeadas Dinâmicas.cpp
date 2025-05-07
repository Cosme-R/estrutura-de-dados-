#include <iostream>
#include <locale.h>
#include <stdlib.h>

using namespace std;

//Inicializa com ponteiro NULL indicando final da lista e grava início da Lista
//Insere e remove alterando o valor do ponteiro prox e considerando a ordenação
//Não tem limite para tamanho máximo
struct Dados_Enc_Dinamica{
    int RG;
    string Nome;
    string Endereco;
    struct Dados_Enc_Dinamica* prox;
};

//header ou cabeçalho ou cabeça
struct Lista_Enc_Dinamica{
    struct Dados_Enc_Dinamica* Inicio;   
    int Tamanho;
};

void Ini_Lista_Enc_Dinamica(Lista_Enc_Dinamica* Lista){
    Lista->Inicio = NULL;
    Lista->Tamanho=0;
}

struct Dados_Enc_Dinamica* CriaNovoItemDin(int RG, string Nome, string Endereco){
    struct Dados_Enc_Dinamica* Ret;
    
    Ret = new Dados_Enc_Dinamica;
    //Ret= (Dados_Enc_Dinamica  *) malloc(sizeof (Dados_Enc_Dinamica));
    Ret->RG = RG;
    Ret->Nome = Nome;   
    Ret->Endereco = Endereco;   
    Ret->prox = NULL;   
    
    return Ret;
}

void InsereNovoItemDin(Lista_Enc_Dinamica* Lista, int RG, string Nome, string Endereco){
    struct Dados_Enc_Dinamica *Item, *Aux, *Ant;
       
    //Aloca espaço, grava os dados e retorna o ponteiro pro elemento   
    Item = CriaNovoItemDin(RG, Nome, Endereco);
    if (Lista->Tamanho == 0){//Lista Vazia
        Lista->Inicio = Item;
        //Lista->Inicio->prox = NULL;
    }
    else{// Precisa encontrar a posição correta
        if( RG < Lista->Inicio->RG){ //Insere no início da lista
            Item->prox = Lista->Inicio;
            Lista->Inicio = Item;
        }
        else{ //Insere no meio ou final
            Aux = Lista->Inicio;
            while(RG > Aux->RG && Aux->prox != NULL){ //Procura na lista a posição de inserção
                Ant = Aux;
                Aux = Aux->prox;
            }
               
            if (RG < Aux->RG) { //Meio da lista
                Ant->prox = Item;                       
                Item->prox = Aux;           
            }       
            else{ //Chegou ao final da lista
                Aux->prox = Item;
            }   
        }               
    }
    
    Lista->Tamanho++;
}

void ImprimeListaDin(Dados_Enc_Dinamica* Item){
    if (Item != NULL){
        //imprime o item na tela
        cout << endl << "Item: " << Item->RG <<", Nome: " << Item->Nome;
        ImprimeListaDin(Item->prox);
    }
}

void LimparMemoria(Dados_Enc_Dinamica* Item){
    if (Item != NULL){
        //imprime o item na tela
        LimparMemoria(Item->prox);
    }
    
    free(Item);
}

Lista_Enc_Dinamica Lista;
main () {
    setlocale (LC_ALL,"Portuguese");   
    Ini_Lista_Enc_Dinamica(&Lista);   
    InsereNovoItemDin(&Lista, 3, "José", "Rua C"); //Lista Vazia                       
    InsereNovoItemDin(&Lista, 1, "Valtemir", "Rua A");//Primeiro elemento
    InsereNovoItemDin(&Lista, 2, "Carlos", "Rua B"); //Meio da lista
    InsereNovoItemDin(&Lista, 4, "Antonio", "Rua D");    //Final da lista   

    if (Lista.Tamanho > 0){
        ImprimeListaDin(Lista.Inicio);
       
        LimparMemoria(Lista.Inicio);               
    }   
}
