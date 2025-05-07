

//Soma de dois números naturais, através de incrementos sucessivos (Ex.:3 + 4 = 1+1+ 1+1 + 3).

#include <iostream>
#include <locale.h>
#include <iomanip>
#include <math.h>
using namespace std;

int conta(int n1, int n2, int n3)
{   int ret=1;

	//n3 = 0;
	n3 = n1 + n2;
	
	if (n3 ==0)
	{
		ret= 0;
	}
	else
	{
		 ret = ret + conta  (n1, n2-1, n3);
	}

	cout << ret << endl;
	return ret;
}


int main () {
	setlocale (LC_ALL,"Portuguese");
	
	int n1;
	int n2;
	//int n3;
//	int resultado;
	
	
	cout<<"digite o primeiro numero";
	cin>>n1;
	cout<<"digite o segundo numero";
	cin>>n2;
	

conta( n1, n2, 0);


	return 0;
}

