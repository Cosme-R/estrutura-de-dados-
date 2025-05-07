/*
5.Escreva uma função recursiva em linguagem C++ para calcular o valor de x elevado a n
*/
#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include<string.h>



using namespace std;

float potencia(float base, float expoente)
{
	float ret;
	
	if(expoente == 0)
	{
		ret = 1;
	}
	else
	{
		if (expoente > 0)
		{
			ret = base * potencia (base, expoente-1);
		}
	
	}
	return ret;
}



main()
{
	
	float ret;
	float base, expoente;
	
	cout<<"digite a base";
	cin>>base;
	cout<<"digite o expoente";
	cin>>expoente;

	ret = potencia(base,expoente);
//	cout<<ret;
}





/*

int repetenome(int vezes, string nome)
{
    int ret;
    
    if(vezes == 0)
	{
        return 1;
    }
    else
	{
        cout << endl<<nome;
        ret = vezes * repetenome(vezes-1, nome); 
    }
    return ret;
}



int vezes, ret;
string nome; 

int main()
{

  
    cout << "Informe a quantidade vezes ";
    cin >> vezes;
    cout << "Informe o nome: ";
    cin >> nome;
    repetenome(vezes, nome);
   
}
*/
