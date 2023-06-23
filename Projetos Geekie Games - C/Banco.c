#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>


typedef struct{
	int codigo;
	char nome[50];
	char email[50];
	char cpf[20];
	char dataNascimento[20];
	char dataCadastro[20];
}Cliente;

typedef struct{
	int numero;
	Cliente cliente;
	float saldo;
	float limite;
	float saldoTotal; //saldo + limite
}Conta;


void menu();
void infoCliente(Cliente cliente);
void infoConta(Conta conta);
void criarConta();
void efetuarSaque();
void efetuarDeposito();
void efetuarTransferencia();
void listarContas();
float atualizarSaldoTotal(Conta conta);
Conta buscarContaPorNumero(int numero);
void sacar(Conta conta, float valor);
void transferir(Conta conta_origem, Conta conta_destino, float valor);

static Conta contas[50];
static int contador_contas = 0;
static int contador_clientes = 0;

int main(){
	menu();

	return 0;
}

void menu(){
	int opcao = 0;
	printf("=====================================");
	printf("============ ATM ====================");
	printf("============== Geek Bank ============");
	printf("=====================================");

	printf("Selecione uma opção no menu");
	printf("1 - Criar conta\n2 - Efetuar saque\n3 - Efetuar depósito\n 4 - Efetuar trasnferência\n "
			"5 - Listar contas\n 6 - Sair do sistema");

	scanf("%i", &opcao);
	getchar();

	switch(opcao){
		case 1:
			criarConta();
			break;
		case 2:
			efetuarSaque();
			break;
		case 3:
			efetuarDeposito();
			break;
		case 4:
			efetuarTransferencia();
			break;
		case 5:
			listarContas();
			break;
		case 6:
			printf("Até a próxima\n");
			Sleep(2);
			exit(0);
		default:
			printf("Opção inválida\n");
			Sleep(2);
			menu();
	}

}


void infoCliente(Cliente cliente){
	printf("Código: %i \nNome: %s\n Data de Nascimento: %s \nCadastro: %s\n", cliente.codigo,
			strtok(cliente.nome, "\n"), strtok(cliente.dataNascimento, "\n"), strtok(cliente.dataCadastro, "\n"));


}

void infoConta(Conta conta){
	printf("Número da conta: %i \nCliente: %s \nData Nascimento: %s \nSaldo Total: %.2f\n",
			conta.numero, strtok(conta.cliente.nome, "\n"), strtok(conta.cliente.dataNascimento, "\n"),
			conta.saldoTotal);

}

void criarConta(){
	Cliente cliente;

	char dia[3], mes[3], ano[5], data_cadastro[20];

	time_t t = time(NULL);

	struct tm tm = *localtime(&t);


	//dia
	if(tm.tm_mday < 10){
		sprintf(dia, "0%i", tm.tm_mday);
	}
	else{
		sprintf(dia, "%i", tm.tm_mday);
	}

	//mes
	if((tm.tm_mon + 1) < 10){
		sprintf(mes, "0%i", tm.tm_mon + 1);
	}
	else{
		sprintf(mes, "%i", tm.tm_mon + 1);
	}

	//ano
	sprintf(ano, "%i", tm.tm_year + 1900); //o tm_year devolve o ano atual - 1900, por isso a soma!

	strcpy(data_cadastro, "");
	strcat(data_cadastro, dia);
	strcat(data_cadastro, "/");
	strcat(data_cadastro, mes);
	strcat(data_cadastro, "/");
	strcat(data_cadastro, ano);
	strcat(data_cadastro, "\0");
	strcpy(cliente.dataCadastro, data_cadastro);

	//Criar cliente
	printf("Informe os dados do cliente: \n");
	cliente.codigo = contador_clientes + 1;

	printf("Nome do cliente: \n");
	fgets(cliente.nome, 50, stdin);

	printf("Email do cliente: \n");
	fgets(cliente.email, 50, stdin);

	printf("CPF do cliente: \n");
	fgets(cliente.cpf, 20, stdin);

	printf("Data de nascimento do cliente: \n");
	fgets(cliente.dataNascimento, 20, stdin);

	contador_clientes++;

	//Cria conta
	contas[contador_contas].numero = contador_contas + 1;
	contas[contador_contas].cliente = cliente;
	contas[contador_contas].saldo = 0.0;
	contas[contador_contas].limite = 0.0;
	contas[contador_contas].saldoTotal = atualizarSaldoTotal(contas[contador_contas]);

	printf("Conta criada com sucesso!\n");
	printf("\n");
	printf("Dados da conta criada: \n");
	printf("\n");
	infoConta(contas[contador_contas]);
	contador_contas++;

	Sleep(4);
	menu();
}


float atualizarSaldoTotal(Conta conta){

	return conta.saldo + conta.limite;
}

Conta buscarContaPorNumero(int numero){
	Conta c;
	if(contador_contas > 0){
		for(int i = 0; i < contador_contas; i++){
			if(contas[i].numero == numero){
				c = contas[i];
			}
		}
	}

	return c;
}

void sacar(Conta conta, float valor){
	if(valor > 0 && conta.saldoTotal >= valor){
		for(int i = 0; i < contador_contas; i++){
			if(contas[i].numero == conta.numero){
				if(contas[i].saldo >= valor){
					contas[i].saldo = contas[i].saldo - valor;
					contas[i].saldoTotal = atualizarSaldoTotal(contas[i]);
					printf("Saque efetuado com sucesso\n");
				}
				else{
					float restante = contas[i].saldo - valor;
					contas[i].limite = contas[i].limite + restante;
					contas[i].saldo = 0.0;
					contas[i].saldoTotal = atualizarSaldoTotal(contas[i]);
					printf("Saque efetuado com sucesso\n");
				}
			}
		}
	}
	else{
		printf("Saque não realizado. Tente novamente!");
	}

}

void depositar(Conta conta, float valor){
	if(valor > 0){
		for(int i = 0; i < contador_contas; i++){
			if(contas[i].numero == 	conta.numero){
				contas[i].saldo = contas[i].saldo + valor;
				contas[i].saldoTotal =  atualizarSaldoTotal(contas[i]);
				printf("Depósito efetuado com sucesso!\n");
			}
		}
	}
	else{
		printf("Erro ao efetuar depósito. Tente novamente!\n");
	}

}


void transferir(Conta conta_origem, Conta conta_destino, float valor){
	if(valor > 0 && conta_origem.saldoTotal >= valor){
		for(int co = 0; co < contador_contas; co++){
			if(contas[co].numero == conta_origem.numero){
				for(int cd = 0; cd < contador_contas; cd++){
					if(contas[cd].numero == conta_destino.numero){
						if(contas[co].saldo >= valor){
							contas[co].saldo = contas[co].saldo - valor;
							contas[cd].saldo = contas[cd].saldo + valor;
							contas[co].saldoTotal = atualizarSaldoTotal(contas[co]);
							contas[cd].saldoTotal = atualizarSaldoTotal(contas[cd]);
							printf("Trasnferência realizada com sucesso!\n");
						}
						else{
							float restante = contas[co].saldo - valor;
							contas[co].limite = contas[co].limite + restante;
							contas[co].saldo = 0.0;
							contas[cd].saldo = contas[cd].saldo + valor;
							contas[co].saldoTotal = atualizarSaldoTotal(contas[co]);
							contas[cd].saldoTotal = atualizarSaldoTotal(contas[cd]);
							printf("Trasnferência realizada com sucesso!\n");
						}
					}
				}
			}
		}
	}
	else{
		printf("Transferência não realizada, tente novamente!\n");
	}


}

void efetuarSaque(){
	if(contador_contas > 0){
		int numero;
		printf("Informe o número da conta: \n");
		scanf("%i", &numero);

		Conta conta = buscarContaPorNumero(numero);

		if(conta.numero == numero){
			float valor;
			printf("Informe o valor do saque: \n");
			scanf("%f", &valor);

			sacar(conta, valor);
		}
		else{
			printf("Não foi encontrada uma conta com o número %i\n", numero	);
		}
	}
	else{
		printf("Ainda não existem contas para saque!\n");
	}

	Sleep(2);
	menu();

}


void efetuarDeposito(){
	if(contador_contas > 0){
			int numero;
			printf("Informe o número da conta: \n");
			scanf("%i", &numero);

			Conta conta = buscarContaPorNumero(numero);

			if(conta.numero == numero){
				float valor;
				printf("Informe o valor do depósito: \n");
				scanf("%f", &valor);

				depositar(conta, valor);
			}
			else{
				printf("Não foi encontrada uma conta com o número %i\n", numero	);
			}
	}
	else{
		printf("Ainda não existem contas para depósito!\n");
	}

	Sleep(2);
	menu();

}

void efetuarTransferencia(){
	if(contador_contas > 0){
		int numero_o, numero_d;
		printf("Informe o número da sua conta: \n");
		scanf("%d", &numero_o);

		Conta conta_o = buscarContaPorNumero(numero_o);

		if(conta_o.numero == numero_o){
			printf("Informe o número da conta destino: \n");
			scanf("%i", &numero_d);

			Conta conta_d = buscarContaPorNumero(numero_d);

			if(conta_d.numero == numero_d){
				float valor;
				printf("Informe o valor para transferência: \n");
				scanf("%f", &valor);

				transferir(conta_o, conta_d, valor);
			}
			else{
				printf("A conta destino de número %i não foi encontrada!\n", numero_d);
			}
		}
		else{
			printf("A conta de origem de número %i não foi encontrada!\n", numero_o);
		}

	}
	else{
		printf("Ainda não existem contas para transferências!\n");
	}

	Sleep(2);
	menu();

}

void listarContas(){
	if(contador_contas > 0){
		for(int i = 0; i < contador_contas; i++){
			infoConta(contas[i]);
			printf("\n");
			Sleep(1);
		}
	}
	else{
		printf("Não existem contas cadastradas ainda.\n");
	}

	Sleep(2);
	menu();
}
