#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "cinema.h"
void inicializar_compras(Compra* compras, int tam){
    for(int i = 0; i < tam*tam; i++){
    compras[i].assento = 0;
    //o valor inicial é 0, caso uma compra vá ser feita, é alterado para o preço do ingresso
    compras[i].valor = 0;
    compras[i].entrada = -1;
    //Coloquei um nome generico para o id, o nome do filme e a categoria
    sprintf(compras[i].id, "%04d", i+1);
    strcpy(compras[i].nomefilme, "O filme");
    strcpy(compras[i].categoria, "Ação");
    }
    
}
void imprimir_valor(Compra* compra, int tam){
    float valor_arrecadado = 0;
for(int i = 0; i < tam*tam; i++){
    valor_arrecadado += compra[i].valor;
}
    printf("ate agora, arrecadamos %.2f", valor_arrecadado);
}
void registrarcompra(Compra* compras, float valor_inteira, int cadeira_escolhida){
    //se o status da entrada é 0, é meia entrada, 1 é inteira, para assento, 0 é vazio e 1 é ocupado
    if(cadeira_escolhida < 0) return;
    if(compras[cadeira_escolhida].entrada == 0){
        compras[cadeira_escolhida].valor = valor_inteira/2;
        compras[cadeira_escolhida].assento = 1;
    }
    if(compras[cadeira_escolhida].entrada == 1){
        compras[cadeira_escolhida].valor = valor_inteira;
        compras[cadeira_escolhida].assento = 1;
    }
}
void contabilizar_ingressos(Compra* compras, int tam,int* qtd_inteira, int* qtd_meia){
    *qtd_inteira = 0;
    *qtd_meia = 0;
    for(int i = 0; i < tam*tam; i++){
        if(compras[i].assento == 1){
            if(compras[i].entrada == 1){
                (*qtd_inteira)++;
            }
            else if(compras[i].entrada == 0){
                (*qtd_meia)++;
            }
        }
    }
}
int verificar_espacos(Compra* compras, int tam){
    int qtdlivres = 0;
    for(int i = 0; i < tam*tam; i++){
    if(compras[i].assento == 0){
        qtdlivres++;
    }
}
    if(qtdlivres > 0){
     return 1; 
     //ou seja, tem espaço  
    }
    else{
        return 0;
    }
}
int selecionar_assento(Compra* compras, int tam){
    int coluna_escolhida, linha_escolhida, tipoingresso, continuar;
    do{
    printf("Digite a coluna do assento escolhido: ");
    scanf("%i", &coluna_escolhida);
    printf("Digite a fileira(linha) do assento escolhido: ");
    scanf("%i", &linha_escolhida);
    if(linha_escolhida <= tam && coluna_escolhida <= tam && linha_escolhida >=1 && coluna_escolhida >= 1){
    //"formula" que converte a linha e a coluna escolhida no numero do assento (ou seja do vetor compras nesse caso)
    int cadeira_escolhida = (linha_escolhida - 1)*tam + (coluna_escolhida - 1);
    if(compras[cadeira_escolhida].assento == 0){
        printf("Perfeito! essa cadeira esta livre\n");
        printf("Digite o tipo de ingresso, 0 para meia entrada e 1 para inteira\n:");
        scanf("%i", &tipoingresso);
        if(tipoingresso == 1){
            compras[cadeira_escolhida].entrada = 1;
            printf("Perfeito, cadeira reservada com sucesso!");
            return cadeira_escolhida;
        }
        if(tipoingresso == 0){
            compras[cadeira_escolhida].entrada = 0;
            printf("Perfeito, cadeira reservada com sucesso!");
            return cadeira_escolhida;
        }
        else{
            printf("Digito invalido!");
        }
    }
    if(compras[cadeira_escolhida].assento == 1){
        printf("Cadeira ocupada, deseja escolher outra? 1 para sim, 0 para não");
        scanf("%i", &continuar);
        if(continuar == 0){
            return -1;
            break;
        }
    }}
    else{
        printf("O assento que voce escolheu nao existe! deseja escolher outro? 1 para sim, 0 para não\n: ");
        scanf("%i", &continuar);
        if(continuar == 0){
            return -1;
            break;}
    }
    
}while(1);
}
void imprimir_assentos(Compra* compras, int tam){
    char assentos[tam][tam];
    printf("\nMapa dos assentos(I para ocupado por inteira, M para ocupado por meia e # para livre): \n");
    printf("  ");
    for(int i = 0; i < tam; i++){
    printf("%i ", i + 1);
    }

    for(int i = 0; i < tam; i++){
        if(i+1 < 10){
        printf("\n%i ", i + 1);
    }
        else{
            printf("\n%i", i + 1);
        }
        for(int j = 0; j < tam; j++){
            //converte linha e coluna para um numero do assento (multiplicando por tamanho, conseguimos o numero de linhas antes do assento, somando com as colunas para adquirir o numero do assento)
            int numero_assento = i*tam + j;
            if(compras[numero_assento].assento == 0){
                assentos[i][j] = '#';
            }
            if(compras[numero_assento].assento == 1){
                if(compras[numero_assento].entrada == 1){
                assentos[i][j] = 'I';
            }
                else if(compras[numero_assento].entrada == 0){
                    assentos[i][j] = 'M';
                }
            }
            printf("%c ", assentos[i][j]);
        }
        
    }
}

void imprimir_menu(){
printf("\n 0: sair\n 1: ver mapa dos ingressos\n 2: comprar assento\n 3: ver valor arrecadado\n 4: ver a quantidade de ingressos inteira e meia entrada adquiridos ate o momento\n 5: salvar como arquivo\n 6: Abrir e registrar arquivo previamente adquirido (isso atualizara a quantidade de ingressos e assentos adquiridos até o momento)");
}

void salvaraquivos(const char *nome_arquivo, int *dados, Compra* compras, int tam){
FILE *arquivo = fopen(nome_arquivo, "w");
char assentos[tam][tam];
float valor_arrecadado = 0;
if (arquivo == NULL) {
        printf("Erro ao criar o arquivo!\n");
        return;
    }
fprintf(arquivo, "quantidade inteira: %d\n", dados[0]);
fprintf(arquivo, "quantidade meia: %d\n", dados[1]);
fprintf(arquivo, "\nMapa dos assentos(M para ocupado por meia, I para ocupado por inteira e # para livre): \n");
fprintf(arquivo, "  ");
    for(int i = 0; i < tam; i++){
    fprintf(arquivo, "%i ", i + 1);
    }

    for(int i = 0; i < tam; i++){
        if(i+1 < 10){
        fprintf(arquivo, "\n%i ", i + 1);
    }
        else{
            fprintf(arquivo, "\n%i", i + 1);
        }
        for(int j = 0; j < tam; j++){
            int numero_assento = i*tam + j;
            if(compras[numero_assento].assento == 0){
                assentos[i][j] = '#';
            }
            if(compras[numero_assento].assento == 1){
                if(compras[numero_assento].entrada == 1){
                assentos[i][j] = 'I';
            }
                else if(compras[numero_assento].entrada == 0){
                    assentos[i][j] = 'M';
                }
            }
            fprintf(arquivo, "%c ", assentos[i][j]);
        }
    }
for(int i = 0; i < tam*tam; i++){
    valor_arrecadado += compras[i].valor;
}
fprintf(arquivo, "\nValor adquirido: %.2f", valor_arrecadado);
fclose(arquivo);
printf("Arquivo salvo com sucesso!");
}
void ler_arquivo(const char *nome_arquivo, int *dados, Compra* compras, int tam){
FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo! verifique se esse é realmente o nome do arquivo\n");
        return;
    }
char linha[200];

fscanf(arquivo, "quantidade inteira: %d\n", &dados[0]);
fscanf(arquivo, "quantidade meia: %d\n", &dados[1]);
do {
    //Procura uma linha que começa com um numero(Ou seja, a linha da matriz do mapa)
        fgets(linha, sizeof(linha), arquivo);
    } while (linha[0] < '0' || linha[0] > '9');
    for(int i = 0; i < tam; i++){
        int coluna = 0;
        for(int j = 0; j < tam; j++){
            while(linha[coluna] != 'I' && linha[coluna] != 'M' && linha[coluna] != '#' && linha[coluna] != '\0'){
                coluna++;
            }
            char c = linha[coluna];
            int numero_assento = i*tam + j;
            if (c == '#') {
                compras[numero_assento].assento = 0;
                compras[numero_assento].entrada = -1;
                compras[numero_assento].valor = 0;
            }
            else if (c == 'M') {
                compras[numero_assento].assento = 1;
                compras[numero_assento].entrada = 0;
                compras[numero_assento].valor = 7.5;
            }
            else if (c == 'I') {
                compras[numero_assento].assento = 1;
                compras[numero_assento].entrada = 1;
                compras[numero_assento].valor = 15;
            }
            coluna++;
        }
        fgets(linha, sizeof(linha), arquivo);
    }
fclose(arquivo);
printf("Arquivo lido com sucesso! as informações foram atualizadas");
}   