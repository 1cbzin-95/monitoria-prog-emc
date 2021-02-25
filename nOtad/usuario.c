#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include "data.h"
#include "estoque.h"
#include "usuario.h"
//----------------------RELACIONADA USUARIOS-------------------------------
uSuario *dUeserVazio(void){
	return NULL;
}
void libedUeser(uSuario *fichaDuSEr){
	if(fichaDuSEr!= NULL){
		uSuario *aux;
		while(fichaDuSEr!=NULL){
			aux=fichaDuSEr;//aux recebe o endereço  atual;
			fichaDuSEr=fichaDuSEr->prox;
			free(aux);
		}
	free(fichaDuSEr);
	}
}
int menuadmin(){
		int opcao;
		printf("\n===== MENU PRINCIPAL =====\n");
		printf("\n     1 ----Cadastrar Produto a Ser Estocado\n");
		printf("     2 ----Quantidade de produtos Estocados\n");
		printf("     3 ----Mostrar produtos Estocados\n");
		printf("     4 ----Excluir produto\n");
		printf("     5 ----Procurar produto no estoque\n");
		printf("     6 ----Alterar dados de um produto estocado\n");
		printf("     7 ----Acrescentar produto no estoque\n");
		printf("     8 ----Retirada de produto do estoque\n");
		printf("     9 ----Mostrar usuarios\n");
		printf("     10 ---Ver Relatorio\n");
		printf("     11 ---Cadastar usuarios do sistema\n");
		printf("     12 ---Lista de produtos a se vencer\n");
		printf("     13----Sobre\n");
		printf("     14----Ver total de operaçoes de um produto durante data\n");
		printf("     0 ----Sair\n");
		printf("\nEscolha uma opcao: ");
		scanf("%d",&opcao);
		system("CLS");
		return opcao;
}
int menuUser(){
		int opcao;
		printf("\n===== MENU PRINCIPAL =====\n");
		printf("\n     1 ----Ver quantidade de produtos cadastrados\n");
		printf("     2 ----Mostrar produtos Cadastrados\n");
		printf("     3 ----Procurar produto\n");
		printf("     4 ----Acrescentar produto\n");
		printf("     5 ----Retirar produto\n");
		printf("     6 ----Ver Relatorio\n");
		printf("     7  ---Sobre\n");
		printf("     8  ---Lista de produtos a se vencer\n");
		printf("     0 ----Sair\n");
		printf("\nEscolha uma opcao: ");
		scanf("%d",&opcao);
		system("CLS");
		return opcao;
}
int loginAdm(uSuario *fichaDuSEr){
	char login[8] = "admin";// ADmin
	char senha[4] = "123";
	//uSuario *aux;
	char login1[21];
	int lguin=0;int lgsenha=0;int naoLogar=0;
	char buf[21] = {0};
	if(fichaDuSEr==NULL){
		while (lguin ==0 && lgsenha==0){
		naoLogar+=1;//para caso o boy erre 3 vezes ja saia
		printf("==============================\n");
		printf("          LOGIN: ");
		scanf(" %20[^\n]",login1); //aqui defini 20 para padrao de loguin
		
			if (strcmp(login, login1) == 0){ //strcmp() é uma função da biblioteca string.h que compara 2 strings. Se for igual a 0 é porque as duas são iguais.
				printf("==============================\n");
				printf("          SENHA: ");
				int  index = 0;
				while(lgsenha==0){
					char senha1 = getch();
					if(senha1 == ENTER)
						break;
					else
						putchar('*');
					buf[index] = senha1; 
					index++;				
				}
				buf[index]='\0';
				if (strcmp(senha, buf) == 0){
					strcpy(nomeLogado,login1);//O loguin vai la pro vetor global;
					lgsenha=1;lguin=1;
					printf("LOGADO");
					system("CLS");
				}
			}
			else if(naoLogar==10){
				system("CLS");
				return 0;
			}
			system("CLS");
		}
	}
	else{
		while (lguin ==0 && lgsenha==0){
			naoLogar+=1;//para caso o boy erre 3 vezes ja saia
			printf("==============================\n");
			printf("          LOGIN: ");
			scanf(" %20[^\n]",login1); //aqui defini 20 para padrao de loguin
			uSuario *aux;
			for(aux=fichaDuSEr;aux!=NULL;aux=aux->prox){
				if (strcmp(login, login1) == 0 || strcmp(aux->login,login1)==0){ //strcmp() é uma função da biblioteca string.h que compara 2 strings. Se for igual a 0 é porque as duas são iguais.
					printf("==============================\n");
					printf("          SENHA: ");
					int  index = 0;
					while(lgsenha==0){
						char senha1 = getch();
						if(senha1 == ENTER)
							break;
						else
							putchar('*');
						buf[index] = senha1; 
						index++;				
					}
					buf[index]='\0';
					if (strcmp(senha, buf) == 0 ||strcmp(aux->senha,buf)==0){
						strcpy(nomeLogado,login1);//O loguin vai la pro vetor global;
						lgsenha=1;lguin=1;
						printf("LOGADO");
						system("CLS");
					}
				}
				else if(naoLogar==10){
					system("CLS");
					return 0;
				}
				system("CLS");
			}
		}
	}
	return lguin==1 && lgsenha==1? 1:0;
}
void preenUser(uSuario **fichaDuSEr){
		uSuario *novoUser=(uSuario *)malloc(sizeof(uSuario));
		printf("insira o loguin: ");
		scanf(" %20[^\n]",novoUser->login);
		printf("insira o email: ");
		scanf(" %40[^\n]",novoUser->email);
		printf("insira a senha: "); 
		scanf(" %20[^\n]",novoUser->senha);
		novoUser->prox= *fichaDuSEr;
		*fichaDuSEr=novoUser;
}
void leer_User(uSuario *fichaDuSEr){
	uSuario *aux;
	if(fichaDuSEr==0){
		printf("ainda nao ha usuario cadastrados no momento.\n");
	}
	for(aux=fichaDuSEr;aux!=NULL;aux=aux->prox){
		printf("\n");
		printf("Loguin:%s\n",aux->login);
		printf("Email:%s\n",aux->email);
		printf("Senha:%s\n",aux->senha); 
	}
}
void gravar(uSuario **fichaDuSEr){
	FILE *arqui;
	arqui=fopen("usu.txt","ab");
	if(arqui==NULL){
		printf("erro nao e possivel abrir o arquivo!\n");
		exit(1);
	}
	uSuario *aux;
	for(aux=*fichaDuSEr;aux!=NULL;aux=aux->prox){
		fwrite(aux,sizeof(uSuario),1,arqui);
	}
	fclose(arqui);
}
void lerAqui(uSuario **fichaDuSEr){
	FILE *arqui;
	arqui=fopen("usu.txt","rb");
	if(arqui==NULL){
		printf("erro nao e possivel abrir o arquivo!\n");
		exit(1);
	}
	uSuario *novoUser;
	novoUser=(uSuario *)malloc(sizeof(uSuario));
	while(fread(novoUser,sizeof(uSuario),1,arqui)){
		novoUser->prox=*fichaDuSEr;
		*fichaDuSEr=novoUser;
		novoUser=(uSuario *)malloc(sizeof(uSuario));
	}
	fclose(arqui);
}
void atualizarArqui(void){
	FILE *arqui;
	arqui=fopen("usu.txt","wb");
	if(arqui==NULL){
		printf("erro nao e possivel abrir o arquivo!\n");
		exit(1);
	}
}
void chamaFuncADMin(Relat *fichario,Ficha *lista,uSuario *fichaDuSEr){
		int tamanho,result;long int identificador;int opcao;//saida;//variaveis relacionadas as opcoes de escolha e saida do projeto
		do{	opcao=menuadmin();
			switch(opcao){
				case 0://--Saida
					opcao=0;
					break;
				case 1://--Cadastrar produto
					printf("\n===== CADASTRO DE PRODUTO PARA ESTOCAR =====\n");
					lista=preencherLista(lista);
					atualizaArquivo();
					gravarArquivo(lista);
					break;
				case 2://--Quantidade de produtos CAdastrados
					tamanho=tamanhoLista(lista);
					printf("\nseu estoque possui:%d produto(s)\n",tamanho);
					break;
				case 3://----Mostrar produtos Cadastrados
					printf("\n===== LISTA DE ESTOCADOS =====\n");
					lerLista(lista);
					break;
				case 4://Excluir produto\n
					printf("\nDigite o iD elemento que voce quer excluir:");
					scanf("%ld",&identificador);
					result=removerElemento(&lista,identificador);
					if(result==0)
						printf("\nESTOQUE VAZIO\n");
					else if(result==2)
					printf("\nITEM NAO EXISTE NO ESTOQUE\n");
					else{
						printf("\nExcluido com Sucesso!\n");
						atualizaArquivo();
						gravarArquivo(lista);}
					break;
				case 5://----procurar produto
					printf("\nDigite o iD elemento que voce procura:");
					scanf("%ld",&identificador);
					buscarProduto(lista,identificador);
					break;
				case 6://----alterar dados produto
					printf("\nDigite o iD elemento que quer fazer a ALTERACAO:");
					scanf("%ld",&identificador);
					result=alterarElem(&lista,identificador);			
					if(result==0)
						printf("\nESTOQUE VAZIO\n");
					else if(result==1)
						printf("\noperaçao realizada com sucesso\n");
					else if(result==2)
						printf("\nELEMENTO NAO COSTA NO ESTOQUE\n");
					atualizaArquivo();
					gravarArquivo(lista);
					break;
				case 7://----acrescentar produto
					printf("\nDigite o iD elemento que voce quer ACRESCENTAR:");
					scanf("%ld",&identificador);
					result=acrescNoProduto(&lista,identificador,&fichario);
					if(result==2)
						printf("ITEM NAO COSTA NO ESTOQUE\n");
					else if(result==0)
						printf("Operacao realizda com sucesso\n");
					atualizaArquivo();
					gravarArquivo(lista);
					//===============================
					atuaizarRela();
					gravarRela(&fichario); 
					break;
				case 8://----retirar produto
					printf("\nDigite o iD elemento que voce quer RETIRAR:");
					scanf("%ld",&identificador);
					result=retirarNoProduto(&lista,identificador,&fichario);
					if(result==2)
						printf("\nITEM INEXISTENTE\n");
					else if(result==3)
						printf("\nO PRODUTO EXISTE, POREM ESTA ZERADO\n");
					else if(result==0)
						printf("\nOperaçao realizada com sucesso\n");
					atualizaArquivo();
					gravarArquivo(lista);
					atuaizarRela();
					gravarRela(&fichario); 
					break;
				case 9://mostrar usuarios
					leer_User(fichaDuSEr);
					break;
				case 10:
					verRelatorio(fichario);
					printf("=====FIM DE RELATORIO=====\n");
					break;
				case 11://cadastrar usauarios do sistema
					preenUser(&fichaDuSEr);
					atualizarArqui();
					gravar(&fichaDuSEr);
					break;
				case 12://LIsta a se vencer
					VerProdVencimento(lista);
					break;
				case 13: //---- para ver os autores do projeto
					printf("\n==================================================================================================\n");
					printf("   A EstoqueMax e um programa para gerenciamento de estoque, feito por Clodoaldo e Joao Batista,\n     o EstoqueMax permite cadastrar produtos, retirar, alterar, excluir, entre outras funcoes\n                               para auxiliar no controle da administracao.");
					printf("\n==================================================================================================\n");
					break;
				case 14: //---- ver total de operaçoes de um prod do estoque 
					verporData(fichario);//##
					break;
				default:
					printf("\nOPCAO INVALIDA\n");
					break;
			}
		}while(opcao!=0);
}
void chamaFuncUser(Relat *fichario,Ficha *lista,uSuario *fichaDuSEr){
		int tamanho,result;long int identificador;int opcao;//saida;//variaveis relacionadas as opcoes de escolha e saida do projeto
		do{	opcao=menuUser();
			switch(opcao){
				case 0://--Saida
					opcao=0;
					break;
				case 1://--Quantidade de produtos CAdastrados
					tamanho=tamanhoLista(lista);
					printf("\nseu estoque possui:%d produto(s)\n",tamanho);
					break;
				case 2://----Mostrar produtos Cadastrados
					printf("\n===== LISTA DE ESTOCADOS =====\n");
					lerLista(lista);
					break;
				case 3://----procurar produto
					printf("\nDigite o iD elemento que voce procura:");
					scanf("%ld",&identificador);
					buscarProduto(lista,identificador);
					break;
				case 4://----acrescentar produto
					printf("\nDigite o iD elemento que voce quer ACRESCENTAR:");
					scanf("%ld",&identificador);
					result=acrescNoProduto(&lista,identificador,&fichario);
					if(result==2)
						printf("ITEM NAO COSTA NO ESTOQUE\n");
					else if(result==0)
						printf("Operacao realizda com sucesso\n");
					atualizaArquivo();
					gravarArquivo(lista);
					//===============================
					atuaizarRela();
					gravarRela(&fichario); 
					break;
				case 5://----retirar produto
					printf("\nDigite o iD elemento que voce quer RETIRAR:");
					scanf("%ld",&identificador);
					result=retirarNoProduto(&lista,identificador,&fichario);
					if(result==2)
						printf("\nITEM INEXISTENTE\n");
					else if(result==3)
						printf("\nO PRODUTO EXISTE, POREM ESTA ZERADO\n");
					else if(result==0)
						printf("\nOperaçao realizada com sucesso\n");
					atualizaArquivo();
					gravarArquivo(lista);
					atuaizarRela();
					gravarRela(&fichario); 
					break;
				case 6://consultar relatorio
					verRelatorio(fichario);
					printf("=====FIM DE RELATORIO=====\n");
					break;
				case 7: //---- para ver os autores do projeto
					printf("\n==================================================================================================\n");
					printf("   A EstoqueMax e um programa para gerenciamento de estoque, feito por Clodoaldo e Joao Batista,\n     o EstoqueMax permite cadastrar produtos, retirar, alterar, excluir, entre outras funcoes\n                               para auxiliar no controle da administracao.");
					printf("\n==================================================================================================\n");
					break;
				case 8://LIsta a se vencer
					VerProdVencimento(lista);
					break;
				default:
					printf("\nOPCAO INVALIDA\n");
					break;
			}
		}while(opcao!=0);
} 
