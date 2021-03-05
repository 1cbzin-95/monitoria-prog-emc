#include <stdio.h>
#include <time.h>
#include <string.h> /* Uso atoi*/
#include <stdlib.h> /* Uso atoi*/
#include "dataValida.h"
// No arquivo de cabeçalho time.h existem funções e tipos de dados para manipular informações de tempo e datas.
// O tipo de dados struct tm define uma struct para ser utilizada em funções que trabalham com data e hora.
// struct tm {
//     int tm_sec;   // Indica os segundos de 0 a 59
//     int tm_min;   // Indica os minutos de 0 a 59
//     int tm_hour;  // Indica as horas de 0 a 24
//     int tm_mday:  // Indica os dias do mês de 1 a 31
//     int tm_mon;   // Indica os meses do ano de 0 a 11
//     int tm_year;  // Indica o ano a partir de 1900
//     int tm_wday;  // Indica o dia da semana de 0 (domingo) até 6 (sábado)
//     int tm_yday;  // Indica o dia do ano de 1 a 365
//     int tm_isdst; // Indica o horário de verão se for diferente de zero
// };
int main(void) {
	// Você tem que usar a função localtime() para lhe fornecer a data em uma estrutura, depois pode montar como quiser. 
	// Tem gente que cria funções prontas para abstrair isso.
    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    printf("Data: %d/%d/%d \n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

    int dataValida=0;
    char dia[5];char mes[5];char ano[6];

    printf("Programa Testa Data\n\n");
    printf("Informe sua data de nascimento\n");
    printf("Dia: ");
    scanf("%[0-9]",dia);
    getchar();
    printf("Mês: ");
    scanf("%[0-9]",mes);
    getchar();
    printf("Ano: ");
    scanf("%[0-9]",ano);
    getchar();
    dataValida = testaData(atoi(dia),atoi(mes),atoi(ano));
    while (!dataValida) {
        printf("A data %s/%s/%s não é válida\n",dia,mes,ano);
        printf("Tente novamente!!!\n\n");
        printf("Dia: ");
        scanf("%[0-9]",dia);
        getchar();
        printf("Mês: ");
        scanf("%[0-9]",mes);
        getchar();
        printf("Ano: ");
        scanf("%[0-9]",ano);
        getchar();
        dataValida = testaData(atoi(dia),atoi(mes),atoi(ano));
    }
    printf("A data %s/%s/%s está Ok!\n",dia,mes,ano);

    system("pause");
    return 0;
}