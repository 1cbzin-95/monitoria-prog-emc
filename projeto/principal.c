#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tempo.h"
#include "usuario.h"
#include "produto.h"

// Assinaturas das funções
char menuPrincipal(void);
void moduloInformacoes(void);
void moduloRelatorio(void);

void telaSobre(void);// mais modulos a definir, void moduloEstoque(void);

int main(void) {
	char opcao;
	do {
		opcao = menuPrincipal();
		switch(opcao) {
			case '1': 	moduloUsuario();
						break;
			case '2': 	moduloProduto();
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
void moduloRelatorio(void) {
	// modulo em desenvolvimento

}
void moduloInformacoes(void) {
	// modulo em desenvolvimento
	telaSobre();
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