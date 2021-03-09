#include <stdio.h>

void bagunca(int *vetor,int tamanho);
void mostraVetor(int vetor[],int tamanho);

int main(int argc, char *argv[]){
    int vetor[5]={1,2,3,4,5};
    mostraVetor(vetor,5);
    bagunca(vetor,5);
    printf("------------------------\n");
    mostraVetor(vetor,5);

    return 0;
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
