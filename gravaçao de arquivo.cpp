#include <iostream>
#include <string.h>

#define MAX 100

using namespace std;

// declara��o da struct pessoa
struct pessoa
{
	char nome[50];
	int idade;
};


// fun��o para escrever os elementos de uma struct no arquivo
void GravarArquivo(pessoa pessoas[], int TamVet)
{
	int Cont;
	FILE * arq;

	// abre o arquivo para escrita no modo append (adiciona ao final)
	arq = fopen("D:/vitor/dados.bin", "wb");

	if(arq != NULL)
	{		
		for(Cont = 0; Cont < TamVet; Cont++){
			// escreve cada elemento do vetor no arquivo
			fwrite(&pessoas[Cont], sizeof(pessoa), 1, arq);
		}
			
		fclose(arq); // fecha o arquivo
	}
	else
	{
		cout << "\nErro ao abrir o arquivo para leitura!\n";	
	}
}

// fun��o para ler do arquivo
// recebe o vetor que ela ir� preencher
// retorna a quantidade de elementos preenchidos
int LerArquivo(pessoa aux_pessoas[])
{
	int Cont = 0, Ret;
	pessoa p;
	FILE *arq;
	
	// abre o arquivo para leitura
	arq = fopen("D:/vitor/dados_alt.bin", "rb");

	if(arq != NULL)
	{		
		while(fread(&aux_pessoas[Cont], sizeof(pessoa), 1, arq) == 1) //Leitura foi OK!!!
		{
			//aux_pessoas[Cont] = p;
			Cont++;
		}
		fclose(arq); // fecha o arquivo
	}
	else
	{
		printf("\nErro ao abrir o arquivo para leitura!\n");
	}
	
	return Cont;
}

void MostrarArquivo(pessoa pessoas[], int TamVet){
	int Cont;
	
	// mostrando os elementos do vetor 
	for(Cont = 0; Cont < TamVet; Cont++)
	{
		cout << "Nome: "<< pessoas[Cont].nome << endl;
		cout << "Idade: "<< pessoas[Cont].idade << endl << endl;
	}
}

// vetor que ser� escrito no arquivo
pessoa ListaPessoas[] = {{"pedro", 20}, {"maria", 30}, {"catarina", 2}};
// vetor para onde ser�o carregados os dados
// esse vetor foi criado para demonstrar que realmente funciona,
// mas basta utilizar somente um vetor
pessoa ListaAux[MAX];
int TamVet, Cont;
int main()
{
	setlocale (LC_ALL,"Portuguese");

	TamVet =  sizeof(ListaPessoas)/sizeof(ListaPessoas[0]);		

	//GravarArquivo(ListaPessoas, TamVet);
	TamVet = LerArquivo(ListaAux);
	MostrarArquivo(ListaAux, TamVet);	
	

	return 0;
}
