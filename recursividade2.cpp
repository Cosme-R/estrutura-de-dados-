#include <iostream>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
float resul;
//Cálculo de 1 + 1/2 + 1/3 + 1/4 + ... + 1/N
float teste(float n){

	float aux ;
	//float resul =1;
	if(n>=1){
		aux =(1/n);
		resul = resul +aux;
		teste(n-1);
		//cout<<"aux é = a "<<aux<<endl;
		//cout<<"valor de n "<<n<<endl<<endl<<endl;
		
	} 
	return resul;
}

// Multiplicação de dois números naturais, através de somas sucessivas (Ex.:6*4 =4 + 4 + 4 + 4 + 4 + 4).
int ret = 0;
void natu (int n1 ,int n2){
    
    if(n1> 1){ // Condição de saida
        cout<<""<<n1<<endl;    
        natu(n1, ret+n2); // Chamando a si mesmo
    }
    cout<<""<<n2<<endl;
}

// Soma de dois números naturais, através de incrementos sucessivos (Ex.:3 + 4 = 1+1+1+1 + 3).
int incrementoNaturais;
int somaNaturais(int A, int B){
        if(B != incrementoNaturais){ 
        	somaNaturais(A, B+1) + A ; // chamando a si mesmo e só depois fazendo a soma        
        }
        else{  
            A = 0; 
        }
    
    return B;
}

int main(){
    setlocale(LC_ALL,"Portuguese");
	float n =5;
	teste(n);
    cout<<teste(n)<<endl;
//////////////////////////////////////////
	int n1=6;
	int n2=7;
	natu ( n1,n2);
/////////////////////////////////////////
 int A=5;
 int B=6;
cout<<somaNaturais( A, B);
////////////////////////////////////////
    return 0;
}
