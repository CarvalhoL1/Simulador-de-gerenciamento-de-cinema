#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "cinema.h"

int main(){
setlocale(LC_ALL, "");
int tam = 10, qtd_inteira = 0, qtd_meia = 0, escolha, continuar = 1;
float valor_inteira = 15;
char nome_arquivo[21];
Compra compras[tam*tam];
int dados[2];
inicializar_compras(compras, tam);
imprimir_menu();

while (continuar == 1){
printf("\nO que desejas fazer? (digite 7 para ver o menu de opções novamente): ");
scanf("%i", &escolha);
switch(escolha){
    case 0:
    printf("Encerrando...");
    continuar = 0;
    break;
    case 1:
    imprimir_assentos(compras, tam);
    break;
    case 2:
    if(verificar_espacos(compras, tam) == 0){
        printf("Infelizmente nao tem mais lugares disponiveis na sala prime!");
    }
    else{
        int cadeira_escolhida = selecionar_assento(compras, tam);
        if(cadeira_escolhida != -1){
        registrarcompra(compras, valor_inteira, cadeira_escolhida);}
    }
    break;
    case 3: 
    imprimir_valor(compras, tam);
    break;
    case 4:
    contabilizar_ingressos(compras, tam, &qtd_inteira, &qtd_meia);
    printf("Quantidade de ingressos meia entrada: %i\n", qtd_meia);
    printf("Quantidade de ingressos inteira: %i", qtd_inteira);
    break;
    case 5:
    contabilizar_ingressos(compras, tam, &qtd_inteira, &qtd_meia);
    dados[0] = qtd_inteira;
    dados[1] = qtd_meia;
    printf("Digite o nome do arquivo a ser criado (max 20 caracteres): ");
    scanf("%20s", nome_arquivo);
    char caminho[80];
    salvaraquivos(nome_arquivo, dados, compras, tam);
    break;
    case 6:
    printf("Digite o nome do arquivo a ser lido: ");
    scanf("%20s", nome_arquivo);
    ler_arquivo(nome_arquivo, dados, compras, tam);
    qtd_inteira = dados[0];
    qtd_meia = dados[1];
    break;
    case 7:
    imprimir_menu();
    break;
    default:
    printf("Digito invalido!");
    break;
}
}
    return 0;
}