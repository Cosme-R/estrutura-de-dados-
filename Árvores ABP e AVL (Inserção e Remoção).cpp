#include <iostream>
using namespace std;

struct No{
    int ValorNum;
    int Bal; //Fator de balanceamento
    No* Esq;
    No* Dir;
};

//header ou cabeçalho ou cabeça
struct Arvore{
    No* Raiz;        
    int TotalElem;
};

//Pilha para armazenar os ancestrais de um nó
struct ItemPilha{
    No* NoArv;
    struct ItemPilha* Prox;
};

struct Pilha{
    struct ItemPilha* Topo;
    int Tamanho;
};

void IniPilha(Pilha* P){
    P->Topo = NULL;
    P->Tamanho = 0;
}

void Empilha(Pilha* P, No* NoArv){
    ItemPilha* Item;

    Item = (ItemPilha *) malloc(sizeof(ItemPilha));
    Item->NoArv = NoArv;
    Item->Prox = P->Topo;

    P->Topo = Item;
    P->Tamanho++;
}

ItemPilha* Desempilha(Pilha* P){
    ItemPilha* Item;

    if (P->Topo != NULL){
        Item = P->Topo;
        P->Topo = Item->Prox;
        P->Tamanho--;
    }
    else{
        Item = NULL;
    }

    return Item;
}

void ImprimePilha(Pilha *P, ItemPilha *Item){

    if (Item != NULL){    
        cout<<Item->NoArv->ValorNum<<", ";    
        ImprimePilha(P, Item->Prox);    
    }
}

void LimpaPilha(Pilha *P){
    ItemPilha *Item;
    if (P->Tamanho > 0){
        Item = Desempilha(P);
        free(Item);
        LimpaPilha(P);
    }
}

void Ini_Arvore(Arvore* Arv){
    Arv->Raiz = NULL;
    Arv->TotalElem = 0;
}

No* CriaNo(int ValorNum){
    No* Ret;
    
    Ret = new No;
    
    Ret->ValorNum = ValorNum;
    Ret->Bal = 0;
    Ret->Esq = NULL;    
    Ret->Dir = NULL;    
    
    return Ret;
}

//Encontrar item na árvore ordenada
No* EncontrarNo(No* NoArv, int ValorNum){
    No* Ret;
    

    if (NoArv == NULL){
        Ret = NULL;
    }
    else{
        if (ValorNum == NoArv->ValorNum){
            Ret = NoArv;            
        }
        else{
            //procura à esquerda (menor) ou direita (maior)
            if    (ValorNum < NoArv->ValorNum){
                Ret = EncontrarNo(NoArv->Esq, ValorNum);
            }            
            else{
                Ret = EncontrarNo(NoArv->Dir, ValorNum);
            }            
        }            
    }    
    
    return Ret;
}


No* BuscaPai(No* NoArv, int ValorNum, Pilha *P){
    No* Ret;
    
    if (NoArv != NULL){
        if (ValorNum == NoArv->ValorNum){
            Ret = NULL;            
        }
        else{
            Empilha(P, NoArv);
            if ((NoArv->Esq == NULL && ValorNum < NoArv->ValorNum) ||
                (NoArv->Dir == NULL && ValorNum > NoArv->ValorNum)){
                 // Encontrou posição
                 Ret = NoArv;        
            }
            else{
                //procura à esquerda (menor) ou direita (maior)
                if    (ValorNum < NoArv->ValorNum){
                    Ret = BuscaPai(NoArv->Esq, ValorNum, P);
                }            
                else{
                    Ret = BuscaPai(NoArv->Dir, ValorNum, P);
                }            
            }    
        }                
    }
        
    return Ret;
}

void Rot_dir(Arvore* Arv, No* Pai, Pilha* P){   
    No *U, *Avo;
    
    cout << endl << "Rotação à direita!!" << endl;               
    U = Pai->Esq;
    Pai->Esq = U->Dir;
    U->Dir = Pai;
    Pai->Bal = 0;
       
    if (Pai == Arv->Raiz){ //Atualiza raíz da árvore
        cout << endl << "Atualização da raíz para " << U->ValorNum <<endl;
        Arv->Raiz = U;       
        Arv->Raiz->Bal = 0;
    }
    else{ //Atualiza avô para apontar para o novo pai       
        Avo = P->Topo->NoArv; //Instancia o avô   
        cout << endl << "Atualização apontamento do pai de " << U->ValorNum << " para " << Avo->ValorNum << endl;
        if (Avo->ValorNum > U->ValorNum){
            Avo->Esq = U;
        }
        else{
            Avo->Dir = U;
        }       
        Avo->Bal = 0;
    }
}

void Rot_esq_dir(Arvore* Arv, No* Pai, Pilha* P){   
    No *U, *V, *Avo;
    
    cout << endl << "Rotação à esquerda-direita!!" << endl;               
    U = Pai->Esq;
    V = U->Dir;
    U->Dir = V->Esq;
    V->Esq = U;
    Pai->Esq = V->Dir;
    V->Dir = Pai;
    if (V->Bal == -1){
        Pai->Bal = 1;
    }
    else{
        Pai->Bal = 0;
    }
    
    if (V->Bal == 1){
        U->Bal = -1;
    }
    else{
        U->Bal = 0;
    }
    
    if (Pai == Arv->Raiz){ //Atualiza raíz da árvore
        cout << endl << "Atualização da raíz para " << V->ValorNum <<endl;
        Arv->Raiz = V;       
        Arv->Raiz->Bal = 0;
    }
    else{ //Atualiza avô para apontar para o novo pai       
        Avo = P->Topo->NoArv; //Instancia o avô   
        cout << endl << "Atualização apontamento do pai de " << V->ValorNum << " para " << Avo->ValorNum << endl;
        if (Avo->ValorNum > V->ValorNum){
            Avo->Esq = V;
        }
        else{
            Avo->Dir = V;
        }       
        Avo->Bal = 0;
    }
}

void Rot_dir_zero(Arvore* Arv, No* Pai, Pilha* P){   
    No *U, *Avo;
    
    U = Pai->Esq;
    if (U->Bal == 0){
        cout << endl << "Rotação à direita-zero!!" << endl;                   
        
        Pai->Esq = U->Dir;
        U->Dir = Pai;
        Pai->Bal = -1;
        U->Bal = 1;
                         
        if (Pai == Arv->Raiz){ //Atualiza raíz da árvore
            cout << endl << "Atualização da raíz para " << U->ValorNum <<endl;
            Arv->Raiz = U;       
        }
        else{ //Atualiza avô para apontar para o novo pai       
            Avo = P->Topo->NoArv; //Instancia o avô   
            cout << endl << "Atualização apontamento do pai de " << U->ValorNum << " para " << Avo->ValorNum << endl;
            if (Avo->ValorNum > U->ValorNum){
                Avo->Esq = U;
            }
            else{
                Avo->Dir = U;
            }       
        }        
    }    
}

void Rot_esq(Arvore* Arv, No* Pai, Pilha* P){   
    No *U, *Avo;
    
    cout << endl << "Rotação à esquerda!!" << endl;               
    U = Pai->Dir;
    Pai->Dir = U->Esq;
    U->Esq = Pai;
    Pai->Bal = 0;
       
    if (Pai == Arv->Raiz){ //Atualiza raíz da árvore
        cout << endl << "Atualização da raíz para " << U->ValorNum <<endl;
        Arv->Raiz = U;       
        Arv->Raiz->Bal = 0;
    }
    else{ //Atualiza avô para apontar para o novo pai       
        Avo = P->Topo->NoArv; //Instancia o avô   
        cout << endl << "Atualização apontamento do pai de " << U->ValorNum << " para " << Avo->ValorNum << endl;
        if (Avo->ValorNum > U->ValorNum){
            Avo->Esq = U;
        }
        else{
            Avo->Dir = U;
        }       
        Avo->Bal = 0;
    }
}

void Rot_dir_esq(Arvore* Arv, No* Pai, Pilha* P){   
    No *U, *V, *Avo;
    
    cout << endl << "Rotação à direita-esquerda!!" << endl;               
    U = Pai->Dir;
    V = U->Esq;
    U->Esq = V->Dir;
    V->Dir = U;
    Pai->Dir = V->Esq;
    V->Esq = Pai;
    if (V->Bal == 1){
        Pai->Bal = -1;
    }
    else{
        Pai->Bal = 0;
    }
    
    if (V->Bal == -1){
        U->Bal = 1;
    }
    else{
        U->Bal = 0;
    }
    
    if (Pai == Arv->Raiz){ //Atualiza raíz da árvore
        cout << endl << "Atualização da raíz para " << V->ValorNum <<endl;
        Arv->Raiz = V;       
        Arv->Raiz->Bal = 0;
    }
    else{ //Atualiza avô para apontar para o novo pai       
        Avo = P->Topo->NoArv; //Instancia o avô   
        cout << endl << "Atualização apontamento do pai de " << V->ValorNum << " para " << Avo->ValorNum << endl;
        if (Avo->ValorNum > V->ValorNum){
            Avo->Esq = V;
        }
        else{
            Avo->Dir = V;
        }       
        Avo->Bal = 0;
    }
}

void Rot_esq_zero(Arvore* Arv, No* Pai, Pilha* P){   
    No *U, *Avo;
    
    U = Pai->Dir;
    if (U->Bal == 0){
        cout << endl << "Rotação à esquerda-zero!!" << endl;                   
        
        Pai->Dir = U->Esq;
        U->Esq = Pai;
        Pai->Bal = 1;
        U->Bal = -1;
                         
        if (Pai == Arv->Raiz){ //Atualiza raíz da árvore
            cout << endl << "Atualização da raíz para " << U->ValorNum <<endl;
            Arv->Raiz = U;       
        }
        else{ //Atualiza avô para apontar para o novo pai       
            Avo = P->Topo->NoArv; //Instancia o avô   
            cout << endl << "Atualização apontamento do pai de " << U->ValorNum << " para " << Avo->ValorNum << endl;
            if (Avo->ValorNum > U->ValorNum){
                Avo->Esq = U;
            }
            else{
                Avo->Dir = U;
            }       
        }        
    }    
}

void BalancearAVL(Arvore* Arv, Pilha* P, char Lado, string Op){
    ItemPilha *Pai;
    No *U;
    int Bal;
    
    if (P->Tamanho > 0){ //Há ancestrais para analisar na pilha
        //verifica qual lado do pai está havendo a inserção
        if (Lado == 'E' && Op== "INS" || Lado == 'D' && Op == "REM" ){
            Bal = -1;
        }
        else{
            Bal = 1;
        }   
        Pai = Desempilha(P);       
        Pai->NoArv->Bal += Bal; //atualiza o fator de balanceamento
       
        cout << endl << "Atualizando fator para pai " << Pai->NoArv->ValorNum << " Bal = " << Pai->NoArv->Bal << endl;
       
        //Verifica se houve desbalanceamento
        switch(Pai->NoArv->Bal){
            case -1:
            case 1:               
                if (P->Tamanho > 0){
                    //verifica se está à direita ou esquerda do avô para propagar o balanceamento
                    if (P->Topo->NoArv->ValorNum < Pai->NoArv->ValorNum){
                        Lado = 'D';
                    }
                    else{
                        Lado = 'E';
                    }
               
                    BalancearAVL(Arv, P, Lado, Op);   
                }                               
                break;
            case -2:
                U = Pai->NoArv->Esq;               
                if (U->Bal == -1){
                    Rot_dir(Arv, Pai->NoArv, P);
                }
                else{
                    if (U->Bal == 0 && Op == "REM"){
                        Rot_dir_zero(Arv, Pai->NoArv, P);
                    }
                    else{
                        Rot_esq_dir(Arv, Pai->NoArv, P);    
                    }                    
                }
               
                //Pai->NoArv->Bal = 0; //Atualizado nas funções de rotação, pois mda o pai após a rotação
                break;
            case 2:
                U = Pai->NoArv->Dir;                                   
                if (U->Bal == 1){
                    Rot_esq(Arv, Pai->NoArv, P);
                }
                else{
                    if (U->Bal == 0 && Op == "REM"){
                        Rot_esq_zero(Arv, Pai->NoArv, P);
                    }
                    else{                    
                        Rot_dir_esq(Arv, Pai->NoArv, P);
                    }
                }
                               
                //Pai->NoArv->Bal = 0; //Atualizado nas funções de rotação, pois mda o pai após a rotação
                break;               
        //    default: //0 - nada a fazer, pois a altura da subárvore nãpfoi modificada
        }
    }
}

No* InsereNoArv(Arvore* Arv, int ValorNum, No* NoPai, string TipoLig){
    No *Item, *Aux;
    int Erro = 0;
    char Lado;
    Pilha P;
        
    //Aloca espaço, grava os dados e retorna o ponteiro pro elemento    
    Item = CriaNo(ValorNum);
    if (Arv->Raiz == NULL){//Árvore Vazia
        Arv->Raiz = Item;            
    }
    else{
        if (NoPai != NULL){// Se passou o pai, insere diretamente
            if (TipoLig == "E"){
                NoPai->Esq = Item;    
            }
            else{
                NoPai->Dir = Item;
            }                
        }
        else{    //Não passa o pai, vai procurar qual pai deve ser usado para inserção
            IniPilha(&P);
            Aux = BuscaPai(Arv->Raiz, ValorNum, &P); //Busca o pai e carrega a pilha de ancestrais
            if (Aux != NULL){            
                if (ValorNum < Aux->ValorNum){
                    Aux->Esq = Item;
                    Lado = 'E';                
                }
                else{
                    Aux->Dir = Item;
                    Lado = 'D';
                }
                
                BalancearAVL(Arv, &P, Lado, "INS");
            }                
            else{
                cout << endl << "Item " << ValorNum << " já existe!!";
                Erro = 1;
            }    
            
            LimpaPilha(&P);                
        }        
    }
    
    if (Erro == 0){
        Arv->TotalElem++;    
    }
        
    return Item;
}

void ImprimeArvore(No* NoArv, string Tipo) {
    string TextoEsq = "NULL", TextoDir = "NULL";    
    
    if (NoArv != NULL){
        if (NoArv->Esq != NULL){
            TextoEsq =     to_string(NoArv->Esq->ValorNum);
        }

        if (NoArv->Dir != NULL){
            TextoDir =     to_string(NoArv->Dir->ValorNum);
        }        
        
        //imprime o item na tela
        if (Tipo == "PRE") {
            /*cout << NoArv->ValorNum << ", ";*/
            cout << "Pai:" << NoArv->ValorNum << endl;
            cout <<"Filho Esq: " << TextoEsq  << endl;
            cout <<"Filho Dir: " << TextoDir  << endl << endl;
        }
        
        ImprimeArvore(NoArv->Esq, Tipo);
        
        if (Tipo == "CEN") {
            /*cout << NoArv->ValorNum << ", ";*/
            cout << "Pai:" << NoArv->ValorNum << endl;
            cout <<"Filho Esq: " << TextoEsq  << endl;
            cout <<"Filho Dir: " << TextoDir  << endl << endl;
        }        
        
        ImprimeArvore(NoArv->Dir, Tipo);
        
        if (Tipo == "POS") {
            /*cout << NoArv->ValorNum << ", ";*/
            cout << "Pai:" << NoArv->ValorNum << endl;
            cout <<"Filho Esq: " << TextoEsq  << endl;
            cout <<"Filho Dir: " << TextoDir  << endl << endl;
        }                
    }
}

//Calcular a altura da árvore
int Altura(No* NoArv){
    int AltEsq, AltDir, Ret;
    
    if (NoArv == NULL){
         Ret = -1; //altura da arvore vazia
    }else{
        //verificar a altura da árvore da esquerda
        AltEsq = Altura(NoArv->Esq);

        //verificar a altura da árvore da direita
        AltDir = Altura(NoArv->Dir);
        
        //ramo mais alto + raíz
        if(AltEsq<AltDir){
            Ret =  AltDir + 1;
        }else{
            Ret =  AltEsq + 1;
        }
        
        /*cout << endl << "Nó atual: " << NoArv->ValorTexto << " Ret: " << Ret << endl;
        system("pause");*/
    }    
    
    return Ret;
}

No* acha_menor(No* NoArv) {
    No* Ret;

    if(NoArv->Esq == NULL) {
        Ret = NoArv;
    }
    else{
        Ret = acha_menor(NoArv->Esq);
    }

    return Ret;
}

No* remove(Arvore* Arv, No* NoArv, int ValorNum, Pilha* Pais, char Lado) {
     No *Ret, *Suc;
     if(NoArv == NULL) {      
         Ret = NULL;
         cout << "Elemento ausente!!" << endl;
    }
     else {
         Ret = NoArv; //FALTOU INICIALIZAR O RET COM O VALOR DO NÓ ATUAL!!!!!!
         if(ValorNum < NoArv->ValorNum){
             Empilha(Pais, NoArv);
            NoArv->Esq = remove(Arv, NoArv->Esq, ValorNum, Pais, 'E');
        }    
        else{
             if(ValorNum > NoArv->ValorNum){
                 Empilha(Pais, NoArv);
                NoArv->Dir = remove(Arv, NoArv->Dir, ValorNum, Pais, 'D');                
            }                
            else{
                if(NoArv->Esq == NULL && NoArv->Dir == NULL) { /* zero filhos */
                     free(NoArv);
                    Ret = NULL;             
                    if (Pais->Tamanho > 0){ //pode necessitar balanceamento
                        BalancearAVL(Arv, Pais, Lado, "REM");
                    }
                    else{
                        Arv->Raiz = Ret; //Atualiza a raíz, caso não haja mais pais na pilha
                    }
                }                
                else{
                    if(NoArv->Esq == NULL) { /* 1 filho */
                         Ret = NoArv->Dir;
                        if (Pais->Tamanho > 0){ //pode necessitar balanceamento
                            BalancearAVL(Arv, Pais, Lado, "REM");
                        }                 
                        else{
                            Arv->Raiz = Ret;  //Atualiza a raíz, caso não haja mais pais na pilha
                        }        
                         free(NoArv);
                    }                
                    else{
                        if(NoArv->Dir == NULL) { /* 1 filho */                             
                            Ret = NoArv->Esq;                 
                            if (Pais->Tamanho > 0){ //pode necessitar balanceamento
                                BalancearAVL(Arv, Pais, Lado, "REM");
                            }
                            else{
                                Arv->Raiz = Ret;  //Atualiza a raíz, caso não haja mais pais na pilha
                            }                            
                            free(NoArv);
                        }
                        else{ /* 2 filhos */
                            Empilha(Pais, NoArv); //Cadastra o nó na pilha de pais para poder remover/balancear o menor filho à direita (realmente excluído)
                            Suc = acha_menor(NoArv->Dir);
                            //Grava os valores do sucessor por cima do nó a ser eliminado
                            NoArv->ValorNum = Suc->ValorNum;                                
                            //Não precisa propagar o balanceamento a partir daqui, mas sim a partir do nó que é realmente excluído (Suc)!!
                            NoArv->Dir = remove(Arv,NoArv->Dir, Suc->ValorNum, Pais, 'D');                            
                            Ret = NoArv;                
                        }
                    }
                }
            }
        }
    }    
    
    return Ret;
}

void InserePreOrdem(No* NoArv, No* Vetor, int *Pos) {
        
    if (NoArv != NULL){        
        Vetor[*Pos] = *NoArv;
        //cout << "Valor de Pos:" << *Pos << " e item no vetor " << Vetor[*Pos].ValorNum << endl;
        (*Pos)++;                        
        
        InserePreOrdem(NoArv->Esq, Vetor, Pos);
         InserePreOrdem(NoArv->Dir, Vetor, Pos);
     }         
}

No* GeraVetorABP(Arvore* Arv, int MostraTela){
    No* Vetor;
    int Pos = 0, Cont;

    if (Arv->TotalElem > 0){
        Vetor = (No *) malloc(sizeof(No)*(Arv->TotalElem)); //Aloca espaço no vetor parao total de elementos da árvore
        InserePreOrdem(Arv->Raiz, Vetor, &Pos);        
        
        if (MostraTela==1){
            cout <<endl << endl << "Vetor gerado BPL" << endl << endl;
            for (Cont=0;Cont<Arv->TotalElem;Cont++){
                cout << Vetor[Cont].ValorNum << ", ";
            }
            cout << endl;
        }
    }    
    
    return Vetor;
}

No* GeraArvoreABP(Arvore* Arv, No* Vetor, int Inicio, int Fim){
    int Pos, Meio;
    No* Ret;
    
    if (Inicio > Fim){
        Ret = NULL; // Não encontrou!!
    }
    else{
        Meio = (Inicio + Fim)/2;
        Ret = Vetor + Meio; //Aponta para a metade relativa do vetor
        //cout << "Valor do Ret: " << Ret->ValorNum << endl;
        Ret->Esq = GeraArvoreABP(Arv, Vetor, Inicio, Meio-1);
        Ret->Dir = GeraArvoreABP(Arv, Vetor, Meio+1, Fim);
    }
    
    return Ret;
}
 
Arvore Arv;
No *Vetor;
Pilha PilhaPaisRem;
main (){
    setlocale (LC_ALL,"Portuguese");
    
    Ini_Arvore(&Arv);        
    IniPilha(&PilhaPaisRem);
    
    //Teste ABP                                     
    /*InsereNoArv(&Arv, 1, NULL, "");
    InsereNoArv(&Arv, 2, NULL, "");                             
    InsereNoArv(&Arv, 3, NULL, "");
    InsereNoArv(&Arv, 4, NULL, "");
    InsereNoArv(&Arv, 5, NULL, "");*/
        
    //*********************** AVL - INSERÇÃO
    //Teste AVL - Rotação à direita
    /*InsereNoArv(&Arv, 10, NULL, "");
    InsereNoArv(&Arv, 5, NULL, "");     
    InsereNoArv(&Arv, 15, NULL, "");
    InsereNoArv(&Arv, 3, NULL, "");                                  
    InsereNoArv(&Arv, 1, NULL, "");*/
    
    //Teste AVL - Rotação à esquerda-direita
    /*InsereNoArv(&Arv, 5, NULL, "");
    InsereNoArv(&Arv, 2, NULL, "");
    InsereNoArv(&Arv, 10, NULL, "");
    InsereNoArv(&Arv, 1, NULL, "");            
    InsereNoArv(&Arv, 3, NULL, "");                                 
    InsereNoArv(&Arv, 4, NULL, "");*/
    
    //Teste AVL - Rotação à esquerda
    /*InsereNoArv(&Arv, 10, NULL, "");
    InsereNoArv(&Arv, 5, NULL, "");     
    InsereNoArv(&Arv, 15, NULL, "");
    InsereNoArv(&Arv, 18, NULL, "");                                  
    InsereNoArv(&Arv, 20, NULL, "");*/    
    
    //Teste AVL - Rotação à direita-esquerda
    /*InsereNoArv(&Arv, 5, NULL, "");
    InsereNoArv(&Arv, 2, NULL, "");
    InsereNoArv(&Arv, 10, NULL, "");
    InsereNoArv(&Arv, 12, NULL, "");
    InsereNoArv(&Arv, 7, NULL, "");            
    InsereNoArv(&Arv, 6, NULL, "");*/                                     
    
    //*********************** AVL - REMOÇÃO
    //Rotação à direita (1.1)
       /*InsereNoArv(&Arv, 10, NULL, "");
    InsereNoArv(&Arv, 5, NULL, "");     
    InsereNoArv(&Arv, 15, NULL, "");
    InsereNoArv(&Arv, 3, NULL, ""); */
    
    //Rotação à esquerda-direita (1.2)
       /*InsereNoArv(&Arv, 10, NULL, "");
    InsereNoArv(&Arv, 5, NULL, "");     
    InsereNoArv(&Arv, 15, NULL, "");
    InsereNoArv(&Arv, 6, NULL, "");*/     
    
    //Rotação à esquerda (2.1)
       /*InsereNoArv(&Arv, 30, NULL, "");
    InsereNoArv(&Arv, 15, NULL, "");     
    InsereNoArv(&Arv, 40, NULL, "");
    InsereNoArv(&Arv, 50, NULL, "");*/
    
    //Rotação à direita-esquerda (2.2)
    /*InsereNoArv(&Arv, 30, NULL, "");
    InsereNoArv(&Arv, 15, NULL, "");     
    InsereNoArv(&Arv, 40, NULL, "");
    InsereNoArv(&Arv, 35, NULL, "");     */
            
    //Rotação à direita-zero (1.3)
    /*InsereNoArv(&Arv, 10, NULL, "");
    InsereNoArv(&Arv, 5, NULL, "");     
    InsereNoArv(&Arv, 15, NULL, "");
    InsereNoArv(&Arv, 3, NULL, "");
    InsereNoArv(&Arv, 6, NULL, ""); */
    
    //Rotação à esquerda-zero (2.3)
    InsereNoArv(&Arv, 30, NULL, "");
    InsereNoArv(&Arv, 15, NULL, "");     
    InsereNoArv(&Arv, 40, NULL, "");
    InsereNoArv(&Arv, 35, NULL, "");
    InsereNoArv(&Arv, 50, NULL, "");
    
    if (Arv.Raiz != NULL){        
        cout << endl << "Pré-Ordem - Árvore Original ABP/ Árvore Balanceada AVL [Inserção]" << endl << endl;
        ImprimeArvore(Arv.Raiz, "PRE");                    
        //Teste ABP
        //Vetor = GeraVetorABP(&Arv, 1);
        //Arv.Raiz = GeraArvoreABP(&Arv, Vetor, 0, (Arv.TotalElem-1));

        //Teste AVL    - Remoção        
        remove(&Arv, Arv.Raiz, 15, &PilhaPaisRem, 'C'); //retorna o ponteiro pra atualziar a raíz, caso ela seja o único nó
        cout << endl << endl << "Pré-Ordem - Árvore Balanceada AVL [Remoção]" << endl << endl;        
        ImprimeArvore(Arv.Raiz, "PRE");    
    }
}
