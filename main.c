#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void limpar_terminal() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

void criar_barra() { printf("--------------------------------\n"); }

char menu() {
  char x;
  printf("======== <<<<  \033[32mWattStatus\033[0;0m  >>>> ========\n");
  printf(
      "|  [\033[1;36m1\033[0;0m] Realizar o cálculo de gasto mensal     |\n");
  printf(
      "|  [\033[1;36m2\033[0;0m] Aba de conscientização                 |\n");
  printf(
      "|  [\033[1;36m0\033[0;0m] Sair                                   |\n");
  printf("--------------------------------\n");
  printf("\033[32mInsira a opção: \033[0;0m");
  scanf(" %c", &x);
  printf("--------------------------------\n");
  return x;
}

int calculo(int *consumo) {
  char potencia[10], horas_pordia[10], dias_mes[10];

  while (1) {
    limpar_terminal();
    printf("==== < \033[32mCálculo de gasto mensal\033[0;0m > ====\n");

    printf("Digite a potência do equipamento: ");
    scanf("%s", potencia);
    printf("Digite aproximadamente quantas horas por dia este equipamento fica "
           "ligado: ");
    scanf("%s", horas_pordia);
    printf("Digite quantos dias por mês: ");
    scanf("%s", dias_mes);
    printf("\n");

    if (strcmp(potencia, "") == 0) {
      printf("É necessário inserir a potência.\n");
      continue;
    } else if (strcmp(horas_pordia, "") == 0) {
      printf("É necessário inserir as horas por dia do aparelho.\n");
      continue;
    } else if (strcmp(dias_mes, "") == 0) {
      printf("É necessário inserir os dias no mês que o aparelho permanece "
             "ligado.\n");
      continue;
    } else {
      *consumo = atoi(potencia) * atoi(horas_pordia) * atoi(dias_mes);
      printf("==== < \033[32mResultado do gasto mensal\033[0;0m > ====\n");
      criar_barra();
      printf("O resultado do seu gasto mensal é de:\n");
      printf("\033[32mR$%d\033[0;0m\n", *consumo);
      criar_barra();
      printf("\n");
      return *consumo;
    }
  }
}

void resultado() {
  int res = 0;
  calculo(&res);
  limpar_terminal();
  printf("==== < \033[32mResultado do gasto mensal\033[0;0m > ====\n");
  criar_barra();
  printf("O resultado do seu gasto mensal é de: R$%d\n", res);
}

void aba() {
  char x;
  while (1) {
    limpar_terminal();
    printf("==== < \033[32mConscientização\033[0;0m > ====\n");
    printf("|                                                    |\n");
    printf("| Aprenda mais sobre energias renováveis             |\n");
    printf("|                                                    |\n");
    printf("| Como a energia renovável pode afetar seu dia a dia |\n");
    printf("|                                                    |\n");
    printf("|  [\033[1;36m0\033[0;0m] Voltar ao menu                           "
           "    |\n");
    printf("--------------------------------\n");
    printf("Pressione '0' para voltar: ");
    scanf(" %c", &x);

    if (x == '0') {
      limpar_terminal();
      break;
    } else {
      printf("Opção inválida! Tente novamente.\n");
    }
  }
}

int main() {
  char escolha;

  while (1) {
    escolha = menu();

    if (escolha == '1') {
      resultado();
    } else if (escolha == '2') {
      aba();
    } else if (escolha == '0') {
      printf("Programa encerrado!\n");
      break;
    } else {
      printf("Opção inválida!\n");
    }
  }

  return 0;
}
