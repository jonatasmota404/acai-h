//
// Created by jjuni on 28/11/2019.
//
#include <stdio.h>
#include <stdlib.h>
#include "despesas.h"
#include "estoque.h"

 void menu() {
    int opcao;
    printf("Digite 1 para cadastrar novas despesas\n");
    printf("Digite 2 para ler o arquivo das despesas\n");
    printf("Digite 3 pesquisar por nome\n");
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
             printf("operação inválida");
             break;
     }
};
    printf("****************MENU PRINCIPAL****************\n");
    printf("Selecione uma das opções a baixo:\n");
    printf("1 - cadastrar novas despesas\n");
    printf("2 - cadastrar novos produtos no estoque\n");
    scanf("%d",&opcao);
    switch(opcao){
		case 1:
			cadastra_despesa();
			break;
		case 2
			cadastra_produto();
			break;
		case 0;
			return 0;
			break;
			
    }
};
