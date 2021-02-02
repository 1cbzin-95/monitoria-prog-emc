#include <stdio.h>
/*
O parâmetro argc representa o número de argumentos da linha de comando, 
e char * argv [] é uma matriz de strings (ponteiros de caracteres) que representam os 
argumentos individuais fornecidos na linha de comando. A função principal pode ter dois parâmetros, argc e argv .
*/
int impaoupar(int numero);

int main(int argc,char *argv[]){
    /*---------------------------------------------------Declarando variaveis em c-----------------------------------------------*/
    /*Variaveis contantes, não podem ser modificadas*/
    const int tamanho =30;
    /* Vetor de caracteres (char) */
    char nome[30] ="";
    /* Inteiro */
    int idade = 25 ;
    /*Flutuante, com casas decimais*/
    float altura = 1.70;
    /*Double -> um ponto flutuante com mais capacidade de casa decimais*/
    double pi = 3.1416141614;

    /*especificação de tipos*/
    printf("meu nome e: %s, tenho: %d anos de idade, altura: %.2f e estudei que pi e um numero aproximado de: %lf ...",nome,idade,altura,pi);

    /*----------------------------------------- Lendo valores do teclado com scanf_precisa indicar o tipo da variavel destino e a variavel-------------------------------------*/
    printf("informe sua idade: ");
    scanf("%d",&idade);
    /*
    int x = impaoupar(idade);
    char ehPar[8]= " ";
    if(x==1){
        ehPar="Par";
    }else{
        ehPar="Impar";
    }
    printf("sua idade e: %s ",ehPar);

    printf("informe sua altura: ");
    scanf("%f",&altura);*/


    /*---------------------------------------------------------------------------------- Loop ------------------------------------------------------------------------------------*/
    for(int x=0;x<10;x++){
        printf("Agora vai\n");
    }
    int x=0;
    while(x<10){
        printf("Agora  while\n");
        x++;
    }
    x=0;
    do{
        printf("Agora Do while\n");
        x++; 
    }while(x<10);

    /*----------------------------------------------------------------------------------- Vetores -----------------------------------------------------------------------------------*/
    

    return 0;
}

int impaoupar(int numero){
    return numero%2==0? 1:0;
}