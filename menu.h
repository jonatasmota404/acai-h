//
// Created by jjuni on 28/11/2019.
//
#include <stdio.h>
#include <stdlib.h>
#include "despesas.h"

 void menu() {
    int opcao;
    printf("Digite 1 para cadastrar novas despesas\n");
    scanf("%d",&opcao);
     switch(opcao){
         case 1:
             cadastra_despesa();
             break;
     }
};