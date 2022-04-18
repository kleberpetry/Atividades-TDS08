#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<stdbool.h>
struct projeto{
	int codido;
	char titulo[50];
	char descricao[100];
	int ano;
	int status;
	char resposavel[50];
};
struct projeto projetos[200];
const int a=1,f=2,c=3;
int sequencia=0;

cadastrarProjeto(){
	char continuar;
	bool cadastro=true;
	do{
		system("cls");
		projetos[sequencia].codido=sequencia+1;
		printf("\nDigite o titulo do projeto: ");
		fflush(stdin);
		gets(projetos[sequencia].titulo);
		printf("\nDigite a descri��o do projeto: ");
		fflush(stdin);
		gets(projetos[sequencia].descricao);
		printf("\nDigite o ano do projeto: ");
		scanf("%d",&projetos[sequencia].ano);
		printf("\nDigite o status do projeto: ");
		scanf("%d",&projetos[sequencia].status);
		printf("\nDigite o respons�vel: ");
		fflush(stdin);
		gets(projetos[sequencia].resposavel);
		printf("\nProjeto cadastrado com sucesso! c�digo gerado %d",projetos[sequencia].codido);
		printf("\nDeseja cadastrar um novo projeto? S-sim N-n�o ");
		fflush(stdin);
		scanf("%c",&continuar);
		if(continuar=='n'||continuar=='N'){
			cadastro=false;
		}
		sequencia++;
		
	}while(cadastro!=false);
	
}
todosProjetos(){
	system("cls");
	int x;
	if(projetos[0].codido>0){
		for(x=0;x<sequencia;x++){
			printf("\nC�digo: %d",projetos[x].codido);
			printf("\nTitulo: %s",projetos[x].titulo);
			printf("\nDescri��o: %s",projetos[x].descricao);
			printf("\nAno: %d",projetos[x].ano);
			switch(projetos[x].status){
				case 1:
					printf("\nStatus: A fazer");
				break;
				case 2:
					printf("\nStatus: Fazendo");
				break;
				case 3:
					printf("\nStatus: Conclu�do");
				break;
				default:
					printf("\nSem status definido");
			}
			printf("\nRespons�vel: %s\n",projetos[x].resposavel);
		}
	}else{
		printf("\nNenhum projeto cadastrado\n");
	}
	system("pause");
}
porStatus(int status){
	system("cls");
	int x,achou=0;
	for(x=0;x<sequencia;x++){
		if(projetos[x].status==status){
			printf("\nC�digo: %d",projetos[x].codido);
			printf("\nTitulo: %s",projetos[x].titulo);
			printf("\nDescri��o: %s",projetos[x].descricao);
			printf("\nAno: %d",projetos[x].ano);
			switch(projetos[x].status){
				case 1:
					printf("\nStatus: A fazer");
				break;
				case 2:
					printf("\nStatus: Fazendo");
				break;
				case 3:
					printf("\nStatus: Conclu�do");
				break;
				default:
					printf("\nSem status definido");
			}
			printf("\nRespons�vel: %s\n",projetos[x].resposavel);
			achou=1;
		}else{
			achou=0;
		}	
	}
	if(achou==0){
		printf("\nNenhum projeto encontrado\n");
	}
	system("pause");
}
buscaCodigo(int codigo){
	system("cls");
	int x,achou=0;
	for(x=0;x<sequencia;x++){
		if(projetos[x].codido==codigo){
			printf("\nC�digo: %d",projetos[x].codido);
			printf("\nTitulo: %s",projetos[x].titulo);
			printf("\nDescri��o: %s",projetos[x].descricao);
			printf("\nAno: %d",projetos[x].ano);
			switch(projetos[x].status){
				case 1:
					printf("\nStatus: A fazer");
				break;
				case 2:
					printf("\nStatus: Fazendo");
				break;
				case 3:
					printf("\nStatus: Conclu�do");
				break;
				default:
					printf("\nSem status definido");
			}
			printf("\nRespons�vel: %s\n",projetos[x].resposavel);
			achou=1;
			break;
		}else{
			achou=0;
		}
	}
	if(achou!=1){
		printf("\nProjeto n�o encontrado\n");
	}
	system("pause");
}
main(){
	setlocale(LC_ALL, "Portuguese");
	int op,codigo;
	do{
		system("cls");
		printf("\nDigite \n1 para cadastrar\n2 para imprimir todos os projetos\n3 para imprimir todos os projetos com status A FAZER\n4 para imprimir todos os projetos com status FAZENDO\n5 para imrprimir todos os projetos com status CONCLU�DO\n6 busca por c�digo");
		printf("\n_______________________________________________");
		printf("\nDigite a op��o desejada: ");
		scanf("%d",&op);
		switch(op){
			case 1:
				cadastrarProjeto();
			break;
			case 2:
				todosProjetos();
			break;
			case 3:
				porStatus(a);
			break;
			case 4:
				porStatus(f);
			break;
			case 5:
				porStatus(c);
			break;
			case 6:
				system("cls");
				printf("\nDigite o c�digo a ser buscado: ");
				scanf("%d",&codigo);
				buscaCodigo(codigo);
			break;
			default:
				printf("\nOp��o inv�lida");
		}
	}while(op!=0);
}





