#include <stdio.h>
#include <stdlib.h>

#include "boletim.c"
#include "calculadora.c"
#include "banco.c"
#include "arquivos.c"
#include "erros.c"

int main(){   

    int opcao = 1;
    int erroCodigo = 0;
    
    while(opcao != 0) {

    system("cls");

    printf("=====================\n");
    printf("SISTEMA DE ATIVIDADES\n");
    printf("=====================\n");
    printf("Escolha uma das opções abaixo:\n");
    printf("1 - Boletim \n");
    printf("2 - Calculadora\n");
    printf("3 - Banco\n");
    printf("4 - Arquivos\n");
    printf("5 - Sair\n");
    scanf("%d",&opcao);

      switch(opcao) {
        

        case 1:
           erroCodigo = boletim();
        break;

        case 2:
           erroCodigo = calculadora();
        break;

        case 3:
           erroCodigo = banco();
        break;

        case 4:
           erroCodigo = arquivos();
        break;

        case 5:
            printf("finalizando Sistema...\n");
        return 0;

        default:
            erroCodigo = 404;
        break;

      }

      if(erroCodigo != 0){
        erro(erroCodigo);
      }

    }
}