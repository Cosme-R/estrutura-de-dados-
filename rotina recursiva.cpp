#include <iostream>
using namespace std;

int soma(int num)
{
    if(num==1)
        return 1;
    else
        return num+soma(num-1);
}

int main()
{
    int num;

    cout<<"Somat�rio de: ";
    cin>> num;

    cout<<"Igual a: "<<soma(num)<<endl;
}
