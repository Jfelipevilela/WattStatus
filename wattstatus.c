#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para armazenar dados dos equipamentos
typedef struct Equipamento {
  int potencia;
  int horas_pordia;
  int dias_mes;
  int consumo;
  struct Equipamento *prev;
  struct Equipamento *next;
} Equipamento;

typedef struct {
  Equipamento *head;
  Equipamento *tail;
} ListaEquipamentos;

void inicializar_lista(ListaEquipamentos *lista) {
  lista->head = NULL;
  lista->tail = NULL;
}

void adicionar_equipamento(ListaEquipamentos *lista, int potencia, int horas,
                           int dias, int consumo) {
  Equipamento *novo = (Equipamento *)malloc(sizeof(Equipamento));
  novo->potencia = potencia;
  novo->horas_pordia = horas;
  novo->dias_mes = dias;
  novo->consumo = consumo;
  novo->prev = lista->tail;
  novo->next = NULL;

  if (lista->tail) {
    lista->tail->next = novo;
  } else {
    lista->head = novo;
  }
  lista->tail = novo;
}

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
      "|  [\033[1;36m3\033[0;0m] Exibir histórico de consumo            |\n");
  printf(
      "|  [\033[1;36m0\033[0;0m] Sair                                   |\n");
  printf("--------------------------------\n");
  printf("\033[32mInsira a opção: \033[0;0m");
  scanf(" %c", &x);
  printf("--------------------------------\n");
  return x;
}

int calculo(ListaEquipamentos *lista) {
  int potencia, horas_pordia, dias_mes, consumo;

  limpar_terminal();
  printf("==== < \033[32mCálculo de gasto mensal\033[0;0m > ====\n");
  printf("Digite a potência do equipamento (em watts): ");
  scanf("%d", &potencia);
  printf("Digite quantas horas por dia o equipamento fica ligado: ");
  scanf("%d", &horas_pordia);
  printf("Digite quantos dias por mês: ");
  scanf("%d", &dias_mes);

  consumo = potencia * horas_pordia * dias_mes;
  adicionar_equipamento(lista, potencia, horas_pordia, dias_mes, consumo);

  printf("==== < \033[32mResultado do gasto mensal\033[0;0m > ====\n");
  criar_barra();
  printf("O consumo mensal estimado é: \033[32m%d\033[0;0m kWh\n", consumo);
  criar_barra();

  return consumo;
}

void exibir_historico(ListaEquipamentos *lista) {
  limpar_terminal();
  printf("==== < \033[32mHistórico de Consumo\033[0;0m > ====\n");
  criar_barra();

  Equipamento *atual = lista->head;
  int i = 1;
  while (atual) {
    printf("Equipamento %d:\n", i);
    printf("Potência: %d W, Horas por dia: %d, Dias no mês: %d\n",
           atual->potencia, atual->horas_pordia, atual->dias_mes);
    printf("Consumo mensal: %d kWh\n", atual->consumo);
    criar_barra();
    atual = atual->next;
    i++;
  }

  if (lista->head == NULL) {
    printf("Nenhum histórico disponível.\n");
  }
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
           "|\n");
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

void liberar_lista(ListaEquipamentos *lista) {
  Equipamento *atual = lista->head;
  while (atual != NULL) {
    Equipamento *proximo = atual->next;
    free(atual);
    atual = proximo;
  }
  lista->head = NULL;
  lista->tail = NULL;
}

int main() {
  char escolha;
  ListaEquipamentos lista;
  inicializar_lista(&lista);

  while (1) {
    escolha = menu();

    if (escolha == '1') {
      calculo(&lista);
    } else if (escolha == '2') {
      aba();
    } else if (escolha == '3') {
      exibir_historico(&lista);
    } else if (escolha == '0') {
      printf("Programa encerrado!\n");
      break;
    } else {
      printf("Opção inválida!\n");
    }
  }

  liberar_lista(&lista);
  return 0;
}
