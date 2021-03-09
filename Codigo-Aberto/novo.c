#include <stdio.h>

void bagunca(int *vetor,int tamanho);
void mostraVetor(int vetor[],int tamanho);
//struct 

//estruturas --> structs
struct horario{//definir o tipo
        int horas;
        int minuto;
        int segundo;
        //bool verdadeiro;
};

struct hora{                     //definindo estrutura e em seguida variavel do tipo dela para ser utilizada;
    int horas;
    int minuto;
    int segundo;
    //bool verdadeiro;
}Horario,QualquerOutra,Maisuma;

void printarEstrutura(struct horario x);

int main(int argc, char *argv[]){
    int vetor[5]={1,2,3,4,5};
    mostraVetor(vetor,5);
    bagunca(vetor,5);
    printf("------------------------\n");
    mostraVetor(vetor,5);
    printf("------------------------\n");
    struct horario Agora; //harario é o tipo ->agora é o nome da estrutura;

    Agora.horas = 15;//acessar e definir valor dentro da estrutura
    printf("%i <- -> \n",Agora.horas);

    printarEstrutura(Agora);


    return 0;
}

//struct horario 
void printarEstrutura(struct horario x){
    printf("sao :%d horas \n",x.horas);
}
void bagunca(int *vetor,int tamanho){
    int vetorAux[tamanho];
    for(int i=0;i<tamanho;i++){
        vetorAux[i]=vetor[i+1];
        if(i==4){
            vetorAux[4]=vetor[4];
        }
    }
    //passo de volta
    for(int i=0;i<tamanho;i++){
        vetor[i]=vetorAux[i];
    }
}
void mostraVetor(int vetor[],int tamanho){
    for(int i=0;i<tamanho;i++){
        printf("posicao:%d == %d \n",i,vetor[i]);
    }
}
