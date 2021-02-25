//IMPORTANTE COMPILAR PARA EXECUÇAO NO WINDOWS JA QUE BIBLIOTECAS UTILIZADAS DA TIME.H,PEGAR DATA
// DO SISTEMA NAO RODAM NO LIXUX...
//---------------ENTRAR ADMIN-----------
//loguin:admin
//senha:123
//___________FALTANDO SER FEITO__________
//##FAZER PARTE DA VALIDAÇAO;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "estoque.h"
#include "usuario.h"

int main(int argc,char *argv[]){
	FILE *arqui;
	arqui=fopen("usu.txt","ab");
	if(arqui==NULL){
		printf("erro nao e possivel abrir o arquivo!\n");
		exit(1);}
	fclose(arqui);//**************************************
	uSuario *fichaDuSEr;
	fichaDuSEr=dUeserVazio();
	lerAqui(&fichaDuSEr);//***************************
	static char aDmin[8]="admin";
	int log=loginAdm(fichaDuSEr);
	if(log==0){
		printf("VC errou o loguin e senha muitas vezes\n");
		exit(1);}//****************************************************
	FILE *pont;
	pont=fopen("estoque.txt","a");//adiciona ou cria sem apagar
	if (pont==NULL){
		printf("\n===== erro na abertura do arquivo! =====\n");
		exit(1);}
	fclose(pont);//****************************************
	Ficha *lista;//apontador para ponteiros;				
	lista=listaVazia();//--começo de tudo cria a inicio da lista;
	lerArquivo(&lista);//******************************
	FILE *reLATor;
	reLATor=fopen("relatorio.bin","ab");
	if(reLATor==NULL){
		printf("erro nao e possivel abrir o arquivo!\n");
		exit(1);}
	fclose(reLATor);//**************************************
	Relat *fichario;
	fichario=ficharioVazio();
	lerRelatorio(&fichario);
	if(strcmp(aDmin,nomeLogado)==0){
		chamaFuncADMin(fichario,lista,fichaDuSEr);}
	else{
		chamaFuncUser(fichario,lista,fichaDuSEr);}//*****************
	libedUeser(fichaDuSEr);
	liberarLista(lista);
	libefichario(fichario);
	printf("\n");
	printf("__________ FIM DE PROGRAMA __________\n");
	system("PAUSE");
	return 0;
}
