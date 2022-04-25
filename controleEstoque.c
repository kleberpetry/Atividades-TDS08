#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
struct produto{
	int codigo;
	char nome[50];
	double valor;
	int estoque;
};
struct produto produtos[200];
int sequencia=0;

cadastrarProduto(){
	system("cls");
	printf("\nDigite o nome do produto: ");
	fflush(stdin);
	gets(produtos[sequencia].nome);
	printf("\nDigite o valor do produto: ");
	scanf("%lf",&produtos[sequencia].valor);
	printf("\nDigite a quantidade em estoque: ");
	scanf("%d",&produtos[sequencia].estoque);
	printf("\nCadastro realizado com sucesso!\n");
	system("pause");
	system("cls");
	printf("\nDados do produtos cadastrado: ");
	produtos[sequencia].codigo=sequencia+1;
	printf("\nCódigo: %d",produtos[sequencia].codigo);
	printf("\nNome: %s",produtos[sequencia].nome);
	printf("\nValor: %0.2lf",produtos[sequencia].valor);
	printf("\nEstoque: %d\n",produtos[sequencia].estoque);
	sequencia++;
	system("pause");	
}


main(){
	setlocale(LC_ALL, "Portuguese");
	int opcao;
	do{
		system("cls");
		printf("\nDigite a opção desejada: ");
		printf("\n1 - cadastro do produto.");
		printf("\n2 - entrada de estoque.");
		printf("\n3 - ajuste de produto.");
		printf("\n4 - lista todos os cadastros");
		printf("\nOpção: ");
		scanf("%d",&opcao);
		switch(opcao){
			case 1:
				cadastrarProduto();
			break;
			case 2:
			break;
			case 3:
			break;
			case 4:
			break;
			default:
				printf("\nOpção inválida!\n");
				system("pause");
		}
	}while(opcao!=0);
	
	
	
	
	
	
	return 0;
}






