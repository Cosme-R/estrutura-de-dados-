/*
3. Escreva uma função que receba um valor inteiro positivo N por parâmetro e retorne o 
ponteiro para um vetor de tamanho N alocado dinamicamente. Se N for negativo ou 
igual a zero, um ponteiro nulo deverá ser retornado.
*/

#include <iostream>
#include <locale.h>
#include <stdlib.h>

using namespace std;


int alocando(int n)
{
    int *p = (int *) malloc ( n * sizeof (int) );
    
    if(n > 0)
	{
		 for(int conta = 1; conta <= n; conta++)
		{
	        p[conta] = conta;
	        cout << "v["<<conta<<"]:" << p[conta]<<endl;
	    }
	    return *p;
	    
    }
    else
	{
	    cout <<endl<<"nenhum vetor";
	    
	    return *p=0;	   
    }
    
}

int main()
{
    int n;
    
    cout << "digite o tamanho do vetor: "<<endl;
    cin >> n;
    
    alocando(n);
    
}
