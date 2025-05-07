#include <iostream> //cin cout
#include <locale.h> //teclado em português

// Este é um exemplo de programa em C++

using namespace std;

//Retorna o enésimo elemento Fibonacci
int Fib(int N){
    int Res;
    
    //condição de parada
    if (N==0){
        Res = 0;
    }   
    else{
        if (N==1){
            Res=1;
        }
        else{
            Res = Fib(N-1) + Fib (N-2);   
        }
    }
       
    
    return Res;       
}


//Alterado = 0 (não mudou), Alterado = 1 (Mudou)
int main () {   
    setlocale (LC_ALL,"Portuguese");
    
    cout << Fib(6);
           
    return 0;
}
