#include <stdio.h>
#include <stdlib.h>

int calculadora() {

  char operador;
  float numero1;
  float numero2;
  float resultado;
  int modo;
  int continuar = 1;

  while(continuar == 1){  

    system("cls");
    printf("====================\n");
    printf("        MENU\n");
    printf("====================\n");
    printf("1 - Calculadora Normal\n");
    printf("2 - Calculadora Direta\n");
    printf("3 - Sair\n");

    printf("Opcao: ");
    scanf("%d", &modo);

    system("cls");

    //O switch modo apenas coleta os dados, ainda por sí não realiza nenhum cálculo.
    switch (modo){

    case 1:

      printf("====================\n");
      printf(" CALCULADORA NORMAL\n");
      printf("====================\n");

      printf("Digite o primeiro numero: ");
      scanf("%f", &numero1);

      printf("Escolha uma operacao:\n");
      printf("Soma           +\n");
      printf("Subtracao      -\n");
      printf("Multiplicacao  *\n");
      printf("Divisao        /\n");
      printf("Opcao: ");

      //O espaço%c evita com que o Enter seja lido como operador, então sem esse espaço o programa confunde esse espaço com o operador e gera um erro de operador invalido.
      scanf(" %c", &operador);

      printf("Digite o segundo numero: ");
      scanf("%f", &numero2);

      //Aqui depois de coletar os dados, ele para o caso atual e vai para o próximo switch..
      break;

    case 2:

      printf("====================\n");
      printf(" CALCULADORA DIRETA\n");
      printf("====================\n");

      printf("Digite a operacao (Ex: 9 + 9): ");

      //esse scanf lê tudo de uma vez um número, um operador e outro número, assim armazenando os dados.
      scanf("%f %c %f", &numero1, &operador, &numero2);

      break;

      case 3:
      printf("Encerrando a calculadora...\n");
      return 0;

      //Se não for nenhuma das opções, ele retorna um erro e continua o Loop, voltando para o menu.
      default:
      printf("ERRO 202! Verifique a operação e tente novamente.\n");

      //Ele vai pular direto para a próxima interação do laço, voltando para o menu.
      continue;
    }

    //Ele olha qual operador o usuário digitou e vai realizar o cálculo correspodente.
    switch (operador) {
    case '+':
      resultado = numero1 + numero2;
      break;

    case '-':
      resultado = numero1 - numero2;
      break;

    case '*':
      resultado = numero1 * numero2;
      break;

    case '/':
      if (numero2 == 0) {
    
      printf("ERRO 200! Não é possível dividir por zero.\n");
      
      
      //Vai mostrar a mensagem de erro e o (continue) vai fazer com que ele pule e vá direto para a próxima interação do Loop.
      system("pause");

      //Vai mostrar a mensagem de erro e o (continue) vai fazer com que ele pule e vá direto para a próxima interação do loop, voltamndo ao menu.
      continue;
      }

      resultado = numero1 / numero2;
      
      //Ele para o caso atual e sai do switch, indo para a próxima parte do código, imprimindo o resultado e perguntando se o usuário deseja continuar.
      break;
      
      //Ele pega qualquer operador que não seja +, -, * ou / e retorna um erro, voltando ao menu.
      default:
      printf("ERRO 201! Operador invalido, verifique e tente novamente.\n");

      //Vai garantir que o programa volte para o menu.
      continue;

    }

  printf("\nResultado: %.2f\n", resultado);
  printf("\nDigite 1 para realizar outra operação\n");
  printf("Digite 2 para sair\n");
  printf("Opção: ");
  scanf("%d", &continuar);

  }
    return 0;
}