

double calculadora(double num1,double num2,int op){
	double resultado;
	switch(op){
		case 1:
			resultado=num1+num2;
		break;
		case 2:
			resultado=num1-num2;
		break;
		case 3:
			resultado=num1/num2;
		break;
		case 4:
			resultado=num1*num2;
		break;
		default:
			resultado=0;
	}
	return resultado;
}
