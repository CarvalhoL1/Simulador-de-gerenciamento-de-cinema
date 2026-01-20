#ifndef CINEMA_H
#define CINEMA_H

typedef struct Compra{
    char nomefilme[30];
    char id[11];
    char categoria[20];
    int entrada;
    int assento;
    float valor;
}Compra;
void inicializar_compras(Compra* compras, int tam);

void imprimir_valor(Compra* compra, int tam);

void registrarcompra(Compra* compras, float valor_inteira, int cadeira_escolhida);

void contabilizar_ingressos(Compra* compras, int tam,int* qtd_inteira, int* qtd_meia);

int verificar_espacos(Compra* compras, int tam);

int selecionar_assento(Compra* compras, int tam);

void imprimir_assentos(Compra* compras, int tam);

void imprimir_menu();

void salvaraquivos(const char *nome_arquivo, int *dados, Compra* compras, int tam);

void ler_arquivo(const char *nome_arquivo, int *dados, Compra* compras, int tam);

#endif