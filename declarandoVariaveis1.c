#include <stdio.h>
/*
O parâmetro argc representa o número de argumentos da linha de comando, 
e char * argv [] é uma matriz de strings (ponteiros de caracteres) que representam os 
argumentos individuais fornecidos na linha de comando. A função principal pode ter dois parâmetros, argc e argv .
*/
int impaoupar(int numero);
int validaCpf(char vetor[]);

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
    /* ---------------------------------------------------------------------------------- Vetores ----------------------------------------------------------------------------------*/    
    /* vetor de inteiros --  calcular tamanho de um vetor --> sizeof(vetor)/sizeof(int)*/
    int vetorInteiro[10]={0,1,2,3,4,5,6,7,8,9};
    for(int i =0;i<10;i++){
        printf("%i |",vetorInteiro[i]);
     }
    printf("\n");

    for(int i =0;i<10;i++){
        printf("insira a nota %i:",i+1);
        scanf("%i",&vetorInteiro[i]);
    }
    for(int i =0;i<10;i++){
        printf("%i |",vetorInteiro[i]);
    }
    printf("\n");
    /* vetor de caracteres -- */
    char nome3[30]={'c','l','1','0'};
    printf("%s\n",nome3);

    /*-----------------------------------------------------------valida cpf parte 1 sem os calculos -----------------------------------------------------------------------------*/
    printf("Digite o seu cpf com pontuação no formato XXX.XXX.XXX-XX \n");
    char cpf[15]={'1','1','9','.','9',' 9','8','.','0','8','4','-','9','1'};
    int ehValido = validaCpf(cpf);
    printf("%i",ehValido);

    return 0;
}

int impaoupar(int numero){
    return numero%2==0? 1:0;
}
int validaCpf(char vetor[]){
    int ehValido=1;
    for(int i=0;i<14;i++){
        if(vetor[3]!='.' || vetor[7]!='.' || vetor[11]!='-'){
            ehValido=0;
        }
    }
    return ehValido;
}