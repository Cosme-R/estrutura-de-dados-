/*
2. Fa�a uma rotina recursiva para calcular a somat�ria de todos os n�mero de 1 a N (N 
ser� lido do teclado). 
Observa��o: Se N � igual a 5 por exemplo, A somat�ria dos n�meros ser� igual a 15, ou 
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
