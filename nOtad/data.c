#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "data.h"
void dataSistema(int *d,int *m,int *a){
	char dateString[11];
	_strdate(dateString);//pega data do sistema
	char dia[3]={dateString[3],dateString[4],'\0'};
	char mes[3]={dateString[0],dateString[1],'\0'};
	char ano[3]={dateString[6],dateString[7],'\0'};
	*d=atoi(dia);
	*m=atoi(mes);
	int anoint=atoi(ano);
	*a=anoint+2000;
}
void dataVencimento(int *d,int *m,int *a){
	char dateString[11];
	printf("Inserir a data de vencimento dd/mm/aa: ");
	do{
		scanf(" %10[^\n]",dateString);
		if(verif_data(dateString)==0)
			printf("data invalida,Inserir a data de vencimento dd/mm/aa:");
	}while(verif_data(dateString)!=1);
	char dia[3]={dateString[0],dateString[1],'\0'};
	char mes[3]={dateString[3],dateString[4],'\0'};
	char ano[5]={dateString[6],dateString[7],dateString[8],dateString[9],'\0'};
	*d=atoi(dia);
	*m=atoi(mes);
	*a=atoi(ano);
}
void dataNova(int *d,int *m,int *a){
	char dateString[11];
	do{
		printf("Inserir a nova data no formato dd/mm/aa: ");
		scanf(" %10[^\n]",dateString);
		if(verif_data(dateString)==0)
			printf("data invalida\n");
	}while(verif_data(dateString)!=1);
	
	char dia[3]={dateString[0],dateString[1],'\0'};
	char mes[3]={dateString[3],dateString[4],'\0'};
	char ano[5]={dateString[6],dateString[7],dateString[8],dateString[9],'\0'};
	*d=atoi(dia);
	*m=atoi(mes);
	*a=atoi(ano);
}
int verif_data(char dateString[11]){
	char dia[3]={dateString[0],dateString[1],'\0'};
	char mes[3]={dateString[3],dateString[4],'\0'};
	int d=atoi(dia);
	int m=atoi(mes);
	int tam=0;int i=0;//tamanho tem de ser 10 dd/mm/aaaa
	while(dateString[i]!='\0'){
		tam+=1;
		i+=1;
	}
	if ((tam==10) && (d<=31) && (m<=12) &&(dateString[0]>='0'||dateString[0]<='9')&& (dateString[1]>='0'||dateString[1]<='9')&&(dateString[2]=='/')&& 
	(dateString[3]>='0'||dateString[3]<='9')&& (dateString[4]>='0'||dateString[4]<='9')&&(dateString[5]=='/')&& 
	(dateString[6]>='0'||dateString[6]<='9')&& (dateString[7]>='0'||dateString[7]<='9')&& (dateString[8]>='0'||dateString[8]<='9')
	&& (dateString[9]>='0'||dateString[9]<='9')){
		return 1;
	}
	return 0;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++	
int calculaVencimento(int dia,int mes,int ano,int sdia,int smes,int sano){
	int resultado,remes,resuldias;
	//-----------------------------------------------------------
	int quantiBiss;int naoBiss;
	//-----------------------------------------------------------
	quantiBiss=calcQuantBiInterv(ano,sano);
	naoBiss=(sano-ano)-quantiBiss;//quantidade nbiss=(segundo ano - primeiro)- quantidade de biss
	resultado=quntdiaBissex(quantiBiss,naoBiss);
	resuldias=calculadias(sdia,dia);
	remes=calculames(mes,smes,ano);
	return resuldias+remes+resultado;
}
int saberanoatual(int ano){
	int resp;
	if((ano%4==0 && ano%100!=0)|| (ano%400==0))
		resp=1;
	else
		resp=0;
	return resp;
}
int quntdiaBissex(int bissexto,int naobissexto){//me dá quantidade de dias feito o calculo
	int quantidade;
	if(bissexto==0 && naobissexto>0){//totalmente nenhum bissexto
		quantidade=naobissexto * 365;//quantidade normal de dias do ano
	}
	else if(bissexto>0&& naobissexto>0){//tendo bissexto e nao bissexto
		quantidade=(bissexto*366)+(naobissexto * 365);
	}
	else if(bissexto>0 && naobissexto==0){
		quantidade=(bissexto*366);
	}
	return quantidade;
}
int calcQuantBiInterv(int ano1,int ano2){
	int resp=0;
	for(int i=ano1;i<=ano2;i++){
		if((i%4==0 && i%100!=0)||i%400==0)
			resp+=1;
	}
	return resp;
}
int calculadias(int sdia,int dia){
	int resuldias=sdia-dia;
	if(resuldias<0)
		resuldias=resuldias*(-1);
	return resuldias;
}
int calculames(int mes, int smes,int ano1){
	int remes=0;
	int valorMes[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	//janeiro=0;fevereiro=1;marco=2;abril=3;maio=4;junho=5;julho=6;
	//agosto=7;setembro=8;outubro=9;novembro=10;dezembro=11;
	int x=saberanoatual(ano1);
	if(x==1)
		valorMes[1]=29;
	if(mes<smes){//se o mes da primeira data for menor que segunda data
		for(int i=mes-1;i<smes-1;i++){//percorre crescente
			remes+=valorMes[i];
		}
	}
	else if(mes>smes){//se o mes da segunda data for menor que primeira data/
		for(int i=mes-1;i>smes-1;i--){//se for mes 11 ele vai ta posicao 10
			remes+=valorMes[i];//percorre decrescente
		}	
	}
	else if(mes==smes){
		remes=0;//caso seja iguall
	}
	return remes;
}
