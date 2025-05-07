
// Multiplicação de dois números naturais, através de somas sucessivas (Ex.:6*4 =4 + 4 + 4 + 4 + 4 + 4).
#include <iostream>
#include <locale.h>
#include <iomanip>
#include <math.h>

using namespace std;

int conta(int numero,int numerodevez)
{   int ret;

	if (numerodevez ==0)
	{
		ret= 0;
	}
	else
	{ 
		ret= numero + conta (numero, numerodevez-1);
		//cout<<ret<<endl;
	}
	cout<<ret<<endl;
	return ret;

}


int main () {
	setlocale (LC_ALL,"Portuguese");
	
	int numerodevez;
	int numero;
//	int resultado;
	
	
	cout<<"numero";
	cin>>numero;
	cout<<"numero de vezes";
	cin>>numerodevez;
	
	
	conta(numero, numerodevez);
	//cout<<conta(numero, numerodevez);
	return 0;
}

