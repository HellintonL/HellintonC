#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int banco() {
  int retornoMenu = 1;
  float saldo = 0.0;
  float deposito = 0.0, saque = 0.0, rendimento = 0.0;
  int meses;

  while (retornoMenu == 1) {
    system("cls");
    printf("==============================");
    printf("      SISTEMA DE BANCO\n");
    printf("==============================");
    printf("1 - Consultar saldo\n");
    printf("2 - Depositar\n");
    printf("3 - Sacar\n");
    printf("4 - Simulação de rendimento\n");
    printf("0 - Sair\n");
    printf("Escolha uma das opções acima: ");
    scanf("%d", &retornoMenu);

    switch (retornoMenu) {

    case 0:

      printf("Fechando sistema...\n");
      retornoMenu = 0;
      break;

    case 1:

      system("cls");
      printf("==============================");
      printf("      SISTEMA DE BANCO\n");
      printf("==============================");
      printf("Seu saldo é de R$%.2f\n", saldo);
      printf("\nDigite 1 para retornar ao menu\n");
      scanf("%d", &retornoMenu);

      break;

    case 2:

      system("cls");
      printf("==============================");
      printf("       SISTEMA DE BANCO\n");
      printf("==============================");
      printf("Digite o valor que deseja depositar: ");
      scanf("%f", &deposito);
      saldo = saldo + deposito;
      printf("\nDepósito realizado com sucesso!\n");
      printf("Seu saldo atual é de R$%.2f\n", saldo);
      printf("\nDigite 1 para retornar ao menu\n");
      scanf("%d", &retornoMenu);

      break;

    case 3:

      system("cls");
      printf("==============================");
      printf("       SISTEMA DE BANCO\n");
      printf("==============================");
      printf("Digite o valor que deseja sacar: ");
      scanf("%f", &saque);
      if (saque <= saldo) {
        saldo = saldo - saque;
        printf("\nSaque realizado com sucesso!\n");
        printf("Seu saldo atual é de R$%.2f\n", saldo);
      } else {
        printf("\nSaldo insuficiente!\n");
      }
      printf("\nDigite 1 para retornar ao menu\n");
      scanf("%d", &retornoMenu);
      break;

    case 4:

      system("cls");
      printf("==============================");
      printf("      SISTEMA DE BANCO\n");
      printf("==============================");
      printf("Você escolheu simulação de rendimento.\n");
      printf("\nDigite o valor que deseja simular: ");
      scanf("%f", &rendimento);
      printf("\nDigite a quantidade de meses que deseja simular: ");
      scanf("%d", &meses);

      printf("\nVocê escolheu simular o rendimento de R$%.2f por %d meses.\n\n", rendimento, meses);

      for (int i = 0; i < meses; i++) {
        rendimento = rendimento * 1.1;
        printf("%d mês: R$%.2f\n", i + 1, rendimento);
      }

      printf("\nDigite 1 para retornar ao menu\n");
      scanf("%d", &retornoMenu);
      break;

    default:
      printf("Opção inválida!\n");
    }
  }
  return 0;
}