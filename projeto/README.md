# Este projeto serve apenas de exemplo:  
- Foi desenvolvidos com sugestões de alunos para ajuda no desenvolvimento dos projetos deles;
- Portanto voçê pode encontrar codigo  com funcionalidade diversificada que não se encaixa em um sistema de estoque por exemplo;
## Sobre o projeto
* Utiliza Linguagem C;
* Para compilar Precisa do GCC;
* Desenvolvido Utilizando Ubuntu ou seja Distro Linux, pode ter funções não reconhecidas no windows;

## Como compilar
* Compilando arquivos 1 a 1:
    ```
        gcc -c nomeArquivo1.c
        gcc -c nomeArquivo2.c
        ...
        gcc -o meuProjeto nomeArquivo1.o nomeArquivo2.o ...

    ```
* Compilando todos de uma vez e transformando os .o no projeto direto:
    ```
        gcc -o projeto main.c moduloEntrada.c moduloProdutos.c moduloRelatorios.c moduloSaida.c moduloSobre.c
    ```
* executando:
    ```
        ./projeto
    ```