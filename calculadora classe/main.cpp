#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
	double calculadora(double num1, double num2, int op);
main(){
	setlocale(LC_ALL, "Portuguese");
	double num1,num2,resultado;
	int operacao;
	do{
		system("cls");
		resultado=0;
		printf("\nDigite o primeiro numero: ");
		scanf("%lf",&num1);
		printf("\nDigite o segundo numero: ");
		scanf("%lf",&num2);
		printf("\nDigite a opera��o\n1-soma\n2-subtra��o\n3-divis�o\n4-multiplica��o\n");
		scanf("%d",&operacao);
		resultado=calculadora(num1,num2,operacao);
		printf("\nO resultado �: %0.2lf\n",resultado);
		system("pause");
	}while(operacao!=0);
	return 0;
}
