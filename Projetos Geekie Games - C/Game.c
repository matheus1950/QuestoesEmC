#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct{
	int dificuldade;
	int valor1;
	int valor2;
	int operacao;
	int resultado;
} Calcular;

void jogar();
void mostrarInfo(Calcular calc);
int operacao(int resposta, Calcular calc);

int pontos = 0;

int main(){

	srand(time(NULL));

	printf("Inicio do jogo!\n");

	jogar();

	return 0;
}


void jogar(){
	Calcular calc;

	printf("Digite o nível de dificuldade desejado(1, 2, 3 ou 4)\n");
	fflush(stdout);
	scanf("%i", &calc.dificuldade);

	//gera um valor inteiro randômico entre 0 e 2;
	calc.operacao = rand() % 3;

	if(calc.dificuldade == 1){
		calc.valor1 = rand() % 11; //0 a 10
		calc.valor2 = rand() % 11;
	}

	else if(calc.dificuldade == 2){
		calc.valor1 = rand() % 101; //0 a 100
		calc.valor2 = rand() % 101;
;	}
	else if(calc.dificuldade == 3){
		calc.valor1 = rand() % 1001; //0 a 1000
		calc.valor2 = rand() % 1001;
	}
	else if(calc.dificuldade == 4){
		calc.valor1 = rand() % 10001; //0 a 10000
		calc.valor2 = rand() % 10001;
	}
	else{ //dificuldade secreta - ultra
		calc.valor1 = rand() % 100001;
		calc.valor2 = rand() % 100001;
	}

	int resposta;

	printf("Informe o resultado para a seguinte operação:\n");

	if(calc.operacao == 0){
		printf("%i + %i\n", calc.valor1, calc.valor2);
		fflush(stdout);
		scanf("%i", &resposta);
	}
	else if(calc.operacao == 1){
		printf("%i - %i\n", calc.valor1, calc.valor2);
		fflush(stdout);
		scanf("%i", &resposta);
	}
	else if(calc.operacao == 2){
		printf("%i * %i\n", calc.valor1, calc.valor2);
		fflush(stdout);
		scanf("%i", &resposta);
	}
	else{
		printf("A operação não existe!\n");
	}

	mostrarInfo(calc);

	if(operacao(resposta, calc)){
		pontos += 1;
	}

	printf("Você tem %i pontos\n", pontos);

	//Deseja continuar??
	printf("Deseja continuar jogando? 1 - Sim / 0 - Não \n");
	int continuar;

	fflush(stdout);

	do{
		scanf("%i", &continuar);

		if(continuar == 1){
			jogar();
		}
		else if(continuar == 0){
			printf("Você finalizou  com %i ponto(s).\n", pontos);
		}
		else{
			printf("Digito não correspondente às opções. Por favor, redigite dentre as opções seguintes --> (1 - Sim / 0 - Não):\n");
		}
	}while(continuar != 0 && continuar != 1);
}

void mostrarInfo(Calcular calc){
	char op[25];

	if(calc.operacao == 0){
		sprintf(op, "Somar");
	}
	else if(calc.operacao == 1){
		sprintf(op, "Diminuir");
	}
	else if(calc.operacao == 2){
		sprintf(op, "Multiplicar");
	}
	else{
		sprintf(op, "Operação desconhecida");
	}

	printf("Valor 1: %d\nValor 2: %d \nDificuldade: %d \nOperação: %s\n", calc.valor1, calc.valor2, calc.dificuldade, op);
}


int operacao(int resposta, Calcular calc){

	if(calc.operacao == 0){
		calc.resultado = calc.valor1 + calc.valor2;
	}

	else if(calc.operacao == 1){
		calc.resultado = calc.valor1 - calc.valor2;
	}

	else if(calc.operacao == 2){
		calc.resultado = calc.valor1 * calc.valor2;
	}

	int certo = 0; // 0 é erro e 1 é acerto!

	if(resposta == calc.resultado){
		printf("Resposta correta!\n");
		certo = 1;
	}
	else{
		printf("Resposta errada!\n");
	}

	//impressão!

	if(calc.operacao == 0){
		printf("%i + %i = %i\n", calc.valor1, calc.valor2, calc.resultado);
	}

	else if(calc.operacao == 1){
		printf("%i - %i = %i\n", calc.valor1, calc.valor2, calc.resultado);
	}

	else if(calc.operacao == 2){
		printf("%i * %i = %i\n", calc.valor1, calc.valor2, calc.resultado);
	}

	return certo;
}



