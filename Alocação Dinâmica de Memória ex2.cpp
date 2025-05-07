/*
2. Faça uma rotina recursiva para calcular a somatória de todos os número de 1 a N (N 
será lido do teclado). 
Observação: Se N é igual a 5 por exemplo, A somatória dos números será igual a 15, ou 
seja, 1+2+3+4+5 = 15 . 
*/

#include <iostream>
#include <locale.h>
#include <stdlib.h>
using namespace std;

int soma(int numero)
{/*
    if(numero==1)
        return 1;
    else*/
        return numero+soma(numero-1);
}

int main()
{
    int numero;

    cout<<"digite o numero que sera somado";
    cin>> numero;

    cout<<"resultado "<<soma(numero)<<endl;
}
