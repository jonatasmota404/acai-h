//
// Created by jjuni on 08/12/2019.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int dia;
    int mes;
    int ano;
}data_funcionario;

typedef struct{
    char nome_funcionario[50];
    char cpf_funcionario[20];
    data_funcionario data;
    float salario_funcionario;
}funcionario;

void cadastro_funcionario() {
    FILE *arquivo_funcionario;
    funcionario *cadastro;
    int i = 0;
    int opcao = 1;
    cadastro = (funcionario *) malloc((i + 6) * sizeof(funcionario));
    arquivo_funcionario = fopen("funcionario.txt", "ab");
    if (arquivo_funcionario == NULL) {
        printf("erro na abertura para o cadastro\n");
    } else {
        while (opcao != 0) {
            cadastro = (funcionario *) realloc(cadastro, (i + 7) * sizeof(funcionario));
            printf("Digite o nome do funcionario:\n");
            scanf("%s", cadastro[i].nome_funcionario);
            printf("Digite o CPF do funcionario:\n");
            scanf("%s", cadastro[i].cpf_funcionario);
            printf("Digite o dia do nascimento do funcionario:\n");
            scanf("%d", &cadastro[i].data.dia);
            printf("Digite o mes do nascimento do funcionario:\n");
            scanf("%d", &cadastro[i].data.mes);
            printf("Digite o ano do nascimento do funcionario:\n");
            scanf("%d", &cadastro[i].data.ano);
            printf("Digite a pretencao salarial do funcionario:\n");
            scanf("%f", &cadastro[i].salario_funcionario);

            printf("Digite 1 para continuar o cadastramento \n");
            printf("Digite 0 para voltar ao menu principal\n");
            scanf("%d", &opcao);

            fwrite(&cadastro[i], sizeof(funcionario), 1, arquivo_funcionario);
            i++;
        }
    }
    if (opcao == 0) {
        fclose(arquivo_funcionario);
        for (int d = 0; d < i; d++) {
            printf("%s\n",cadastro[d].nome_funcionario);
            printf("%s\n",cadastro[d].cpf_funcionario);
            printf("%d / %d / %d \n",cadastro[d].data.dia,
                   cadastro[d].data.mes,cadastro[d].data.ano);
            printf("%.2f\n", cadastro[d].salario_funcionario);
        }
        printf("Cadastro do(s) funcionario(s), feito com sucesso!\n");
    }
}

void ler_arquivo_funcionario(){
    funcionario *cadastro;
    FILE *arquivo_funcionario;
    int i = 0;
    cadastro = (funcionario*)malloc(sizeof(funcionario));
    arquivo_funcionario = fopen("funcionario.txt", "rb");
    if (arquivo_funcionario == NULL){
        printf("erro de abertura, para cadastro do funcionario!\n");
    }
    else {
        while (fread(&cadastro[i], sizeof(funcionario), 1, arquivo_funcionario) == 1) {
            cadastro = (funcionario *) realloc(cadastro, (i + 7) * sizeof(funcionario));
            i++;
        }
        fclose(arquivo_funcionario);
        for (int d = 0; d < i; ++d) {
            printf("%s\n",cadastro[d].nome_funcionario);
            printf("%s\n",cadastro[d].cpf_funcionario);
            printf("%d / %d / %d \n",
                    cadastro[d].data.dia,
                   cadastro[d].data.mes,
                   cadastro[d].data.ano);
            printf("%.2f\n", cadastro[d].salario_funcionario);
        }
    }
}

void pesquisa_nome_funcionario(){
    FILE *arquivo_funcionario;
    funcionario *cadastro;
    char nome[50];
    int i = 0;
    arquivo_funcionario = fopen("funcionario.txt","rb");
    cadastro = (funcionario*)malloc(sizeof(funcionario));
    if(arquivo_funcionario == NULL){
        printf("Erro na abertura do arquivo!\n");
    }
    else {
        printf("Digite o nome do funcinario que deseja procurar:\n");
        scanf("%s",nome);
        while (fread(&cadastro[i], sizeof(funcionario),1,arquivo_funcionario) == 1){
            if (strcmp(nome, cadastro[i].nome_funcionario) == 0){
                printf("%s\n", cadastro[i].nome_funcionario);
                printf("%s\n",cadastro[i].cpf_funcionario);
                printf("%d /%d /%d\n", cadastro[i].data.dia,
                       cadastro[i].data.mes,cadastro[i].data.ano);
                printf("%.2f\n", cadastro[i].salario_funcionario);
            }
            i++;
        }
    }
    fclose(arquivo_funcionario);
}