#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<stdbool.h>
struct projeto{
	int codido;
	char titulo[50];
	char descricao[50];
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
		printf("\nDigite a descrição do projeto: ");
		fflush(stdin);
		gets(projetos[sequencia].descricao);
		printf("\nDigite o ano do projeto: ");
		scanf("%d",&projetos[sequencia].ano);
		printf("\nDigite o status do projeto: ");
		scanf("%d",&projetos[sequencia].status);
		printf("\nDigite o responsável: ");
		fflush(stdin);
		gets(projetos[sequencia].resposavel);
		printf("\nProjeto cadastrado com sucesso! código gerado %d",projetos[sequencia].codido);
		printf("\nDeseja cadastrar um novo projeto? S-sim N-não ");
		fflush(stdin);
		scanf("%c",&continuar);
		if(continuar=='n'||continuar=='N'){
			cadastro=false;
		}
		sequencia++;
		
	}while(cadastro!=false);
	
}
todosProjetos(){
	


}
//porStatus(){}

main(){
	setlocale(LC_ALL, "Portuguese");
	int op;
	do{
		system("cls");
		printf("\nDigite \n1 para cadastrar\n2 para imprimir todos os projetos\n3 para imprimir todos os projetos com status A FAZER\n4 para imprimir todos os projetos com status FAZENDO\n5 para imrprimir todos os projetos com status CONCLUÍDO\n6 listagem a pensar");
		printf("\n_______________________________________________");
		printf("\nDigite a opção desejada: ");
		scanf("%d",&op);
		switch(op){
			case 1:
				cadastrarProjeto();
			break;
			case 2:
				//todosProjetos();
			break;
			case 3:
				//porStatus();
			break;
			case 4:
				//porStatus();
			break;
			case 5:
				//porStatus();
			break;
			case 6:
				//a pensar;
			break;
			default:
				printf("\nOpção inválida");
		}
	}while(op!=0);
}





