#include <stdio.h>

void erro(int codigo) {

    printf("\n");

    switch(codigo) {

        case 0:
            printf("SUCESSO - Operacao concluida.\n");
        break;

        case 100:
            printf("ERRO 100 - Nome nao informado.\n");
        break;

        case 101:
            printf("ERRO 101 - Nota invalida. Informe um valor entre 0 e 10.\n");
        break;

        case 102:
            printf("ERRO 102 - Media nao pode ser calculada.\n");
        break;

        case 200:
            printf("ERRO 200 - Divisao por zero.\n");
        break;

        case 201:
            printf("ERRO 201 - Operacao matematica invalida.\n");
        break;

        case 202:
            printf("ERRO 202 - Operador invalido.\n");
        break;

        case 404:
            printf("ERRO 404 - Atividade nao encontrada.\n");
        break;

        case 500:
            printf("ERRO 500 - Erro interno da aplicacao.\n");
        break;

        default:
            printf("ERRO DESCONHECIDO.\n");
        break;

    }

}