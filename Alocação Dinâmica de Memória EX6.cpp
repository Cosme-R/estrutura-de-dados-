/*
6. Fa�a um programa que leia um valor inteiro N n�o negativo. Se o valor de N for 
inv�lido, o usu�rio dever� digitar outro at� que ele seja v�lido (ou seja, positivo). Em 
seguida, leia um vetor V contendo N posi��es de inteiros, em que cada valor dever� ser 
maior ou igual a 2. Esse vetor dever� ser alocado dinamicamente. 
*/

#include <iostream>
#include <locale.h>
#include <stdlib.h>
using namespace std;

int main()
{
	
	int valor;
	int conta=0;
	int n=0;

    int *v = (int*) malloc (n * sizeof (int));


        cout << "digite o tamanho do vetor"<<endl;
        cin >> n;   

        while(conta != n)
		{
            cout << "informe um numero " <<endl;
        	cin >> valor;
                
            if(valor >= 2)
			{
                v[conta] = valor;
                conta = conta +1;
            }
            else
			{
                cout << " numero invalido "<<endl;
            }     
        }
        

}
