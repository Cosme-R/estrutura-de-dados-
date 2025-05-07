#include <iostream> //cin cout
#include <locale.h> //teclado em português
#include <stdlib.h>
#include <string.h>

// Este é um exemplo de programa em C++

using namespace std;

int *Ptr, Valor;
int main () {   
    setlocale (LC_ALL,"Portuguese");
    Valor = 27;
    
    Ptr = &Valor;
    
    cout << "Utilizando ponteiro:\n\n";
    cout << "\nConteúdo da variável Valor: " << Valor;
    cout << "\nEndereço da variável Valor: " << &Valor;
    cout << "\nConteúdo da variável ponteiro ptr:" << Ptr;
    cout << "\nConteúdo da variável apontada pelo ponteiro ptr:" << *Ptr;
    
       
    return 0;
}