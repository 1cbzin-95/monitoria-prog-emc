#include <stdio.h>

int main (int argc, char *argv[]){
    printf("Brincando com ponteiros \n");
    int x = 10;
    printf("%i \n",x);
    printf(" acessando o endereço da variavel %i \n",&x);

    // Para criar o ponteiro preciso dizer primeiro de que tipo é esse ponteiro
    int *ponteiro;
    ponteiro = &x; //Ponteiro esta apontando no endereço de x
    printf(" ponteiro tem acesso ao valor da variavel x: %i \n",*ponteiro);//Mostrando o valor que ele tem,ja que ele aponta em x
    printf(" ponteiro aponta em que é no endereco x: %i \n",ponteiro);
    //Com asterisco acessa -> valor da memoria
    //Sem asterisco acessa -> valor que o ponteiro aponta ou endereço




    //Diferença no modo de escrever
    // int *ponteiro;
    // ponteiro = &x; //Ponteiro esta apontando no endereço de x
    int *pont = &x;//então fica
    printf(" ponteiro aponta em que é no endereco x: %i \n",pont);



    return 0;
}