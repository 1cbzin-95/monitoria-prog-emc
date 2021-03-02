#include <stdio.h>
#include <stdlib.h>
#include "tempo.h"
#include "usuario.h"
//								Módulo Usuario
void moduloUsuario(void) {
	char opcao;
	do {
		opcao = menuUsuario();
		switch(opcao) {
			case '1': 	cadastrarUsuario();
						break;
			case '2': 	pesquisarUsuario();
						break;
			case '3': 	atualizarUsuario();
						break;
			case '4': 	excluirUsuario();
						break;
		} 		
	} while (opcao != '0');
}

void cadastrarUsuario(void) {
	// função ainda em desenvolvimento
	// exibe a tela apenas para testes
	telaCadastrarUsuario();
}

void pesquisarUsuario(void) {
	// função ainda em desenvolvimento
	// exibe a tela apenas para testes
	telaPesquisarUsuario();
}

void atualizarUsuario(void) {
	// função ainda em desenvolvimento
	// exibe a tela apenas para testes
	telaAtualizarUsuario();
}

void excluirUsuario(void) {
	// função ainda em desenvolvimento
	// exibe a tela apenas para testes
	telaExcluirUsuario();
}

char menuUsuario(void) {
	char op;
    system("clear");
	printf("\n");
	printf("|-----------------------------------------------------------------------|\n");
	printf("|                                                                       |\n");
	printf("|          ===================================================          |\n");
	printf("|          = = = = = = = = = = = = = = = = = = = = = = = = = =          |\n");
	printf("|          = = = =       Controle de Estoque           = = = =          |\n");
	printf("|          = = = = = = = = = = = = = = = = = = = = = = = = = =          |\n");
	printf("|          ===================================================          |\n");
	printf("|                Developed by  @clodoaldo brito - Jan, 2021             |\n");
	printf("|                                                                       |\n");
	printf("|-----------------------------------------------------------------------|\n");
	printf("|                                                                       |\n");
	printf("|           = = = = = = = = = = = = = = = = = = = = = = = =             |\n");
	printf("|           = = = = = = = = =  Menu Usuario = = = = = = = =             |\n");
	printf("|           = = = = = = = = = = = = = = = = = = = = = = = =             |\n");
	printf("|                                                                       |\n");
	printf("|           1. Cadastrar um novo Usuario                                |\n");
	printf("|           2. Pesquisar os dados de um Usuario                         |\n");
	printf("|           3. Atualizar o cadastro de um Usuario                       |\n");
	printf("|           4. Excluir um Usuario do sistema                            |\n");
	printf("|           0. Voltar ao menu anterior                                  |\n");
	printf("|                                                                       |\n");
	printf("|           Escolha a opção desejada: ");
	scanf("%c", &op);
	getchar();
	printf("|                                                                       |\n");
	printf("|                                                                       |\n");
	printf("|-----------------------------------------------------------------------|\n");
	printf("\n");
	delay(1);
	return op;
}

void telaCadastrarUsuario(void) {
	char id[12];
	char nome[51];
	char email[51];
	char nasc[11];
	char celular[12];
    system("clear");
	printf("\n");
	printf("|-----------------------------------------------------------------------|\n");
	printf("|                                                                       |\n");
	printf("|          ===================================================          |\n");
	printf("|          = = = = = = = = = = = = = = = = = = = = = = = = = =          |\n");
	printf("|          = = = =       Controle de Estoque           = = = =          |\n");
	printf("|          = = = = = = = = = = = = = = = = = = = = = = = = = =          |\n");
	printf("|          ===================================================          |\n");
	printf("|                Developed by  @clodoaldo brito - Jan, 2021             |\n");
	printf("|                                                                       |\n");
	printf("|-----------------------------------------------------------------------|\n");
	printf("|                                                                       |\n");
	printf("|           = = = = = = = = = = = = = = = = = = = = = = = =             |\n");
	printf("|           = = = = = = = = Cadastrar Usuario = = = = = = = =           |\n");
	printf("|           = = = = = = = = = = = = = = = = = = = = = = = =             |\n");
	printf("|                                                                       |\n");
	printf("|           Matrícula (apenas números): ");
	scanf("%[0-9]", id);
	getchar();
	printf("|           Nome completo: ");
	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nome);
	getchar();
	printf("|           E-mail: ");
	scanf("%[a-z@.]", email);
	getchar();
	printf("|           Data de Nascimento (dd/mm/aaaa):  ");
	scanf("%[0-9/]", nasc);
	getchar();
	printf("|           Celular  (apenas números): ");
	scanf("%[0-9]", celular);
	getchar();
	printf("|                                                                       |\n");
	printf("|                                                                       |\n");
	printf("|-----------------------------------------------------------------------|\n");
	printf("\n");
	delay(1);
}

void telaPesquisarUsuario(void) {
	char matr[12];
    system("clear");
	printf("\n");
	printf("|-----------------------------------------------------------------------|\n");
	printf("|                                                                       |\n");
	printf("|          ===================================================          |\n");
	printf("|          = = = = = = = = = = = = = = = = = = = = = = = = = =          |\n");
	printf("|          = = = =       Controle de Estoque           = = = =          |\n");
	printf("|          = = = = = = = = = = = = = = = = = = = = = = = = = =          |\n");
	printf("|          ===================================================          |\n");
	printf("|                Developed by  @clodoaldo brito - Jan, 2021             |\n");
	printf("|                                                                       |\n");
	printf("|-----------------------------------------------------------------------|\n");
	printf("|                                                                       |\n");
	printf("|           = = = = = = = = = = = = = = = = = = = = = = = =             |\n");
	printf("|           = = = = = = = = Pesquisar Usuario = = = = = = = =           |\n");
	printf("|           = = = = = = = = = = = = = = = = = = = = = = = =             |\n");
	printf("|                                                                       |\n");
	printf("|           Informe a matrícula do Usuario (apenas números): ");
	scanf("%[0-9]", matr);
	getchar();
	printf("|                                                                       |\n");
	printf("|                                                                       |\n");
	printf("|-----------------------------------------------------------------------|\n");
	printf("\n");
	delay(1);
}

void telaAtualizarUsuario(void) {
	char matr[12];
    system("clear");
	printf("\n");
	printf("|-----------------------------------------------------------------------|\n");
	printf("|                                                                       |\n");
	printf("|          ===================================================          |\n");
	printf("|          = = = = = = = = = = = = = = = = = = = = = = = = = =          |\n");
	printf("|          = = = =       Controle de Estoque           = = = =          |\n");
	printf("|          = = = = = = = = = = = = = = = = = = = = = = = = = =          |\n");
	printf("|          ===================================================          |\n");
	printf("|                Developed by  @clodoaldo brito - Jan, 2021             |\n");
	printf("|                                                                       |\n");
	printf("|-----------------------------------------------------------------------|\n");
	printf("|                                                                       |\n");
	printf("|           = = = = = = = = = = = = = = = = = = = = = = = =             |\n");
	printf("|           = = = = = = = = Atualizar Usuario = = = = = = = =           |\n");
	printf("|           = = = = = = = = = = = = = = = = = = = = = = = =             |\n");
	printf("|                                                                       |\n");
	printf("|           Informe a matrícula do Usuario (apenas números): ");
	scanf("%[0-9]", matr);
	getchar();
	printf("|                                                                       |\n");
	printf("|                                                                       |\n");
	printf("|-----------------------------------------------------------------------|\n");
	printf("\n");
	delay(1);
}

void telaExcluirUsuario(void) {
	char matr[12];
    system("clear");
	printf("\n");
	printf("|-----------------------------------------------------------------------|\n");
	printf("|                                                                       |\n");
	printf("|          ===================================================          |\n");
	printf("|          = = = = = = = = = = = = = = = = = = = = = = = = = =          |\n");
	printf("|          = = = =       Controle de Estoque           = = = =          |\n");
	printf("|          = = = = = = = = = = = = = = = = = = = = = = = = = =          |\n");
	printf("|          ===================================================          |\n");
	printf("|                Developed by  @clodoaldobrito - Jan, 2021              |\n");
	printf("|                                                                       |\n");
	printf("|-----------------------------------------------------------------------|\n");
	printf("|                                                                       |\n");
	printf("|           = = = = = = = = = = = = = = = = = = = = = = = =             |\n");
	printf("|           = = = = = = = =  Excluir Usuario  = = = = = = = =           |\n");
	printf("|           = = = = = = = = = = = = = = = = = = = = = = = =             |\n");
	printf("|                                                                       |\n");
	printf("|           Informe a matrícula do Usuario (apenas números): ");
	scanf("%[0-9]", matr);
	getchar();
	printf("|                                                                       |\n");
	printf("|                                                                       |\n");
	printf("|-----------------------------------------------------------------------|\n");
	printf("\n");
	delay(1);
}