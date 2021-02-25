#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include "data.h"
#include "estoque.h"
#include "usuario.h"
//------------------------------------------TODA A PARTE RELACIONADA  AO ESTOQUE GERAL
Ficha *listaVazia(void){//inicio da lista
	return NULL;
}
Ficha *preencherLista(Ficha *lista){
	int d,m,a;
	Ficha *novoitem=(Ficha *)malloc(sizeof(Ficha));
	printf("Digite o nome do produto a ser estocado: ");
	scanf(" %30[^\n]",novoitem->nome);
	long int id;int x;
	do{
		printf("ID do produto: ");
		scanf("%ld",&id);
		x=verificaID(lista,id);
		if(x==1){
			printf("Esse ID ja pertence a outro produto\n");
		}
	}while(x==1);
	novoitem->iD=id;
	printf("Quantidade do produto: ");
	scanf("%d",&novoitem->quantidade);
	dataSistema(&d,&m,&a);
	novoitem->dia=d;
	novoitem->mes=m;
	novoitem->ano=a;
	//------------------------------------------------------------------
	int diaDv,mesDv,anoDv;
	dataVencimento(&diaDv,&mesDv,&anoDv);
	novoitem->vencidia=diaDv;
	novoitem->vencimes=mesDv;
	novoitem->venciano=anoDv;
	//--------------------------------------------------------------------
	novoitem->prox=lista;
	return novoitem;//novoitem aponta para lista;
}
int verificaID(Ficha *lista,long int id){
	Ficha *aux;
	int encont=0;
	for(aux=lista;aux!=NULL;aux=aux->prox){
		if (aux -> iD==id)
			encont=1;
	}
	return encont;
}
void lerLista(Ficha *lista){
	Ficha *aux;
	if(lista==NULL)
		printf("===== ESTOQUE VAZIO =====\n");
	for(aux=lista;aux!=NULL;aux=aux->prox){
		printf("Nome do produto estocado:%s\n",aux->nome);
		printf("ID do produto:%ld\n",aux->iD);
		printf("Quantidade do produto:%d\n",aux->quantidade);
		printf("Data de cadastro :%d/%d/%d\n",aux->dia,aux->mes,aux->ano);
		printf("Data de vencimento :%d/%d/%d\n",aux->vencidia,aux->vencimes,aux->venciano);
		printf("           ^ \n");
	}	
}
int tamanhoLista(Ficha *lista){
	if (lista==NULL)
		return 0;
	int tamanho=0;
	Ficha *aux=lista;//criar ponteiro auxiliar pra nao andar com a cabeça da lista;
	while(aux!=NULL){//percorre cada ponteiro ate que ele encontre NULL
		tamanho+=1;
		aux=aux->prox;
	}
	return tamanho;
}
int removerElemento(Ficha **lista,long int identificador){
	if(*lista==NULL)//se lista==Null nao tem nada
		return 0;
	Ficha *aux=*lista;
	Ficha *ant;
	while(aux != NULL && aux->iD!=identificador){
			ant=aux;
			aux=aux->prox;
	}
	if(aux==NULL)//nao encontrado
		return 2;
	if(aux==*lista){//em caso da lista so possuir um produto
		*lista=aux->prox;
	}
	else	
		ant->prox=aux->prox;
	free(aux);
	return 1;	
}
void liberarLista(Ficha *lista){
	if(lista!= NULL){
		Ficha *aux;
		while(lista!=NULL){
			aux=lista;//aux recebe o endereço  atual;
			lista=lista->prox;
			free(aux);
		}
	free(lista);
	}	
}
//_____________________________________________________________________
void gravarArquivo(Ficha *lista){
	FILE *pont;
	pont=fopen("estoque.txt","a");//adiciona ou cria sem apagar
	if (pont==NULL){
		printf("\nerro na abertura do arquivo!\n");
		exit(1);
	}
	Ficha *aux;//pego a lista e vou gravando em cada linha
	for (aux=lista;aux!=NULL;aux=aux->prox){
		fprintf(pont,"%ld_%d_%d_%d_%d_%d_%d_%d_%s\n",aux->iD,aux->quantidade,aux->dia,aux->mes,aux->ano,aux->vencidia,aux->vencimes,aux->venciano,aux->nome);
	}
	fclose(pont);
}
void lerArquivo(Ficha **lista){
	char nome[31];long int iD;int quantidade;int d,m,a;int vd,vm,va;//leio cada linha coloco em variaveis
	FILE *pont;
	pont=fopen("estoque.txt","r");
	if(pont==NULL){
		printf("\nnao e possivel ler o arquivo\n");
		exit(1);
	}//depois envio direto a lista;
	while(fscanf(pont,"%ld_%d_%d_%d_%d_%d_%d_%d_%40[^\n]",&iD,&quantidade,&d,&m,&a,&vd,&vm,&va,nome)!= EOF){
		Ficha *novoitem=(Ficha *)malloc(sizeof(Ficha));
		strcpy(novoitem->nome,nome);//pra eu fazer um campo receber uma string tenho que copiala e adiciona la
		novoitem->iD=iD;
		novoitem->quantidade=quantidade;
		novoitem->dia=d;
		novoitem->mes=m;
		novoitem->ano=a;
		//--------------------
		novoitem->vencidia=vd;
		novoitem->vencimes=vm;
		novoitem->venciano=va;
		//--------------------
		novoitem->prox=*lista;
		*lista=novoitem;	
	}
	fclose(pont);
}
void atualizaArquivo(void){
	FILE *pont;
	pont=fopen("estoque.txt","w");//apaga e escreve denovo
	if(pont==NULL){
		printf("\nnao e possivel abrir o arquivo\n");
		exit(1);
	}
	fclose(pont);
}
void buscarProduto(Ficha *lista,long int identificador){
	int encontrado=0;//recebera 1 quando produto for encontrado
	Ficha *aux;
	for(aux=lista;aux!=NULL;aux=aux->prox){
		if(aux->iD==identificador){
			printf("nome:%s\n",aux->nome);
			printf("iD:%ld\n",aux->iD);
			printf("quantidade:%d\n",aux->quantidade);
			printf("data de cadastro:%d/%d/%d\n",aux->dia,aux->mes,aux->ano);
			printf("data de vencimento:%d/%d/%d\n",aux->vencidia,aux->vencimes,aux->venciano);
			encontrado=1;
		}
	}
	if(aux==NULL && encontrado!=1)//se chegar ao fim e nao encontrado!
		printf("===== PRODUTO NAO CONSTA NO ESTOQUE =====\n");
}
int pegarQuantidade(){
	int quanti;
	printf("Quantidade a ser Inserida/Retirada no Estoque: ");
	do{
		scanf("%d",&quanti);
	}while(quanti<0);
	return quanti;
}
int alterarElem(Ficha **lista,long int identificador){
	int encontrado=0;//recebera 1 quando produto for encontrado
	if(*lista==NULL)
		return 0;
	Ficha *aux;
	for(aux=*lista;aux!=NULL;aux=aux->prox){
		if(aux->iD==identificador){
			int op=qualAlterar();
			if(op==1){
				printf("Inserir um novo nome para o produto: ");
				scanf(" %40[^\n]",aux->nome);
			}
			else if(op==2){
				printf("Inserir a nova quantidade para o produto: ");
				scanf("%d",&aux->quantidade);
			}
			else if(op==3){
				printf("Inserir uma nova data o produto: ");
				int dia,mes,ano;
				dataNova(&dia,&mes,&ano);
				aux->dia=dia;aux->mes=mes;aux->ano=ano;
			}
			encontrado=1;
		}
	}
	if(aux==NULL && encontrado!=1)//;se chegar ao fim e nao for encontrado!
		return 2;
	return 1;
}
int qualAlterar(){
	int resp;
	printf("Digite 1 para alterar nome\n");
	printf("Digite 2 para alterar a quantidade\n");
	printf("Digite 3 para alterar a data\n");
	printf("qual opcao vc quer alterar:");
	scanf("%d",&resp);
	return resp;
}
int acrescNoProduto(Ficha **lista,long int identificador,Relat **fichario){
	int di,me,an;
	int quantacres=0;
	int encontrado=0;//recebera 1 quando produto for encontrado
	Ficha *aux;
	Relat *novoFichario;
	novoFichario=(Relat *)malloc(sizeof(Relat));
	for(aux=*lista;aux!=NULL;aux=aux->prox){
		if(aux->iD==identificador){
			printf("Nome:%s\n",aux->nome);
			printf("iD:%ld\n",aux->iD);
			printf("Quantidade atual e:%d\n",aux->quantidade);
			quantacres=pegarQuantidade();//criar para facilitar entendimento e usar no RELATORIO
			aux->quantidade+=quantacres;
			dataSistema(&di,&me,&an);
			aux->dia=di;
			aux->mes=me;
			aux->ano=an;
			encontrado=1;
			//-------------------------------------
			strcpy(novoFichario->loginUsado,nomeLogado); 
			novoFichario->oprealizada=1; 
			novoFichario->iDprod=aux->iD;
			novoFichario->quantidade=quantacres;
			novoFichario->dia=di;
			novoFichario->mes=me;
			novoFichario->ano=an;
			novoFichario->prox=*fichario;
			*fichario=novoFichario;                        
			novoFichario=(Relat *)malloc(sizeof(Relat));
		}
	}
	free(novoFichario);
	if(aux==NULL && encontrado!=1)//;se chegar ao fim e nao for encontrado!
		return 2;
	return 0;
}
int retirarNoProduto(Ficha **lista,long int identificador,Relat **fichario){
	int di,me,an;
	int quantdecres=0;
	int encontrado=0;//recebera 1 quando produto for encontrado
	Ficha *aux;
	Relat *novoFichario;
	novoFichario=(Relat *)malloc(sizeof(Relat));
	for(aux=*lista;aux!=NULL;aux=aux->prox){
		if(aux->iD==identificador && aux->quantidade>0){
			printf("Nome:%s\n",aux->nome);
			printf("iD:%ld\n",aux->iD);
			printf("Quantidade atual e:%d\n",aux->quantidade);
			quantdecres=pegarQuantidade();
			while(aux->quantidade < quantdecres){//no caso de o cara querer retirar mais do que pode...
				quantdecres=pegarQuantidade();
			}
			aux->quantidade-=quantdecres;
			dataSistema(&di,&me,&an);
			aux->dia=di;
			aux->mes=me;
			aux->ano=an;
			encontrado=1;
			//-------------------------------------------------------PARTE PASSANDO PARA LISTA DE RELATORIO
			strcpy(novoFichario->loginUsado,nomeLogado); 
			novoFichario->oprealizada=2; 
			novoFichario->iDprod=aux->iD;
			novoFichario->quantidade=quantdecres;
			novoFichario->dia=di;
			novoFichario->mes=me;
			novoFichario->ano=an;
			novoFichario->prox=*fichario;
			*fichario=novoFichario;                        
			novoFichario=(Relat *)malloc(sizeof(Relat));
		}
		else if(aux->iD==identificador && aux->quantidade<=0)
			encontrado=3;
		
	}
	free(novoFichario);
	if(aux==NULL && encontrado==0)//;se chegar ao fim e nao for encontrado!
		return 2;
	else if (aux==NULL && encontrado==3)//;se chegar ao fim encontrar mas nao for maior que 0!
		return 3;
	return 0;
}
void VerProdVencimento(Ficha *lista){
	Ficha *aux;int diaPvencimento;int encontrou=0;
	for(aux=lista;aux!=NULL;aux=aux->prox){
		diaPvencimento=calculaVencimento(aux->dia,aux->mes,aux->ano,aux->vencidia,aux->vencimes,aux->venciano);
		if(diaPvencimento<=30){
			printf("nome:%s\n",aux->nome);
			printf("iD:%ld\n",aux->iD);
			printf("quantidade:%d\n",aux->quantidade);
			printf("data de cadastro:%d/%d/%d\n",aux->dia,aux->mes,aux->ano);
			printf("data de vencimento:%d/%d/%d\n",aux->vencidia,aux->vencimes,aux->venciano);
			printf("faltando %d dias\n",diaPvencimento);
			encontrou+=1;
		}
	}
	if(encontrou==0)
		printf("\nVoce nao Possui produtos que se vencerao nos proximos 30 Dias.\n");
}
//----------------------RELACIONADA RELATORIO-------------------------------
Relat *ficharioVazio(){
	return NULL;
}
void libefichario(Relat *fichario){
	if(fichario!= NULL){
		Relat *aux;
		while(fichario!=NULL){
			aux=fichario;//aux recebe o endereço  atual;
			fichario=fichario->prox;
			free(aux);
		}
	free(fichario);
	}
}
void verRelatorio(Relat *fichario){
	int opRealizada;
	Relat *aux;
	if(fichario==NULL)
		printf("=====RELAATORIO VAZIO =====\n");
	for(aux=fichario;aux!=NULL;aux=aux->prox){
		printf("Loguin que realizou operaçao:%s\n",aux->loginUsado);
		opRealizada=aux->oprealizada;
		if(opRealizada==1)
			printf("ACRESCENTOU\n");
		else
			printf("RETIROU\n");
		printf("Quantidade do produto:%d\n",aux->quantidade);
		printf("Data de cadastro:%d/%d/%d\n",aux->dia,aux->mes,aux->ano);
		printf("           ^ \n");
		printf("           ^ \n"); 
	}	
}
void lerRelatorio(Relat **fichario){
	Relat *novoRela;
	FILE *reLATor;
	reLATor=fopen("relatorio.bin","rb");
	if(reLATor==NULL){
		printf("erro nao e possivel abrir o arquivo!\n");
		exit(1);
	}
	novoRela=(Relat *)malloc(sizeof(Relat));
	while(fread(novoRela,sizeof(Relat),1,reLATor)){
		novoRela->prox=*fichario;
		*fichario=novoRela;
		novoRela=(Relat *)malloc(sizeof(Relat));
	}
	fclose(reLATor);
}
void gravarRela(Relat **fichario){
	FILE *reLATor;
	reLATor=fopen("relatorio.bin","ab");
	if(reLATor==NULL){
		printf("erro nao e possivel abrir o arquivo!\n");
		exit(1);
	}
	Relat *aux;
	for(aux=*fichario;aux!=NULL;aux=aux->prox){
		fwrite(aux,sizeof(Relat),1,reLATor);
	}
	fclose(reLATor);
}
void atuaizarRela(void){
	FILE *reLATor;
	reLATor=fopen("relatorio.bin","wb");
	if(reLATor==NULL){
		printf("erro nao e possivel abrir o arquivo!\n");
		exit(1);
	}
	fclose(reLATor);
}
void verporData(Relat *fichario){//##
	long int comparar;
	printf("informe o id:");
	scanf("%ld",&comparar);
	int d,m,a; int df,mf,af;
	printf("inicio\n");
	dataNova(&d,&m,&a);
	printf("fim\n");
	dataNova(&df,&mf,&af);
	Relat *aux;
	int depositos=0,retiradas=0;
	if(fichario==NULL)
		printf("=====Relatorio Vazio ainda nao houve movimentacao=====\n");
	for(aux=fichario;aux!=NULL;aux=aux->prox){
		if(aux->iDprod==comparar && (aux->dia >= d||aux->dia <= df ) && (aux->mes >= m||aux->mes <= mf ) && (aux->ano >= a||aux->ano <= af )){
			if(aux->oprealizada==1)
				depositos+=aux->quantidade;
			else
				retiradas+=aux->quantidade;
			encontrado+=1;
		}	
	}
	printf("Total de Depositos %d\n",depositos);
	printf("Total de Retirdas %d\n",retiradas);	
}
