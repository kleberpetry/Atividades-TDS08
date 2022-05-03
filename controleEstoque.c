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
struct produto abc;
int sequencia=0,nvenda=0;
double vendas[200];

cadastrarProduto(){
	int ok;
	char nome[10]={'0'};
	system("cls");
	printf("\nDigite o nome do produto ou aperte 0 para retornar: ");
	fflush(stdin);
	gets(produtos[sequencia].nome);
	ok=strcmp(produtos[sequencia].nome,nome);
	if(ok!=0){
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
	}else{
		printf("\nVoltando para o menu!");
		system("pause");
		return;
	}
	system("pause");	
}
entradaEstoque(){
	int codigo,x,entrada=0,achou=0;
	system("cls");
	printf("\nDigite o código do produto ou 0 para retornar: ");
	scanf("%d",&codigo);
	if(codigo!=0){
		for(x=0;x<sequencia;x++){
			if(produtos[x].codigo==codigo){
				printf("\nEstoque atual do produto: %d",produtos[x].estoque);
				printf("\nDigite a quantidade de entrada em estoque: ");
				scanf("%d",&entrada);
				produtos[x].estoque+=entrada;
				printf("\nNovo estoque atualizado : %d\n",produtos[x].estoque);
				achou=1;
				break;
			}else{
				achou=0;
			}
		}
	}else{
		printf("\nRetornando ao Menu!\n");
		achou=1;
		system("pause");
		return;
	}
	if(achou==0){
		printf("\nProduto não encontrado\n");
		
	}
	system("pause");
}
listaTodos(){
	int x;
	system("cls");
	if(produtos[0].codigo>0){
		for(x=0;x<sequencia;x++){
			printf("\n---------------------------\n");
			printf("\nCódigo: %d",produtos[x].codigo);
			printf("\nNome: %s",produtos[x].nome);
			printf("\nValor: %0.2lf",produtos[x].valor);
			printf("\nEstoque: %d\n",produtos[x].estoque);	
		}
	}else{
		printf("\nNão há produtos cadastrados!\n");
	}
	system("pause");
}
ajusteCadastro(){
	int codigo,x,achou=0;
	double valor;
	char nome[50];
	system("cls");
	printf("\nDigite o código do produto ou 0 para retornar: ");
	scanf("%d",&codigo);
	if(codigo!=0){
		for(x=0;x<sequencia;x++){
			if(produtos[x].codigo==codigo){
				printf("\nNome: %s",produtos[x].nome);
				printf("\nValor: %0.2lf",produtos[x].valor);
				printf("\nDigite o novo nome: ");
				fflush(stdin);
				gets(produtos[x].nome);
				printf("\nDigite o novo valor: ");
				scanf("%lf",&produtos[x].valor);
				printf("\nCadastro atualizado com sucesso\n");
				achou=1;
				break;
			}else{
				achou=0;
			}
		}
	}else{
		printf("\nRetornando ao Menu!\n");
		achou=1;
		system("pause");
		return;
	}
	if(achou==0){
		printf("\nProduto não encontrado\n");
	}
	system("pause");
	
}
venda(){
	int codigo, x,continuar,qtde,achou=0;
	double subtotal=0,total=0;
	do{
		subtotal=0;
		system("cls");
		printf("\nDigite o código do produto ou 0 para retornar: ");
		scanf("%d",&codigo);
		if(codigo!=0){
			for(x=0;x<sequencia;x++){
				if(produtos[x].codigo==codigo){
					printf("\nProduto: %s",produtos[x].nome);
					printf("\nDigite a quantidade do produto: ");
					scanf("%d",&qtde);
					if(produtos[x].estoque>0 && produtos[x].estoque>=qtde){
						subtotal=qtde*produtos[x].valor;
						produtos[x].estoque-=qtde;
						printf("\nSubtotal da venda: %0.2lf",subtotal);
						printf("\nDeseja lançar mais um produto? ");
						printf("\nDigite 1 para sim | 2 para não :");
						scanf("%d",&continuar);
						achou=1;
						break;
					}else{
						printf("\nEstoque atual: %d",produtos[x].estoque);
						printf("\nProduto sem estoque para venda\n");
						system("pause");
						break;
					}
				}else{
					achou=0;
				}
			}
		}else{
			printf("\nRetornando ao Menu!\n");
			achou=1;
			system("pause");
			return;
		}
		if(achou==0){
			printf("\nproduto não encontrado\n");
			system("pause");
		}
		total+=subtotal;
	}while(continuar!=2);
	printf("\nO valor total da venda e: %0.2lf",total);
	printf("\nForma de pagamento: ");
	printf("\n1-à vista 2-prazo");
	printf("\nOpção: ");
	int op;
	scanf("%d",&op);
	if(op==2){
		total=total*1.03;
		printf("\nValor a pagar : %0.2lf\n",total);
	}else{
		printf("\nValor a pagar : %0.2lf\n",total);
	}
	vendas[nvenda]=total;
	nvenda++;
	system("pause");
}
listaVendas(){
	int x;
	system("cls");
	if(vendas[0]>0){
		for(x=0;x<nvenda;x++){
			printf("\n---------------------------\n");
			printf("\nVenda %d: %0.2lf\n",x+1,vendas[x]);	
		}
	}else{
		printf("\nNão há vendas realizadas!\n");
	}
	system("pause");
}
menu(){
		system("cls");
		printf("\nDigite a opção desejada: ");
		printf("\n1 - cadastro do produto.");
		printf("\n2 - entrada de estoque.");
		printf("\n3 - ajuste do cadastro.");
		printf("\n4 - lista todos os cadastros");
		printf("\n5 - Venda");
		printf("\n6 - Relatório de Vendas");
		printf("\nOpção: ");
}
main(){
	setlocale(LC_ALL, "Portuguese");
	int opcao;
	do{
		menu();
		scanf("%d",&opcao);
		switch(opcao){
			case 1:
				cadastrarProduto();
			break;
			case 2:
				entradaEstoque();
			break;
			case 3:
				ajusteCadastro();
			break;
			case 4:
				listaTodos();
			break;
			case 5:
				venda();
			break;
			case 6:
				listaVendas();
			break;
			case 0:
				printf("\nSaindo da aplicação\n");
			break;
			default:
				printf("\nOpção inválida!\n");
				system("pause");
		}
	}while(opcao!=0);
	
	return 0;
}






