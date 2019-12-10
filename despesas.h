#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int dia;
    int mes;
    int ano;
}data_despesa;

typedef struct{
    data_despesa vencimento;
    char nome_despesa[50];
    float valor_despesa;
}despesa;

void cadastra_despesa(){
    FILE *arquivo_despesa;
    despesa *custo;
    int i = 0;
    int opcao = 1;
    custo = (despesa*)malloc((i+2)*sizeof(despesa));
    arquivo_despesa = fopen("despesas.txt","ab");
    if(arquivo_despesa == NULL){
        printf("erro de abertura\n");
    } else {
        while (opcao != 0) {
            custo = (despesa *) realloc(custo, (i + 2) * sizeof(despesa));

            printf("Digite o nome da despesa\n");
            scanf("%s", custo[i].nome_despesa);
            printf("Digite o valor da despesa\n");
            scanf("%f", &custo[i].valor_despesa);
            printf("Digite o dia do vencimento da despesa:\n");
            scanf("%d", &custo[i].vencimento.dia);
            printf("Digite o mes do vencimento da despesa:\n");
            scanf("%d", &custo[i].vencimento.mes);
            printf("Digite o ano do vencimento da despesa:\n");
            scanf("%d", &custo[i].vencimento.ano);

            printf("Digite 1 para continuar o cadastramento\n");
            printf("Digite 0 para voltar ao menu principal\n");
            scanf("%d", &opcao);
            fwrite(&custo[i], sizeof(custo[i]), 1, arquivo_despesa);
            i++;
        }
        if (opcao == 0) {
            fclose(arquivo_despesa);
            for (int j = 0; j < i; ++j) {
                printf("%s\n", custo[j].nome_despesa);
                printf("%f\n", custo[j].valor_despesa);
                printf("%d / %d / %d \n",custo[j].vencimento.dia,
                       custo[j].vencimento.mes,custo[j].vencimento.ano);
            }
            printf("Cadastrado com sucesso\n");
        }
    }
}

void ler_arquivo_despesa(){
    despesa *custo;
    FILE *arquivo_despesa;
    int i = 0;
    custo = (despesa*)malloc(sizeof(despesa));
    arquivo_despesa = fopen("despesas.txt", "rb");
    if (arquivo_despesa == NULL){
        printf("erro de abertura\n");
    } else {
        while (fread(&custo[i], sizeof(custo[i]), 1, arquivo_despesa) == 1) {
            custo = (despesa *) realloc(custo, (i + 2) * sizeof(despesa));
            i++;
        }
        fclose(arquivo_despesa);
        for (int j = 0; j < i; ++j) {
            printf("%s\n", custo[j].nome_despesa);
            printf("%.2f\n", custo[j].valor_despesa);
            printf("%d / %d / %d \n",custo[j].vencimento.dia,
                   custo[j].vencimento.mes,custo[j].vencimento.ano);
        }
    }
}

void pesquisa_nome_despesa(){
    FILE *arquivo_despesa;
    despesa *custo;
    char nome[50];
    int i = 0;
    arquivo_despesa = fopen("despesas.txt","rb");
    custo = (despesa*)malloc(sizeof(despesa));
    if(arquivo_despesa == NULL){
        printf("erro na abertura do arquivo\n");
    } else {
        printf("Digite o nome da despesa que deseja\n");
        scanf("%s",nome);
        while (fread(&custo[i], sizeof(despesa),1,arquivo_despesa) == 1){
            if (strcmp(nome, custo[i].nome_despesa) == 0){
                printf("Nome: %s\n",custo[i].nome_despesa);
                printf("Valor: %f\n",custo[i].valor_despesa);
                printf("Vencimento: %d / %d / %d \n",custo[i].vencimento.dia,
                       custo[i].vencimento.mes,custo[i].vencimento.ano);
            }
            i++;
        }
        fclose(arquivo_despesa);
    }
}

void deleta_item() {
    FILE *arquivo_despesa;
    despesa *custo;
    char nome[50];
    int i = 0;
    int posicao_delete = 0;
    arquivo_despesa = fopen("despesas.txt", "rb");
    custo = (despesa *) malloc(sizeof(despesa));
    if (arquivo_despesa == NULL) {
        printf("erro de abertura\n");
    } else {
        printf("Digite o nome da despesa a ser deletada\n");
        scanf("%s",nome);
        while (fread(&custo[i], sizeof(custo[i]), 1, arquivo_despesa) == 1) {
            custo = (despesa *) realloc(custo, (i + 2) * sizeof(despesa));
            if (strcmp(nome, custo[i].nome_despesa) == 0){
                posicao_delete = i;
                printf("%d\n",posicao_delete);
            }
            i++;
        }
    }
    fclose(arquivo_despesa);
    arquivo_despesa = fopen("despesas.txt","wb");
    for (int j = 0; j <i ; j++) {
        if (j == posicao_delete){
            fwrite(&custo[posicao_delete + 1], sizeof(custo[posicao_delete + 1]), 1, arquivo_despesa);
            j = j + 2;
        }
        fwrite(&custo[j], sizeof(custo[j]), 1, arquivo_despesa);
    }
}