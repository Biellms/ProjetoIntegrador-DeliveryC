#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#define TAM 15 //TAMANHO DO ESTOQUE

HANDLE saida;
COORD posicao;
COORD posicao2;
COORD posicao3;
COORD posicao4;

/////////////////////////// LOGIN E CADASTRO ///////////////////////////////////
typedef struct{
	int codigo;
	char nome[100];
	float preco;
}Produto;

Produto produto[TAM];

//FUNÇÕES//
void menuPrincipal();
void cadastroCliente();
void cadastroComercio();
void loginCliente();
void loginComercio();
void menuCadastro();
void menuComercio(Produto *produto);
void menuCliente(Produto *produto);
void alterarProdutos(Produto *produto);
void exibirProdutos(Produto *produto);
void procurarProdutos(Produto *produto);
void cadastrarProdutos(Produto *produto);
void Comprar(Produto *produto);

//variaveis globais//
int op;
//cliente
char nomeCliente[50];
char emailCliente[50];
char telefoneCliente[15];
char usuCliente[50];
char senhaCliente[50];
char endCliente[60];
char CPF[50];
//comercio
char nomeComercio[50];
char emailComercio[50];
char telefoneComercio[15];
char usuComercio[50];
char senhaComercio[50];
char endComercio[60];
char CNPJ[50];

//Estoque
int nCDTS = 0, printar = 0;

int main (){

	system("cls");Sleep(808);
	printf("\n\n\t\t=========================================================");Sleep(808);
	printf("\n\t\t===================== DELIVERY-C ========================");Sleep(808);
	printf("\n\t\t=========================================================\n");Sleep(808);
	printf("\n\t\t=========================================================");Sleep(808);
	printf("\n\t\t>> PROGRAMA COM ALGUMAS CARACTERISTICAS DE UM DELIVERY <<");Sleep(808);
	printf("\n\t\t>> CADASTRE SEU COMERCIO E FACA PEDIDOS, DEVIRTA-SE !! <<");Sleep(808);
	printf("\n\t\t=========================================================\n\n\n\n\t\t");Sleep(1500);
	system("pause");
		
	menuPrincipal();

}

void menuPrincipal () {

	saida = GetStdHandle(STD_OUTPUT_HANDLE);
	posicao = {30,4};
	posicao2 = {15,4};
	system("color F0");
	system("cls");
	printf("---------------------------------------------------------\n");
	printf("----------------------- DELIVERY-C ----------------------\n");
	printf("---------------------------------------------------------\n");
	printf("\n QUAL OPCAO DESEJA ACESSAR? [   ]\n");
	printf("\n 1)LOGIN\n 2)CADASTRAR\n 3)INFORMACOES DO SISTEMA\n 4)SAIR ");
	SetConsoleCursorPosition(saida,posicao);
	scanf("%d", &op);

		switch (op){
			case 1:
					system("cls");
					printf("---------------------------------------------------------\n");
					printf("------------------------ LOGIN --------------------------\n");
					printf("---------------------------------------------------------\n");
					printf("\n LOGAR COMO: [   ]\n");
					printf("\n 1)CLIENTE\n 2)COMERCIO\n 3)SAIR");
					SetConsoleCursorPosition(saida,posicao2);
					scanf("%d", &op);
					if(op == 1) { loginCliente(); } else if(op ==2) { loginComercio(); } else { menuPrincipal(); }
				break; 
			case 2: menuCadastro(); break; 
			case 3:
					system("cls");
					printf("=====================================");
					printf("\n\n DELIVERY-C");
					printf("\n\n CRIADOR: Gabriel Mendes");
					printf("\n CONTATO: biell.mendes8@gmail.com");
					printf("\n\n COPYRIGHT@2021\n\n");
					printf("=====================================\n\n ");
					system("pause");
					menuPrincipal();
				break;
			case 4: system("exit"); break; default: menuPrincipal(); break;
		}
}

void menuCadastro(){
	
	saida = GetStdHandle(STD_OUTPUT_HANDLE);
	posicao = {26,4};
	system("cls");
	printf("---------------------------------------------------------\n");
	printf("----------------------- CADASTRO ------------------------\n");
	printf("---------------------------------------------------------\n");
	printf("\n DESEJA CADASTRAR COMO: [   ]\n");
	printf("\n 1)CLIENTE\n 2)COMERCIO\n 3)SAIR\n");
	SetConsoleCursorPosition(saida,posicao);
	scanf("%d", &op);	
		switch (op){
			case 1: cadastroCliente(); break; 
			case 2: cadastroComercio(); break; 
			case 3: menuPrincipal(); break; 		
		}
}

void cadastroCliente(){

	system("cls");
		printf("---------------------------------------------------------\n");
		printf("------------------- CADASTRO CLIENTE --------------------\n");
		printf("---------------------------------------------------------\n\n");
		printf(" NOME: ");
		fflush(stdin);
		scanf("%[^\n]s", &nomeCliente);
		printf("---------------------------------------------------------\n");
		printf(" EMAIL: ");
		scanf("%s", &emailCliente);
		printf("---------------------------------------------------------\n");
		printf(" TELEFONE: ");
		fflush(stdin);
		scanf("%[^\n]s", &telefoneCliente);
		printf("---------------------------------------------------------\n");
		printf(" USUARIO: ");
		scanf("%s", &usuCliente);
		printf("---------------------------------------------------------\n");
		printf(" SENHA: ");
		scanf("%s", &senhaCliente);
		printf("---------------------------------------------------------\n");
		printf(" ENDERECO: ");
		fflush(stdin);
		scanf("%[^\n]s", &endCliente);
		printf("---------------------------------------------------------\n");
		printf(" CPF: ");
		scanf("%s", &CPF);
		printf("\n=========================================================================\n");
		printf(" USUARIO CADASTRADO COM SUCESSO, VOCE SERA REDIRECIONADO PARA O LOGIN!\n");
		printf("=========================================================================\n\n ");
	system("pause");
	loginCliente();
}

void cadastroComercio(){
	
	system("cls");
		printf("---------------------------------------------------------\n");
		printf("------------------ CADASTRO COMERCIO --------------------\n");
		printf("---------------------------------------------------------\n\n");
		printf(" NOME DO COMERCIO: ");
		fflush(stdin);
		scanf("%[^\n]s", &nomeComercio);
		printf("---------------------------------------------------------\n");
		printf(" EMAIL: ");
		scanf("%s", &emailComercio);
		printf("---------------------------------------------------------\n");
		printf(" TELEFONE: ");
		fflush(stdin);
		scanf("%[^\n]s", &telefoneComercio);
		printf("---------------------------------------------------------\n");
		printf(" USUARIO: ");
		scanf("%s", &usuComercio);
		printf("---------------------------------------------------------\n");
		printf(" SENHA: ");
		scanf("%s", &senhaComercio);
		printf("---------------------------------------------------------\n");
		printf(" ENDERECO: ");
		fflush(stdin);
		scanf("%[^\n]s", &endComercio);
		printf("---------------------------------------------------------\n");
		printf(" CNPJ: ");
		scanf("%s", &CNPJ);
		printf("\n=========================================================================\n");
		printf(" COMERCIO CADASTRADO COM SUCESSO, VOCE SERA REDIRECIONADO PARA O LOGIN!\n");
		printf("=========================================================================\n\n ");
	system("pause");
	loginComercio();
}

void loginCliente() {

char usu1Cliente[50];
char senha1Cliente[50];

		system("cls");
		printf("---------------------------------------------------------\n");
		printf("-------------------- LOGIN CLIENTE ----------------------\n");
		printf("---------------------------------------------------------\n");
		printf("\n DIGITE O USUARIO CADASTRADO: ");
		scanf("%s", &usu1Cliente);
		printf("\n---------------------------------------------------------\n");
		printf("\n DIGITE A SENHA CADASTRADA: ");
		scanf("%s", &senha1Cliente);
		printf("\n---------------------------------------------------------\n");

		if (strcmp(usu1Cliente, usuCliente) == 0 && strcmp(senha1Cliente, senhaCliente) == 0) {
		system("cls");
        printf("\n\n LOGADO\n\n SEJA BEM VINDO, %s\n\n VOCE SERA REDIRECIONADO PARA O MENU!", usuCliente);
        printf("\n\n ");
		system("pause");
		menuCliente(produto); } 
		else {printf("\n DADOS INVALIDOS!!\n\n ");
			  system("pause");
		      loginCliente();
		}
}

void loginComercio(){

char usu1Comercio[50];
char senha1Comercio[50];
	
		system("cls");
		printf("---------------------------------------------------------\n");
		printf("------------------- LOGIN COMERCIO ----------------------\n");
		printf("---------------------------------------------------------\n");	
		printf("\n DIGITE O USUARIO CADASTRADO: ");
		scanf("%s", &usu1Comercio);
		printf("\n---------------------------------------------------------\n");
		printf("\n DIGITE A SENHA CADASTRADA: ");
		scanf("%s", &senha1Comercio);
		printf("\n---------------------------------------------------------\n");

		if (strcmp(usu1Comercio, usuComercio) == 0 && strcmp(senha1Comercio, senhaComercio) == 0){
		system("cls");
        printf("\n\n LOGADO\n\n SEJA BEM VINDO, %s\n\n VOCE SERA REDIRECIONADO PARA O MENU!", usuComercio);
        printf("\n\n ");       
        system("pause");
		menuComercio(produto); } 
		else {printf("\n DADOS INVALIDOS!!\n\n");
			  system("pause");
		      loginComercio();
		}	

}

void menuCliente(Produto *produto) {

int i;

	saida = GetStdHandle(STD_OUTPUT_HANDLE);
	posicao = {30,4};
	system("cls");
	printf("---------------------------------------------------------\n");
	printf("--------------------- MENU CLIENTE ----------------------\n");
	printf("---------------------------------------------------------\n");
	printf("\n QUAL OPCAO DESEJA ACESSAR? [   ]\n");
	printf("\n 1)COMPRAR");
	printf("\n 2)PROCURAR PRODUTOS");
	printf("\n 3)DADOS DO USUARIO");
	printf("\n 4)INFORMACOES DO SISTEMA");
	printf("\n 5)SAIR\n\n");
	SetConsoleCursorPosition(saida,posicao);
	scanf("%d", &op);
		switch (toupper(op)) {
		case 1: Comprar(produto); break;
		case 2: procurarProdutos(produto); break;
		case 3:
			system("cls");
				printf("=======================\n");
				printf(" DADOS DO CLIENTE\n");
				printf("=======================\n");
				printf("\n NOME: %s\n EMAIL: %s\n TELEFONE: %s\n USUARIO: %s\n SENHA: %s\n ENDERECO: %s\n CPF: %s\n\n ", nomeCliente, emailCliente, telefoneCliente, usuCliente, senhaCliente, endCliente, CPF);
                system("pause");
				menuCliente(produto);
			break;
		case 4:
			system("cls");
			printf("=====================================");
			printf("\n\n DELIVERY-C");
			printf("\n\n CRIADOR: Gabriel Mendes");
			printf("\n CONTATO: biell.mendes8@gmail.com");
			printf("\n\n COPYRIGHT@2021\n\n");
			printf("=====================================\n\n ");
			system("pause");
			menuCliente(produto);
			break;
		case 5: menuPrincipal(); break;
		default: printf(" OPCAO INVALIDA!!"); menuCliente(produto); break;
		}
}

void menuComercio(Produto *produto) {

int i;

	saida = GetStdHandle(STD_OUTPUT_HANDLE);
	posicao = {30,4};
	system("cls");
	printf("---------------------------------------------------------\n");
	printf("--------------------- MENU COMERCIO ---------------------\n");
	printf("---------------------------------------------------------\n");
	printf("\n QUAL OPCAO DESEJA ACESSAR? [   ]\n");
	printf("\n 1)CADASTRAR PRODUTO");
	printf("\n 2)EXIBIR PRODUTOS");
	printf("\n 3)ALTERAR PRODUTOS");
	printf("\n 4)DADOS DO COMERCIO");
	printf("\n 5)INFORMACOES DO SISTEMA");
	printf("\n 6)SAIR\n\n");
	SetConsoleCursorPosition(saida,posicao);
	scanf("%d", &op);
		switch(toupper(op)) { 
			case 1: cadastrarProdutos(produto); break;
			case 2: exibirProdutos(produto); break;
			case 3: alterarProdutos(produto); break;
			case 4:
				system("cls");
				printf("=======================\n");
				printf(" DADOS DO COMERCIO\n");
				printf("=======================\n");
				printf("\n NOME DO COMERCIO : %s\n EMAIL: %s\n TELEFONE: %s\n USUARIO: %s\n SENHA: %s\n ENDERECO: %s\n CNPJ: %s\n\n ", nomeComercio, emailComercio, telefoneComercio, usuComercio, senhaComercio, endComercio, CNPJ);
                system("pause");
				menuComercio(produto);
				break;
			case 5:
				system("cls");
				printf("=====================================");
				printf("\n\n DELIVERY-C");
				printf("\n\n CRIADOR: Gabriel Mendes");
				printf("\n CONTATO: biell.mendes8@gmail.com");
				printf("\n\n COPYRIGHT@2021\n\n");
				printf("=====================================\n\n ");
				system("pause");
				menuComercio(produto);
				break;
			case 6: menuPrincipal(); break;
			default: printf(" OPCAO INVALIDA!!"); menuComercio(produto); break;
		}
}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^ LOGIN E CADASTRO ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//

///////////////////////////// ESTOQUE E VENDA ////////////////////////////////////

void cadastrarProdutos(Produto *produto){

int resp=1, i=nCDTS;

	saida = GetStdHandle(STD_OUTPUT_HANDLE);
	posicao = {27,13};
	system("cls");
	printf("=======================\n");
	printf(" CADASTRAR PRODUTO\n");
	printf("=======================\n\n");
		for(i=nCDTS;i>=nCDTS && i<TAM;i++){
			fflush(stdin);
			printf(" NOME DO PRODUTO: ");
			gets(produto[i].nome);
			fflush(stdin);
			printf("\n CODIGO DO PRODUTO: ");
			scanf("%d", &produto[i].codigo);		
			printf("\n PRECO DO PRODUTO: ");
			scanf("%f", &produto[i].preco);						
			printar++;
			nCDTS++;
			printf("\n===================================\n");
			printf(" PRODUTO CADASTRADO COM SUCESSO!\n");
			printf("===================================\n");
			printf(" CADASTRAR NOVO PRODUTO? [   ]\n");
			printf(" 1)SIM\n 2)NAO\n");
			printf("===================================");
			SetConsoleCursorPosition(saida,posicao);
			scanf("%d", &resp);
			if(resp == 1){ cadastrarProdutos(produto); } else { menuComercio(produto); }
			break;	}
}

void exibirProdutos(Produto *produto){

int opExiPro, i;

	saida = GetStdHandle(STD_OUTPUT_HANDLE);
	posicao = {35,3};
	system("cls");
	printf("=====================================\n");
	printf(" PRODUTOS\n");
	printf("-------------------------------------\n");
	printf(" VOCE TEM %d PRODUTOS CADASTRADOS [   ]\n", nCDTS);
	printf("=====================================\n");
	printf(" PRODUTO   CODIGO    PRECO\n");
	for(i=0; i<printar ;i++){
			printf(" %s               ",produto[i].nome);
			printf(" %d     ", produto[i].codigo);
			printf(" %.2f          ", produto[i].preco);
			printf("\n");
			}

	printf("=====================================");
	printf("\n 1)ALTERAR DADOS DO PRODUTO\n 2)VOLTAR\n");
	printf("=====================================");
	SetConsoleCursorPosition(saida,posicao);
	scanf("%d", &opExiPro);
		switch(opExiPro){
			case 1: alterarProdutos(produto); break;
			case 2: menuComercio(produto); break;
			default: printf(" OPCAO INVALIDA, VOCE SERA REDIRECIONADO AO MENU! \n\n "); system("pause");
			menuComercio(produto); break;
			}
}

void alterarProdutos(Produto *produto){

int j, alterar, novoCod;
float novoPreco;
char nomeProduto[100];

	saida = GetStdHandle(STD_OUTPUT_HANDLE);
	posicao = {25,5};
	system("cls");	
	printf("================================================\n");
	printf(" ALTERAR PRODUTO\n");
	printf("================================================\n");
	printf(" DIGITE O NOME DO PRODUTO QUE DESEJA ALTERAR: ");
	scanf("%s", &nomeProduto);
		
		for(j=0; j<TAM; j++){
			if(strcmp(nomeProduto, produto[j].nome) == 0){
				printf("\n ALTERAR O PRODUTO %s: [   ]\n 1)ALTERAR PRECO\n 2)ALTERAR CODIGO\n", produto[j].nome);
				SetConsoleCursorPosition(saida,posicao);
				scanf("%d", &alterar);
				printf("\n\n\n");

				switch(alterar) {
					case 1:
					printf(" INFORME O NOVO PRECO DO PRODUTO: ");
					scanf("%f", &novoPreco);
					produto[j].preco = novoPreco;
					exibirProdutos(produto);
						break;				
					case 2:				
					printf(" INFORME O NOVO CODIGO DO PRODUTO: ");
					scanf("%d", &novoCod);
					produto[j].codigo = novoCod;
					exibirProdutos(produto);
						break;
					default:
					printf(" OPCAO INVALIDA!\n\n "); system("pause");
					alterarProdutos(produto);
						break;
				}
			} else { printf("\n PRODUTO NAO CADASTRADO!\n\n"); system("pause"); menuComercio(produto); } break;
		}
}

void procurarProdutos(Produto *produto) {

int opExiPro, i;

	system("cls");    
	printf("============================================\n");
	printf(" PRODUTOS DO COMERCIO '%s'\n", nomeComercio);
	printf("============================================\n\n");
	printf(" PRODUTO   CODIGO    PRECO\n\n");

	for(i=0; i<printar ;i++){
			printf(" %s               ",produto[i].nome);
			printf(" %d     ", produto[i].codigo);
			printf(" %.2f          ", produto[i].preco);
			printf("\n");
			}
	printf("\n ");
    system("pause");
	menuCliente(produto);
}

void Comprar(Produto *produto){

int codCompra, quantCompra, vazio, opCompra, statusProdCadastrado = 0;
float valorPago;
		
	saida = GetStdHandle(STD_OUTPUT_HANDLE);
	posicao = {21,4};
	posicao2 = {23,8};
	posicao3 = {23,8};
	posicao4 = {22,20};
	system("cls");
	printf("=========================================================\n");
	printf(" COMPRAR PRODUTO DO COMERCIO '%s'\n", nomeComercio);
	printf("=========================================================\n");
	printf(" INFORME O CODIGO DO PRODUTO: ");
	scanf("%d", &codCompra);
		
	for(int i=0;i<TAM; i++){
		if(codCompra == produto[i].codigo) {
			statusProdCadastrado = 1;
			printf("=======================\n");
			printf(" PRODUTO: %s \n PRECO: %.2f \n", produto[i].nome, produto[i].preco);
			printf("=======================\n");
			printf(" QUANTIDADE: ");
			scanf("%d", &quantCompra);
			printf("\n=======================\n");
			system("cls");
			float valorCompra = produto[i].preco*quantCompra;
			printf("\n=======================\n");
			printf(" VALOR DA COMPRA: %.2f \n", valorCompra);
			printf("=======================\n");
			printf(" PAGAR NA ENTREGA? [   ]\n 1)SIM\n 2)NAO");
			SetConsoleCursorPosition(saida,posicao);
			scanf("%d", &vazio);
			switch (vazio){
			case 1:
			printf("\n\n=======================\n");
			printf(" FORMA DE PAGAMENTO: [   ]\n 1)DINHEIRO\n 2)CARTAO");
			SetConsoleCursorPosition(saida,posicao2);
			scanf("%d", &vazio);
			printf("\n\n=======================\n");
			printf(" VALOR PAGO: ");
			scanf("%f", &valorPago);
			printf("=======================\n");
				break;
			case 2:
			printf("\n\n=======================\n");
			printf(" FORMA DE PAGAMENTO: [   ]\n 1)CARTAO DEBITO\n 2)CARTAO CREDITO");
			SetConsoleCursorPosition(saida,posicao3);
			scanf("%d", &vazio);
			printf("\n\n=======================\n");
			printf(" VALOR PAGO: ");
			scanf("%f", &valorPago);
			printf("=======================\n");
				break;
			default: printf("\n"); system("pause"); break;
			}
			float troco = valorPago-valorCompra;
			if (valorCompra > valorPago) {
				printf(" VALOR INSUFICIENTE!!");
				printf("\n=======================");
				} else {printf("\n===================================\n");
						printf(" TROCO: %.2f \n", troco); 
						printf("===================================\n");
						printf(" PEDIDO REALIZADO COM SUCESSO!!"); 
						printf("\n===================================\n"); }
				break;
		} break;
	} 
		if(statusProdCadastrado == 0){
		printf("===========================\n");
		printf("= PRODUTO NAO CADASTRADO! =\n");
		printf("===========================\n\n ");
		system("pause");
		menuCliente(produto);
		}
			printf(" COMPRAR NOVAMENTE? [   ]\n 1)SIM\n 2)NAO");
			SetConsoleCursorPosition(saida,posicao4);
			scanf("%d", &opCompra);
			if(opCompra == 1) { Comprar(produto); }	else { menuCliente(produto); }				
}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^ ESTOQUE E VENDA ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//