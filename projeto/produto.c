#include <stdio.h>
#include <time.h>
#include "produto.h"
#include "delay.h"

void moduloProduto(void){
	char opcao;
	do {
		opcao = menuProduto();
		switch(opcao) {
			case '1': 	//cadastrarProduto();
						break;
			case '2': 	//pesquisarProduto();
						break;
			case '3': 	//atualizarProduto();
						break;
			case '4': 	//excluirProduto();
						break;
		} 		
	} while (opcao != '0');
}
char menuProduto(void){
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
	printf("|           1. Cadastrar um novo Produto                                |\n");
	printf("|           2. Pesquisar os dados de um Produto                         |\n");
	printf("|           3. Atualizar o cadastro de um Produto                       |\n");
	printf("|           4. Excluir um Produto do sistema                            |\n");
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
void telaProduto(void){
    printf("produto---------------------------------\n");
}