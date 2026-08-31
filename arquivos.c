#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>

#define TOTAL_VAGAS = 20;

void registrarEntrada();
void registrarSaida();
void consultarSituacao();
void exibirFaturamento();
void consultarVeiculosEstacionados();
void consultarHistorico();
void encerrarSistema();
int contarVeiculosEstacionados();

const int totalVagas = 20;

struct Veiculo {
  char nome[50];
  char placa[8];
  char tipo[10];
  double tempoEstadia;
};

int contarVeiculosEstacionados() {

  FILE *arquivos;
  char linha[100];
  int quantidadeDEveiculos = 0;

  arquivos = fopen("arquivos/cadastro.txt", "r");

  if(arquivos == NULL) {
    printf("Erro ao encontrar esse arquivo, verifique e tente novamente! \n");
    return 0;
  }

  while(fgets(linha, sizeof(linha), arquivos) != NULL) {
    if(strstr(linha, "Nome: ") != NULL) {
        quantidadeDEveiculos++;
    }
  }

  fclose(arquivos);

  return quantidadeDEveiculos;

}

void arquivos() {

  int opcaomenu = 20;

  do {        
    system("cls");
    printf("==============================\n");
    printf("    ESTACIONAMENTO SENAI\n");
    printf("==============================\n");
    printf("1 - Registrar entrada\n");
    printf("2 - Registrar saída\n");
    printf("3 - Consultar situação\n");
    printf("4 - Exibir faturamento\n");
    printf("5 - Consultar veículos estacionados\n");
    printf("6 - Consultar histórico\n");
    printf("7 - Encerrar sistema\n");
    printf("------------------------------\n");
    printf("Escolha uma das opções acima!\n");
    printf("Opção:\n");
    scanf("%d", &opcaomenu);
    system("cls");

    switch (opcaomenu) {

    case 1:

      registrarEntrada();
      break;

    case 2:
      registrarSaida();
      break;

    case 3:
      consultarSituacao();
      break;

    case 4:
      exibirFaturamento();
      break;

    case 5:
      consultarVeiculosEstacionados();
      break;

    case 6:
      consultarHistorico();
      break;

    case 7:
      encerrarSistema();
      break;

    default:
      printf("Opção inválida, verifique e tente novamente!\n");
      break;
    }

    if(opcaomenu != 7){
    system("pause");
    }

  }while(opcaomenu != 7);
}

void registrarEntrada() {

  FILE *consulta;
  FILE *arquivos;
  FILE *historico;

  struct Veiculo veiculo;
  char linhaConsulta[100];

  int carroOUmoto = 0;  
  char continuar;

    int placaDuplicada = 0;

    system("cls");
    printf("==============================\n");
    printf("     REGISTRAR ENTRADA\n");
    printf("==============================\n");

  do{
    if(contarVeiculosEstacionados() >= totalVagas){
      printf("Estacionameto cheio! \n");
      return ;
    }

  arquivos = fopen("arquivos/cadastro.txt", "a");

  if (arquivos == NULL) {
    printf("Erro ao abrir o arquivo, verifique e tente novamente!\n");
    return;
  }

  printf("Diga o seu nome: \n");
  scanf(" %49[^\n]", veiculo.nome);
  printf("Tipo de veiculo: \n1 - Carro\n2 - Moto\n");
  printf("Opção: ");
  scanf("%d", &carroOUmoto);

  if(carroOUmoto == 1 ){
    strcpy(veiculo.tipo, "carro");
  }
  else if(carroOUmoto == 2){
    strcpy(veiculo.tipo, "moto");
  }
  else{
    printf("Opção inválida, verifique e tente novamente! \n");
    fclose(arquivos);
    continuar = 's';
    continue;
  }

  printf("Informe a placa do veiculo :\n");
  scanf("%7s", veiculo.placa);

  consulta = fopen("arquivos/cadastro.txt", "r");

  if(consulta != NULL) {
    while(fgets(linhaConsulta, sizeof(linhaConsulta), consulta) != NULL) {
      if(strstr(linhaConsulta, "Placa do veiculo: ") != NULL &&strstr(linhaConsulta, veiculo.placa) != NULL) {
        placaDuplicada = 1;
        break;
      }
    }

  fclose(consulta);

  }

  if(placaDuplicada == 1) {
    printf("ERRO: Este veiculo ja esta no estacionamento!\n");
    system("pause");
    system("cls");
    fclose(arquivos);
    continuar = 's';
    continue;
  }

  printf("Informe o tempo de estadia: \n");
  scanf("%lf", &veiculo.tempoEstadia);

  fprintf(arquivos, "Nome: %s\n", veiculo.nome);
  fprintf(arquivos, "Tipo de veiculo: %s\n", veiculo.tipo);
  fprintf(arquivos, "Placa do veiculo: %s\n", veiculo.placa);
  fprintf(arquivos, "Tempo de estadia: %.2f horas\n", veiculo.tempoEstadia);
  fprintf(arquivos, ("\n"));
  fclose(arquivos);

  historico = fopen("arquivos/historico.txt", "a");

  if(historico == NULL) {
    printf("Erro ao abrir o arquivo de historico!\n");
    return;
  }

  fprintf(historico, "ENTRADA - %s - %s\n", veiculo.placa, veiculo.tipo);
  fclose(historico);
  printf("Deseja cadastrar outro veiculo (s/n)?\n");
  scanf(" %c", &continuar);

  continuar = tolower (continuar);

    while(continuar != 's' && continuar != 'n') {
      printf("Opcao invalida, digite (s/n)!\n");
      scanf(" %c", &continuar);
      continuar = tolower(continuar);
    }

  system("cls");
             
  } while(continuar == 's');


  system("cls");
}

void registrarSaida() {

  FILE *arquivos;
  FILE *historico;
  FILE *caixa;

  struct Veiculo veiculo[totalVagas];

  char placa[8];
  char linha[100];
  char nome[50];
  char tipo[10];

  int quantidade = 0;

  system("cls");
  printf("==============================\n");
  printf("      REGISTRAR SAÍDA\n");
  printf("==============================\n");

  historico = fopen("arquivos/historico.txt", "a");

  if(historico == NULL) {
    printf("Erro ao abrir o arquivo, verifique e tente novamente!\n");
    return;
  }

  arquivos = fopen("arquivos/cadastro.txt", "r");

  if(arquivos == NULL) {
    printf("Erro ao abrir o arquivo, verifique e tente novamente!\n");
    fclose(historico);
    return;
  }

  printf("Informe a placa do veiculo:\n");
  scanf("%7s", placa);
  while(fgets(linha, sizeof(linha), arquivos) != NULL) {
    if(strstr(linha, "Nome: ") != NULL) {
      sscanf(linha, "Nome: %49[^\n]", nome);
      strcpy(veiculo[quantidade].nome, nome);
    }
    if(strstr(linha, "Tipo de veiculo: ") != NULL) {
      sscanf(linha, "Tipo de veiculo: %9[^\n]", tipo);
      strcpy(veiculo[quantidade].tipo, tipo);
    }
    if(strstr(linha, "Placa do veiculo: ") != NULL) {
      sscanf(linha, "Placa do veiculo: %7[^\n]", veiculo[quantidade].placa);
    }
    if(strstr(linha, "Tempo de estadia: ") != NULL) {
      sscanf(linha, "Tempo de estadia: %lf", &veiculo[quantidade].tempoEstadia);
      quantidade++;
    }
  }

  fclose(arquivos);

  int encontrado = -1;

  for(int i = 0; i < quantidade; i++) {
    if(strcmp(veiculo[i].placa, placa) == 0) {
      encontrado = i;
      break;
    }
  }

  if(encontrado == -1) {
    printf("Veiculo nao encontrado!\n");
    fclose(historico);
    return;
  }

  double tempoHoras = veiculo[encontrado].tempoEstadia;
  double valorPagar;

  if(strcmp(veiculo[encontrado].tipo, "carro") == 0) {
    valorPagar = tempoHoras * 10.0;
  }
  else {
    valorPagar = tempoHoras * 5.0;
  }

  printf("Veiculo encontrado! \n");
  printf("Nome: %s\n", veiculo[encontrado].nome);
  printf("Tipo de veiculo: %s\n", veiculo[encontrado].tipo);
  printf("Placa: %s\n", veiculo[encontrado].placa);
  printf("Tempo de estadia: %.2f horas\n", tempoHoras);
  printf("Valor a pagar: R$ %.2f\n", valorPagar);

  fprintf(historico, "\n");
  fprintf(historico, "SAIDA - %s - %s\n\n", veiculo[encontrado].placa, veiculo[encontrado].tipo);
  fprintf(historico, "Nome: %s\n", veiculo[encontrado].nome);
  fprintf(historico, "Tipo de veiculo: %s\n", veiculo[encontrado].tipo);
  fprintf(historico, "Placa do veiculo: %s\n", veiculo[encontrado].placa);
  fprintf(historico, "Tempo de estadia: %.2f horas\n", tempoHoras);
  fprintf(historico, "Valor a pagar: R$ %.2f\n", valorPagar);
  fprintf(historico, "\n");

  caixa = fopen("arquivos/caixa.txt", "a");

  if(caixa == NULL) {
    printf("Erro ao abrir o arquivo do caixa!\n");
    fclose(historico);
    return;
  }

  fprintf(caixa, " Placa: %s - Valor: R$ %.2f\n", veiculo[encontrado].placa, valorPagar);
  fprintf(caixa, "\n");

  fclose(caixa);
  for(int i = encontrado; i < quantidade - 1; i++) {
    veiculo[i] = veiculo[i + 1];
  }
  quantidade--;

  arquivos = fopen("arquivos/cadastro.txt", "w");

  if(arquivos == NULL) {
    printf("Erro ao atualizar o cadastro!\n");
    fclose(historico);
    return;
  }

  for(int i = 0; i < quantidade; i++) {
    fprintf(arquivos, "Nome: %s\n", veiculo[i].nome);
    fprintf(arquivos, "Tipo de veiculo: %s\n", veiculo[i].tipo);
    fprintf(arquivos, "Placa do veiculo: %s\n", veiculo[i].placa);
    fprintf(arquivos, "Tempo de estadia: %.2f horas\n", veiculo[i].tempoEstadia);
    fprintf(arquivos, "\n");
  }

  fclose(arquivos);

  fclose(historico);

  printf("\nSaida registrada com sucesso!\n");

}

void consultarSituacao() {

  FILE *arquivos;

  char linha[100];
  char tipo[10];

  int quantidadeDEveiculos = 0;
  int carros = 0;
  int motos = 0;

  double taxaOcupacao;

  system("cls");
  printf("==============================\n");
  printf("    CONSULTAR SITUAÇÃO\n");
  printf("==============================\n");

  arquivos = fopen("arquivos/cadastro.txt", "r");

  if(arquivos == NULL){
    printf("Erro ao encontrar esse arquivo. verifique e tente novamente!\n");
    return;
  }

  while(fgets(linha, sizeof(linha), arquivos) != NULL){
    if(strstr(linha, "Tipo de veiculo: ") != NULL){
      sscanf(linha, "Tipo de veiculo: %9[^\n]", tipo);
      quantidadeDEveiculos++;
    if(strcmp(tipo, "carro") == 0){
      carros++;
      }
      else if(strcmp(tipo, "moto") == 0){
        motos++;
      }
    }
  }

  fclose(arquivos);

  taxaOcupacao = ((double)quantidadeDEveiculos / totalVagas) * 100;

  printf("Vagas totais: %d\n", totalVagas);
  printf("Vagas ocupadas: %d\n", quantidadeDEveiculos);
  printf("Vagas disponiveis: %d\n", totalVagas - quantidadeDEveiculos);
  printf("Carros estacionados: %d\n", carros);
  printf("Motos estacionadas: %d\n", motos);
  printf("Taxa de ocupacao: %.0f%%\n", taxaOcupacao);
  
}

void exibirFaturamento() {

   FILE *caixa;

  double valor;
  double faturamento = 0;

  char linha[100];

  system("cls");
  printf("==============================\n");
  printf("       EXIBIR FATURAMENTO\n");
  printf("==============================\n");

  caixa = fopen("arquivos/caixa.txt", "r");

  if(caixa == NULL) {
    printf("Erro ao encontrar o arquivo do caixa!\n");
    return;
  }

  while(fgets(linha, sizeof(linha), caixa) != NULL) {
    if(sscanf(linha, " Placa: %*s - Valor: R$ %lf", &valor) == 1) {
      faturamento += valor;
    }
  }

  fclose(caixa);

  printf("Faturamento total: R$ %.2f\n", faturamento);

}

void consultarVeiculosEstacionados() {

  FILE *arquivos;

  char linha[100];

  system("cls");
  printf("==============================\n");
  printf("CONSULTAR VEÍCULOS ESTACIONADOS\n");
  printf("==============================\n");

  arquivos = fopen("arquivos/cadastro.txt", "r");

  if(arquivos == NULL) {
    printf("Erro ao encontrar esse arquivo, verifique e tente novamente!\n");
    return;
  }

  while(fgets(linha, sizeof(linha), arquivos) != NULL) {
    printf("%s", linha);
  }

  fclose(arquivos);

}

void consultarHistorico() {

  FILE *historico;

  char linha[100];

  system("cls");
  printf("==============================\n");
  printf("      CONSULTAR HISTÓRICO\n");
  printf("==============================\n");

  historico = fopen("arquivos/historico.txt", "r");

  if(historico == NULL) {
    printf("Erro ao encontrar o arquivo, verifique e tente novamente!\n");
    return;
  }

  while(fgets(linha, sizeof(linha), historico) != NULL) {
    printf("%s", linha);
  }

  fclose(historico);

}

void encerrarSistema() {

int opcao;

  system("cls");
  printf("==============================\n");
  printf("      ENCERRAR SISTEMA\n");
  printf("==============================\n");

  printf("Deseja realmente encerrar?\n");
  printf("1 - Sim\n");
  printf("2 - Não\n");
  printf("Opcao: ");
  scanf("%d", &opcao);

  if(opcao == 1){
    printf("Sistema encerrado com sucesso!\n");
  }
  else if(opcao == 2){
    printf("Retornando ao menu...\n");
  }
   else {
    printf("Opcao invalida!\n");
  }

}