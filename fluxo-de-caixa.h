//
// Created by jjuni on 10/12/2019.
//
#include <stdio.h>
#include <stdlib.h>
#include "estoque.h"
#include "funcionario.h"
#include "despesas.h"

float ler_valor_despesa(int mes){
    FILE *arquivo_despesa;
    despesa *custo;
    float valor_despesa = 0;
    int i = 0;
    custo = (despesa *)malloc(sizeof(despesa));
    arquivo_despesa = fopen("despesas.txt","rb");
    while (fread(&custo[i], sizeof(custo[i]), 1, arquivo_despesa) == 1){
        if (mes == custo[i].vencimento.mes){
            valor_despesa = valor_despesa + custo[i].valor_despesa;
        }
        i++;
    }
    return valor_despesa;
}

float ler_despesa_funcionario(int mes){
    FILE *arquivo_funcionario;
    funcionario *funcionario_p;
    float valor_funcionario = 0;
    int i = 0;
    funcionario_p = (funcionario *)malloc(sizeof(funcionario));
    arquivo_funcionario = fopen("funcionario.txt","rb");
    while (fread(&funcionario_p[i], sizeof(funcionario_p[i]), 1, arquivo_funcionario) == 1){
        if (mes == funcionario_p[i].data.mes){
            valor_funcionario = valor_funcionario + funcionario_p[i].salario_funcionario;
        }
        i++;
    }
    return valor_funcionario;
}

void fluxo_de_caixa(){
    int mes;
    float fluxo_do_mes;
    printf("Digite o mês\n");
    scanf("%d",&mes);
    fluxo_do_mes = (ler_despesa_funcionario(mes) + ler_valor_despesa(mes));
}