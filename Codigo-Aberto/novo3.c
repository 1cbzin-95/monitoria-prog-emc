#include <stdio.h>

//Ponteiro de estruturas
int main (int argc , char *argv[]){
    struct horario{
        int hora;
        int minuto;
        int segundo;
    };


    struct horario agora, *depois;    // tenho um struct agora e um ponteiro para struct depois
    depois = &agora;                   //depois recebe o endereço de agora
                                       //alterar valores utilizando o ponteiro

    //1 das maneiras de acessar um ponteiro de estrutura é usando () de precedencia
    (*depois).hora=20;
    (*depois).minuto=20;
    (*depois).segundo=30;
    //2 utilizando atalho
    depois->hora=40;
    depois->minuto=40;
    depois->segundo=40;

    printf("%i:%i:%i \n",agora.hora,agora.minuto,agora.segundo);
    printf("tudo ok \n");
    return 0;
}