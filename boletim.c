#include <stdio.h>
#include <stdlib.h>

int boletim() {

  char nome[50];
  char turma[50];
  float nota1, nota2, nota3, nota4, nota5;
  float media;
  float maiornota, menornota;
  int acimamedia = 0;
  int abaixomedia = 0;
  int continuar = 1;

  // Entrada de dados
  while (continuar == 1) {
    printf("Digite o nome do aluno: ");
    scanf("%s", nome);

    printf("Digite qual a sua turma: ");
    scanf("%s", turma);

    printf("Digite a primeira nota: ");
    scanf("%f", &nota1);

    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);

    printf("Digite a terceira nota: ");
    scanf("%f", &nota3);

    printf("Digite a quarta nota: ");
    scanf("%f", &nota4);

    printf("Digite a quinta nota: ");
    scanf("%f", &nota5);

    // Cálculo da média

    media = (nota1 + nota2 + nota3 + nota4 + nota5) / 5;

    // Descobrindo a maior e menor nota

    maiornota = nota1;
    menornota = nota1;

    if (nota2 > maiornota) {
      maiornota = nota2;
    }
    if (nota3 > maiornota) {
      maiornota = nota3;
    }
    if (nota4 > maiornota) {
      maiornota = nota4;
    }
    if (nota5 > maiornota) {
      maiornota = nota5;
    }
    if (nota2 < menornota) {
      menornota = nota2;
    }
    if (nota3 < menornota) {
      menornota = nota3;
    }
    if (nota4 < menornota) {
      menornota = nota4;
    }
    if (nota5 < menornota) {
      menornota = nota5;
    }

    // Limpar a Tela

    system("cls");

    // Exibição dos resultados

    printf("\n====================\n");
    printf("      BOLETIM \n");
    printf("====================\n");
    printf("Professor: Lucas Denisson da Luz\n");
    printf("Aluno: %s\n", nome);
    printf("Turma: %s\n", turma);
    printf("Notas: %.1f | %.1f | %.1f | %.1f | %.1f\n", nota1, nota2, nota3, nota4, nota5);
    printf("Média: %.2f\n", media);
    printf("Maior nota: %.1f\n", maiornota);
    printf("Menor nota: %.1f\n", menornota);

    // Mostrar as notas acima da média

    printf("Notas acima da média: ");
    if (nota1 >= 7.0) {
      printf("%.1f ", nota1);
      acimamedia++;
    }
    if (nota2 >= 7.0) {
      printf("%.1f ", nota2);
      acimamedia++;
    }
    if (nota3 >= 7.0) {
      printf("%.1f ", nota3);
      acimamedia++;
    }
    if (nota4 >= 7.0) {
      printf("%.1f ", nota4);
      acimamedia++;
    }
    if (nota5 >= 7.0) {
      printf("%.1f ", nota5);
      acimamedia++;
    }

    printf("\nQuantidade de notas acima da média: %d\n", acimamedia);

    // Notas abaixo da média

    printf("Notas abaixo da média: ");

    if (nota1 < 7.0) {
      printf("%.1f ", nota1);
      abaixomedia++;
    }
    if (nota2 < 7.0) {
      printf("%.1f ", nota2);
      abaixomedia++;
    }
    if (nota3 < 7.0) {
      printf("%.1f ", nota3);
      abaixomedia++;
    }
    if (nota4 < 7.0) {
      printf("%.1f ", nota4);
      abaixomedia++;
    }
    if (nota5 < 7.0) {
      printf("%.1f ", nota5);
      abaixomedia++;
    }

    if (abaixomedia == 0) {
      printf("Nenhuma nota abaixo da média.");
    }

    printf("\nQuantidade de notas abaixo da média: %d\n", abaixomedia);

    // Situação do aluno

    if (media >= 7.0) {
      printf("Situação: Aprovado\n");
    } else if (media >= 5.0) {
      printf("Situação: Recuperação\n");
    } else {
      printf("Situação: Reprovado\n");
    }
    printf("\nDigite 1 para gerar um novo boletim: \nDigite 2 para sair: \n");
    scanf("%d", &continuar);
  }
  // Indica término correto do programa

  return 0;
}