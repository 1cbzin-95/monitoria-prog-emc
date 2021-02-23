# include <stdio.h>
# include <stdlib.h>
# include <time.h>
int main(int argc, char *argv[]){
    srand(time(NULL));

    int numero;
    numero = 1 + rand()%100;      // entre 1 e 100, pois ran() sorteia entre 0 e 99
    printf("o numero sortedo foi %i \n",numero);
    return 0;
}