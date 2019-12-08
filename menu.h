#include <stdio.h>
#include <stdlib.h>
#include "despesas.h"
#include "estoque.h"

void menu_despesa(){
    int opcao;
    printf("****************MENU DESPESA****************\n");
    printf("Selecione uma das opções a baixo:\n");
    printf("1 - cadastrar novas despesas\n");
    printf("2 - visualizar as despesas\n");
    printf("3 - pesquisar por nome\n");
    scanf("%d",&opcao);
    switch(opcao){
        case 1:
            cadastra_despesa();
            break;
        case 2:
            ler_arquivo();
            break;
        case 3:
            pesquisa_nome();
            break;
        default:
            printf("opcao invalida");
            break;
    }
}

void menu_estoque(){
    int opcao;
    printf("****************MENU ESTOQUE****************\n");
    printf("Selecione uma das opções a baixo:\n");
    printf("1 - cadastrar novos produtos no estoque\n");
    scanf("%d",&opcao);
    switch(opcao){
        case 1:
            cadastra_produto();
            break;
        case 2:
            //cadastra_produto();
            break;
        default:
            printf("opcao invalida");
            break;
    }
}

void menu_compra_venda(){

}

 void menu() {
    int opcao;
    int true = 1;
    while (true != 0) {
        printf("****************MENU PRINCIPAL****************\n");
        printf("Selecione uma das opções a baixo:\n");
        printf("0 - para sair\n");
        printf("1 - para ir ao menu das despesas\n");
        printf("2 - cadastrar novos produtos no estoque\n");
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
            default:
                printf("opcao invalida");
                break;
        }
    }
}