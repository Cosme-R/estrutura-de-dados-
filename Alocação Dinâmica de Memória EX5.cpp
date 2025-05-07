/*
5.Escreva uma função recursiva em linguagem C++ para calcular o valor de x elevado a n
*/

#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include<string.h>


using namespace std;

float potencia(float x, float n )
{
	float ret;
	
	if(n  == 0)
	{
		ret = 1;
	}
	else
	{
		if (n  > 0)
		{
			ret = x * potencia (x, n -1);
		}
	
	}
	return ret;
}



main()
{
	
	float ret;
	float x;
	float n ;
	
	cout<<"digite a x";
	cin>>x;
	cout<<"digite o n ";
	cin>>n ;

	ret = potencia(x,n );
	cout<<ret;
}

