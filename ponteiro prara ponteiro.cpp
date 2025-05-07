#include <iostream>
#include <stdlib.h>

using namespace std;

void CalcularArea(float raio, float **perimetro, float **area){
    
    *perimetro = (float *) malloc(sizeof(float)); //criação dos endereços
    *area = (float *) malloc(sizeof(float));
    
    *(*perimetro) = raio*2*3.14;
    *(*area = raio*raio*3.14;
}


float *P, *A;
main(){
    setlocale(LC_ALL, "Portuguese");
    
    CalcularArea(10, &P, &A);
    cout << endl << "O perímetro vale: " << *P;
    cout << endl << "A área vale: " << *A;
}
