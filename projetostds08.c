#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
struct projeto{
	
};
struct projeto projetos[200];

cadastrarProjeto(){
	//identico ao da triagem;
}
//todosProjetos(){}
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
				//cadastrarProjeto();
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





