#include <stdio.h>
#include <stdlib.h>
#include "despesas.h"
#include "estoque.h"
#include "funcionario.h"
#include "fluxo-de-caixa.h"
#include "estatistica.h"

void menu_despesa(){
    int opcao;
    int true = 1;
    while (true != 0){
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("****************MENU ADMINISTRAÇÃO****************\n");
    printf("Selecione uma das opções a baixo:\n");
    printf("0 - para voltar ao menu principal\n");
    printf("1 - cadastrar novas despesas\n");
    printf("2 - visualizar as despesas\n");
    printf("3 - pesquisar por nome\n");
    printf("4 - fluxo de caixa do dia\n");
    printf("5 - fluxo de caixa do mês\n");
    printf("6 - estatísticas de venda\n");
    scanf("%d",&opcao);
    switch(opcao) {
        case 0:
            true = 0;
            break;
        case 1:
            cadastra_despesa();
            break;
        case 2:
            ler_arquivo_despesa();
            break;
        case 3:
            pesquisa_nome_despesa();
            break;
        case 4:
            fluxo_de_caixa_dia();
            break;
        case 5:
            fluxo_de_caixa_mes();
            break;
        case 6:
            mais_pedidos();
            break;
        default:
            printf("opcao invalida");
            break;
        }
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    }
}

void menu_funcionario(){
    int opcao;
    int true = 1;
    while (true != 0) {
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("****************MENU FUNCIONARIOS****************\n");
    printf("Selecione uma das opções a baixo:\n");
    printf("0 - para voltar ao menu principal\n");
    printf("1 - cadastra funcionario\n");
    printf("2 - lista funcionarios\n");
    printf("3 - pesquisa o funcionario\n");
    scanf("%d",&opcao);
        switch (opcao) {
            case 0:
                true = 0;
                break;
            case 1:
                cadastro_funcionario();
                break;
            case 2:
                ler_arquivo_funcionario();
                break;
            case 3:
                pesquisa_nome_funcionario();
                break;
            default:
                printf("opcao invalida");
                break;
        }
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    }
}

 void menu_estoque(){
    int opcao;
    int true = 1;
     while (true != 0) {
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("****************MENU ESTOQUE****************\n");
    printf("Selecione uma das opções a baixo:\n");
    printf("0 - para voltar ao menu principal\n");
    printf("1 - cadastrar novos produtos no estoque\n");
    printf("2 - vender\n");
    printf("3 - adiciona estoque\n");
    printf("4 - exibe estoque\n");
    scanf("%d",&opcao);
         switch (opcao) {
             case 0:
                 true = 0;
                 break;
             case 1:
                 cadastra_produto();
                 break;
             case 2:
                 vender();
                 break;
             case 3:
                 adicionar_no_estoque();
                 break;
             case 4:
                 exibir_estoque();
                 break;
             default:
                 printf("opcao invalida");
                 break;
         }
         printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
     }
}

void menu() {
    int opcao;
    int true = 1;
    while (true != 0) {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("***************MENU PRINCIPAL***************\n");
        printf("Selecione uma das opções a baixo:\n");
        printf("0 - para sair\n");
        printf("1 - menu administração\n");
        printf("2 - menu estoque\n");
        printf("3 - menu funcionarios\n");
        scanf("%d", &opcao);
        switch (opcao) {
            case 0:
                printf("Voce saiu\n");
                true = 0;
                break;
            case 1:
                menu_despesa();
                break;
            case 2:
                menu_estoque();
                break;
            case 3:
                menu_funcionario();
                break;
            default:
                printf("opcao invalida");
                break;
        }
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    }
}
