/*
4. Escreva uma função que receba como parâmetro dois vetores, A e B, de tamanho 
N cada. A função deve retornar o ponteiro para um vetor C de tamanho N alocado 
dinamicamente, em que C[i] = A[i] + B[i]. 
*/
#include <iostream>
#include <locale.h>
#include <stdlib.h>
using namespace std;

int *colandoemC(int *a, int *b, int n)

{
    int *c = (int*) malloc ( n * sizeof (int) );
    
    for (int cont=0; cont < n; cont ++)
	{
    c[cont] = a[cont] + b[cont];
    cout << endl << c[cont];
    }
    
    return c;
}

int main()
{
    int  n;
	int *c;
	
    cout << "digite o tamanho do vetor"<<endl;
    cin >> n;
    
    
    int *a = (int *) malloc ( n * sizeof (int) );
    int *b = (int *) malloc ( n * sizeof (int) );
    

    for (int conta=0; conta < n; conta ++)
	{
        cout <<endl<< "digite o valor do vetor [" << conta+1 << "] a:"<<endl;
        cin >> a[conta];
        
        cout <<endl<<"digite o valor do vetor [" << conta+1 << "] b:"<<endl;
        cin >> b[conta];
    }
    
    
    colandoemC(a, b, n);
    
 
    
    
}
