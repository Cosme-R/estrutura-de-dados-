#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
/*

*/

using namespace std;

#define MAX 10

struct Dados{
    int Valor;
    int Ordem;
};

//Carrega o vetor com valores aleatórios
void CarregaLista(Dados L[MAX], int GeraDados){
    int Cont;
    
    if (GeraDados){
        for(Cont=0;Cont<MAX;Cont++){
            L[Cont].Valor = rand()%100;
            L[Cont].Ordem = Cont;
        }        
    }
    else{
        L[0].Valor = 3; L[1].Valor = 0; L[2].Valor = 1; L[3].Valor = 8; L[4].Valor = 7;
        L[0].Ordem = 0; L[1].Ordem = 1; L[2].Ordem = 2; L[3].Ordem = 3; L[4].Ordem = 4;
        L[5].Valor = 2; L[6].Valor = 5; L[7].Valor = 4; L[8].Valor = 9; L[9].Valor = 6;
        L[5].Ordem = 5; L[6].Ordem = 6; L[7].Ordem = 7; L[8].Ordem = 8; L[9].Ordem = 9;
    }    
}

void ImprimeLista(Dados L[MAX]){
    int Cont;
    
    for(Cont=0;Cont<MAX;Cont++){
        cout <<    "[" << L[Cont].Ordem << "] " << L[Cont].Valor << ", ";
    }        
}

void Swap(Dados L[MAX], int PosA, int PosB){
    Dados Aux;
    
    Aux = L[PosA];
    L[PosA] = L[PosB];
    L[PosB] = Aux;    
}

void SelectionSort(Dados L[MAX]){
    int Cont1, Cont2, Min;
    
    for(Cont1=0;Cont1<MAX;Cont1++){
        Min = Cont1;
        
        //Procura o valor mínimo na lista não ordenada
        for (Cont2=Cont1+1;Cont2<MAX;Cont2++) {        
            if (L[Min].Valor > L[Cont2].Valor){
                Min = Cont2;                
            }        
        }    
        
        //Move o valor encontrado pra lista ordenada
        Swap(L, Cont1, Min);
    }                
}

void SelectionSortRec(Dados L[MAX], int Inicio, int Fim){

    int Cont2, Min;

    

    if (Inicio < Fim){

        Min = Inicio;

        

        //Procura o valor mínimo na lista não ordenada

        for (Cont2=Inicio+1;Cont2<Fim;Cont2++) {        

            if (L[Min].Valor > L[Cont2].Valor){

                Min = Cont2;                

            }        

        }    

        

        //Move o valor encontrado pra lista ordenada

        Swap(L, Inicio, Min);

        

        SelectionSortRec(L, Inicio + 1, Fim);      //for(Cont1=0;Cont1<MAX;Cont1++){         

    } 	

}



void SelectionSortRecBack(Dados L[MAX], int Inicio, int Fim){

    int Cont2, Min;

    

    if (Inicio >= 0){

    	SelectionSortRecBack(L, Inicio-1, Fim); //Inicio=0 e Fim = 1

    	

        Min = Inicio;

        

        //Procura o valor mínimo na lista não ordenada

        for (Cont2=Inicio+1;Cont2<Fim;Cont2++) {        

            if (L[Min].Valor > L[Cont2].Valor){

                Min = Cont2;                

            }        

        }    

        

        //Move o valor encontrado pra lista ordenada

        Swap(L, Inicio, Min);                         

    } 	

}


void InsertionSort(Dados L[MAX]){
    int Cont1, Cont2, Min;
    
    for(Cont1=1;Cont1<MAX;Cont1++){
        Cont2 = Cont1; //Próximo item da lista não ordenada
        
        //Move o próximo item da lista não ordenada para
        //a posição correta na lista ordenada
        while (Cont2 > 0 && L[Cont2].Valor < L[Cont2-1].Valor ) {        
            //Move o valor encontrado pra lista ordenada
            Swap(L, Cont2, Cont2-1);
            
            Cont2--;    
        }            
    }                
}

void BubbleSort(Dados L[MAX]){
    int Cont1, Cont2, FezSwap;
    
    Cont1=0;
    do{    
        FezSwap = 0;    
        //Traz, a partir do fim da lista, cada menor valor
        //até achar algum valor maior que ele. Se achar,
        //passa a fazer o mesmo com esse novo valor
        for (Cont2=MAX-1;Cont2>Cont1;Cont2--) {        
            if (L[Cont2].Valor < L[Cont2-1].Valor){
                //Troca os valores de posição
                Swap(L, Cont2, Cont2-1);
                FezSwap = 1;
            }        
        }        
        
        Cont1++;                    
    } while (Cont1<MAX && FezSwap==1);
}


void MergeSort(Dados L[MAX], int Inicio, int Fim){
    int Meio, Cont, ContA, ContB;
    Dados* Aux;
    
    if (Inicio < Fim){
        Meio = (Inicio + Fim)/2;    
        
        //Quebra em vetores menores (metade)
        MergeSort(L, Inicio, Meio); //VetorA
        MergeSort(L, Meio+1, Fim); //VetorB
        
        //Junta as partes (merge), pegando sempre o menor elemento de cada parte
        //de forma ordenada
        ContA = Inicio;
        ContB = Meio+1;
        Cont = 0;
        Aux = (Dados *) malloc(sizeof(Dados) * (Fim - Inicio + 1));
        while (ContA <= Meio || ContB <= Fim){
            if (ContA > Meio){ //final do VetorA
                Aux[Cont] = L[ContB];
                ContB++;
            }            
            else{
                if (ContB > Fim){ //final do VetorB
                    Aux[Cont] = L[ContA];
                    ContA++;
                }
                else{
                    if (L[ContA].Valor < L[ContB].Valor){ //meio do VetorA
                        Aux[Cont] = L[ContA];
                        ContA++;    
                    }
                    else{ //meio do VetorB
                        Aux[Cont] = L[ContB];
                        ContB++;                        
                    }
                }
            }            
            Cont++; //passa para a próxima posição do vetor com o merge            
        }
        //cout << endl << "Valor de Cont: " << Cont;
        //Copia o merge ordenado dos vetores para o vetor original    
        for(Cont=Inicio;Cont<=Fim;Cont++){
            L[Cont].Valor = Aux[Cont - Inicio].Valor;
            L[Cont].Ordem = Aux[Cont - Inicio].Ordem;
        }    
        
        free(Aux);    
    }        
}

//Coloca os menor que o valor em Início à esquerda, deslocando os maiores
//paraa direita
//versão localizada embaixo do vídeo no link
void QuickSort(Dados L[MAX], int Inicio, int Fim){
    int Pivo, Cont, ContAux;
    Dados Aux;
    if (Inicio < Fim){
        //Processar posição do pivô, de forma que os elementos sucessivos
        //sejam maiores e os antecessores menores
        Pivo = Inicio;        
        for(Cont=Inicio+1;Cont<=Fim;Cont++){        
            ContAux = Cont;                      
            if(L[ContAux].Valor < L[Pivo].Valor){ //procura valor menor que o pivô    
                Aux = L[ContAux];               
                while(ContAux > Pivo){ //desloca valores à direita do pivô e move o valor menor para pos. anterior ao pivô          
                    L[ContAux] = L[ContAux-1];      
                    ContAux--;                    
                }
                L[ContAux] = Aux; //Atualiza o valor menor na posição do pivô              
                Pivo++; //muda o pivô para a posição seguinte que tem valor maior                    
            }
        }
                
        QuickSort(L, Inicio, Pivo-1);
        QuickSort(L, Pivo+1, Fim);
    }
}

//Objetivo é colocar o valor em Início como pivô
//(menores à esquerda/ maiores à direita)
//Troca do Início apenas no final das iterações
int EscolhePivo(Dados L[MAX], int Inicio, int Fim){
    int Pivo, Cont;
    
    Cont = Inicio;        
    Pivo = Fim + 1;
    do{    
        //Busca primeiro maior que o início da esquerda para a direita
        do{
            Cont++;            
        } while (L[Cont].Valor < L[Inicio].Valor && Cont < Fim);
        
        //Busca primeiro menor que o início da direita para a esquerda
        do{
            Pivo--;
        }            
        while (L[Inicio].Valor < L[Pivo].Valor && Pivo > Inicio);
                                
        if (Cont < Pivo){
            //Troca o maior pelo menor                        
            Swap(L, Cont, Pivo);
        }
        
    } while (Cont < Pivo); //precorre até os contadores se cruzarem
    
    //cout << endl << "SWAP Inicio: " << Inicio << " Pivo: " << Pivo;
    Swap(L, Inicio, Pivo); //Troca o pivô pelo início
    
    return Pivo;
}

//versão da apresentação
void QuickSortApr(Dados L[MAX], int Inicio, int Fim){
    int Pivo;

    if (Inicio < Fim){
        //Processar posição do pivô, de forma que os elementos sucessivos
        //sejam maiores e os antecessores menores
        Pivo = EscolhePivo(L, Inicio, Fim);
                            
        QuickSortApr(L, Inicio, Pivo-1);
        QuickSortApr(L, Pivo+1, Fim);
    }
}

//Objetivo tb é colocar o valor em Início como pivô,
//(menores à esquerda/ maiores à direita)
//Trocas do Inicio em cada iteração (versão do vídeo)
void QuickSortV(Dados L[MAX], int Inicio, int Fim, int Msg){
    int Pivo, ContIni, ContFim;

    if (Inicio < Fim){
        //Processar posição do pivô, de forma que os elementos sucessivos
        //sejam maiores e os antecessores menores
        Pivo = Inicio;        
        ContIni = Inicio;        
        ContFim = Fim + 1;
        do{    
        
            //Busca primeiro menor que o pivô da direita para a esquerda
            do{
                ContFim--;
            }            
            while (L[ContFim].Valor > L[Pivo].Valor && ContFim > Pivo);
            
            //Faz a troca
            if (ContFim > Pivo){
                Swap(L, Pivo, ContFim);
                if (Msg){
                    cout << endl << "Troca posição [" << Pivo << "] por [" << ContFim <<"]";
                }
                
                Pivo = ContFim;
                
                if (Msg){
                    cout << endl << "Pivô atualizado dir->esq: " << Pivo;    
                    cout <<    endl;
                    ImprimeLista(L);
                }
            }                            
                                            
            //Busca primeiro maior que o pivô da esquerda para a direita
            do{
                ContIni++;            
            } while (L[ContIni].Valor < L[Pivo].Valor && ContIni < Pivo);
                                    
            //Faz a troca
            if (ContIni < Pivo){
                Swap(L, ContIni, Pivo);
                if (Msg){
                    cout << endl << "Troca posição [" << ContIni << "] por [" << Pivo << "]";
                }    
                Pivo = ContIni;
                
                if (Msg){
                    cout << endl << "Pivô atualizado dir->esq: " << Pivo;    
                    cout <<    endl;
                    ImprimeLista(L);                
                }                
            }    
            
        } while (ContIni < ContFim);
        
        if (Msg){
            cout << endl << "Quicksort " << Inicio << " " << Pivo -1;                            
        }
        QuickSortV(L, Inicio, Pivo-1, Msg);
        
        if (Msg){
            cout << endl << "Quicksort " << Pivo+1 << " " << Fim;                            
        }
        QuickSortV(L, Pivo+1, Fim, Msg);
    }
}

Dados Lista[MAX];
clock_t T;
main () {
    setlocale (LC_ALL,"Portuguese");
    
    CarregaLista(Lista,0); //QuickSort - Exemplo vídeo
    //CarregaLista(Lista,1); //Demais exemplos
    
    if (MAX <= 100){
        cout << endl << endl << "Lista original" << endl << endl;    
        ImprimeLista(Lista);        
    }
    
    T = clock();
    //SelectionSort(Lista);
   //SelectionSortRec(Lista, 0, MAX);    

   //SelectionSortRecBack(Lista, MAX, MAX)

    //InsertionSort(Lista);
    //BubbleSort(Lista);
    //MergeSort(Lista, 0, MAX-1);
    //QuickSort(Lista, 0, MAX-1); //link abaixo do vídeo
    //QuickSortApr(Lista, 0, MAX-1); //apresentação
    cout << endl << "Quicksort " << 0 << " " << MAX -1;                            
    QuickSortV(Lista, 0, MAX-1, 1); //vídeo
    
    T = clock() - T;//tempo decorrido!!
    
    if (MAX <= 100){
        cout << endl << endl << "Lista ordenada" << endl << endl;    
        ImprimeLista(Lista);        
    }    
    
    cout << endl << endl << "Tempo de Ordenação: " << ((double) T)/((CLOCKS_PER_SEC/1000)) << " milisegundos.";

}