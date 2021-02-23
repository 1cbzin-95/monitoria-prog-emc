#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Assinaturas das funções
char menuPrincipal(void);
void moduloInformacoes(void);
void telaSobre(void);

//modulo Usuario
void moduloUsuario(void);
char menuUsuario(void);
void cadastrarUsuario(void);  // C
void pesquisarUsuario(void);  // R
void atualizarUsuario(void);  // U
void excluirUsuario(void);    // D

//telas
void telaSobre(void);
void telaCadastrarUsuario(void);  // C
void telaPesquisarUsuario(void);  // R
void telaAtualizarUsuario(void);  // U
void telaExcluirUsuario(void);    // D

void moduloRelatorio(void);
void delay(int);

// Programa Principal

int main(void) {
	char opcao;
	do {
		opcao = menuPrincipal();
		switch(opcao) {
			case '1': 	moduloUsuario();
						break;
			case '4': 	moduloRelatorio();
						break;
			case '5': 	moduloInformacoes();
						break;
            default:
                if(opcao!='0'){
                    printf("opção invalida, tente novamente!\n");
					delay(2);
                }
		} 		
	} while (opcao != '0');
	return 0;    
}
char menuPrincipal(void) {
	char op;
    system("clear");
	printf("\n");
	printf("------------------------------------------------------------------------------\n");
	printf("|                                                                            |\n");
	printf("|            ===================================================             |\n");
	printf("|            = = = = = = = = = = = = = = = = = = = = = = = = = =             |\n");
	printf("|            = = = =       Controle de Estoque           = = = =             |\n");
	printf("|            = = = = = = = = = = = = = = = = = = = = = = = = = =             |\n");
	printf("|            ===================================================             |\n");
	printf("|                Developed by  @clodoaldoBrito - Jan, 2021                   |\n");
	printf("|                                                                            |\n");
	printf("-----------------------------------------------------------------------------|\n");
	printf("|                                                                            |\n");
	printf("|           = = = = = = = = = = = = = = = = = = = = = = = =                  |\n");
	printf("|           = = = = = = = =  Menu Principal = = = = = = = =                  |\n");
	printf("|           = = = = = = = = = = = = = = = = = = = = = = = =                  |\n");
	printf("|                                                                            |\n");
	printf("|           1. Módulo Usuario                                                |\n");
	printf("|           2. Módulo Produto                                                |\n");
	printf("|           3. Módulo Estoque                                                |\n");
	printf("|           4. Módulo relatórios                                             |\n");
	printf("|           5. Informações sobre o sistema                                   |\n");
	printf("|           0. Encerra o programa                                            |\n");
	printf("|                                                                            |\n");
	printf("|           Escolha a opção desejada: ");
	scanf("%c", &op);
	getchar();
	printf("|                                                                            |\n");
	printf("|                                                                            |\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	delay(3);
	return op;
}

void telaSobre(void) {
    system("clear");
	printf("\n");
	printf("-----------------------------------------------------------------------------\n");
	printf("|                                                                           |\n");
	printf("|              Universidade Federal do Rio Grande do Norte                  |\n");
	printf("|                  Centro de Ensino Superior do Seridó                      |\n");
	printf("|                Departamento de Computação e Tecnologia                    |\n");
	printf("|                   Disciplina DCT1106 -- Programação                       |\n");
	printf("|                   Projeto de Controle de estoque                          |\n");
	printf("|                 Developed by  @clodoaldo brito - Jan, 2021                |\n");
	printf("|                                                                           |\n");
	printf("|---------------------------------------------------------------------------|\n");
	printf("|                                                                           |\n");
	printf("|          ===================================================              |\n");
	printf("|          = = = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
	printf("|          = = = =       Controle de Estoque           = = = =              |\n");
	printf("|          = = = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
	printf("|          ===================================================              |\n");
	printf("|                                                                           |\n");
	printf("| Programa exemplo utilizado na disciplina DCT1106 - Programação, para      |\n");
	printf("| fins didáticos de orientação. O programa contém os principais módulos     |\n");
	printf("| e funcionalidades que serão exigidos na avaliação dos projetos a          |\n");
	printf("| serem desenvolvidos pelos Usuarios ao longo da disciplina. Serve como     |\n");
	printf("| um guia de consulta e referência para o desenvolvimento dos demais        |\n");
 	printf("| projetos. Todos os dados e informações utilizados neste projeto são       |\n");
 	printf("| fictícios.                                                                |\n");
	printf("|                                                                           |\n");
	printf("-----------------------------------------------------------------------------\n");
	printf("\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

void delay(int segundos) {
  int tempo = 500000 * segundos;
  clock_t inicio = clock();
  while (clock() < inicio + tempo) {
    // não faz nada, apenas gasta tempo
  }
}

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
	printf("|                Developed by  @clodoaldobrito - Jan, 2021              |\n");
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
	char matr[12];
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
	printf("|                Developed by  @clodoaldobrito - Jan, 2021              |\n");
	printf("|                                                                       |\n");
	printf("|-----------------------------------------------------------------------|\n");
	printf("|                                                                       |\n");
	printf("|           = = = = = = = = = = = = = = = = = = = = = = = =             |\n");
	printf("|           = = = = = = = = Cadastrar Usuario = = = = = = = =           |\n");
	printf("|           = = = = = = = = = = = = = = = = = = = = = = = =             |\n");
	printf("|                                                                       |\n");
	printf("|           Matrícula (apenas números): ");
	scanf("%[0-9]", matr);
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
	printf("|                Developed by  @clodoaldobrito - Jan, 2021              |\n");
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
	printf("|                Developed by  @clodoaldobrito - Jan, 2021              |\n");
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
void moduloRelatorio(void) {
	// modulo em desenvolvimento

}
void moduloInformacoes(void) {
	// modulo em desenvolvimento
	telaSobre();

}