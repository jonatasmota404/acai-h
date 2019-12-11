//
// Created by jjuni on 10/12/2019.
//
#include <stdio.h>
#include <stdlib.h>
#include "estruturas-auxiliares-fx.h"

float ler_valor_despesa(int ler_mes_ou_dia,int dia, int mes, int ano){
    FILE *arquivo_despesa;
    despesa_fx *custo;
    float valor_despesa = 0;
    int i = 0;
    custo = (despesa_fx *)malloc(sizeof(despesa_fx));
    arquivo_despesa = fopen("despesas.txt","rb");
    while (fread(&custo[i], sizeof(custo[i]), 1, arquivo_despesa) == 1){
        custo = (despesa_fx *)realloc(custo,(i+2)* sizeof(despesa_fx));
        if (ler_mes_ou_dia == 1){
            if (mes == custo[i].vencimento.mes && ano == custo[i].vencimento.ano){
                valor_despesa = valor_despesa + custo[i].valor_despesa;
            }
        }else if (ler_mes_ou_dia == 0){
            if (dia == custo[i].vencimento.dia && mes == custo[i].vencimento.mes && ano == custo[i].vencimento.ano){
                valor_despesa = valor_despesa + custo[i].valor_despesa;
            }
        }
        i++;
    }
    fclose(arquivo_despesa);
    return valor_despesa;
}

float ler_despesa_funcionario(){
    FILE *arquivo_funcionario;
    funcionario_fx *funcionario_p;
    float valor_funcionario = 0;
    int i = 0;
    funcionario_p = (funcionario_fx *)malloc(sizeof(funcionario_fx));
    arquivo_funcionario = fopen("funcionario.txt","rb");

    while (fread(&funcionario_p[i], sizeof(funcionario_p[i]), 1, arquivo_funcionario) == 1){
        funcionario_p = (funcionario_fx *)realloc(funcionario_p,(i+2)* sizeof(funcionario_fx));
            valor_funcionario = valor_funcionario + funcionario_p[i].salario_funcionario;
        i++;
    }
    fclose(arquivo_funcionario);
    return valor_funcionario;
}

float ler_compra(int ler_mes_ou_dia,int dia, int mes, int ano){
    FILE *arquivo_compra;
    adicionados_fx *add;
    float valor_compra = 0;
    int i = 0;
    add = (adicionados_fx *)malloc(sizeof(adicionados_fx));
    arquivo_compra = fopen("compra.txt","rb");
    while (fread(&add[i], sizeof(add[i]), 1, arquivo_compra) == 1){
        add = (adicionados_fx *)realloc(add,(i+2)* sizeof(adicionados_fx));
        if (ler_mes_ou_dia == 1){
            if (mes == add[i].dataEstoque_compra.mes && ano == add[i].dataEstoque_compra.ano){
                valor_compra = valor_compra + (add[i].valor_unit*add[i].quantidade_add);
            }
        } else if (ler_mes_ou_dia == 0){
            if (dia == add[i].dataEstoque_compra.dia && mes == add[i].dataEstoque_compra.mes &&
            ano == add[i].dataEstoque_compra.ano){
                valor_compra = valor_compra + (add[i].valor_unit*add[i].quantidade_add);
            }
        }
        i++;
    }
    fclose(arquivo_compra);
    return valor_compra;
}

float ler_venda(int ler_mes_ou_dia,int dia, int mes, int ano){
    FILE *arquivo_venda;
    venda_fx *add;
    float valor_venda = 0;
    int i = 0;
    add = (venda_fx *)malloc(sizeof(venda_fx));
    arquivo_venda = fopen("venda.txt","rb");
    while (fread(&add[i], sizeof(add[i]), 1, arquivo_venda) == 1){
        add = (venda_fx *)realloc(add,(i+2)* sizeof(venda_fx));
        if (ler_mes_ou_dia == 1){
            if (mes == add[i].dataEstoque_venda.mes && ano == add[i].dataEstoque_venda.ano){
                valor_venda = valor_venda +
                        (add[i].valor_venda*(add[i].quantidade_acai_trezentos + add[i].quantidade_acai_quinhentos));
            }
        } else if (ler_mes_ou_dia == 0){
            if (dia == add[i].dataEstoque_venda.dia && mes == add[i].dataEstoque_venda.mes &&
                ano == add[i].dataEstoque_venda.ano){
                valor_venda = valor_venda +
                        (add[i].valor_venda*(add[i].quantidade_acai_trezentos + add[i].quantidade_acai_quinhentos));
            }
        }
        i++;
    }
    fclose(arquivo_venda);
    return valor_venda;
}

void fluxo_de_caixa_mes(){
    int mes,dia,ano;
    float fluxo_do_mes;
    int ler_mes_ou_dia = 1;
    printf("Digite a data de hoje\n");
    scanf("%d %d %d",&dia,&mes,&ano);
    fluxo_do_mes = (ler_venda(ler_mes_ou_dia,dia,mes,ano))-(ler_despesa_funcionario() +
            ler_valor_despesa(ler_mes_ou_dia,dia,mes,ano) + ler_compra(ler_mes_ou_dia,dia,mes,ano));
    if (fluxo_do_mes < 0){
        printf("Fluxo de caixa negativo, você possui mais despesas que receita sua divida é %.2f\n", fluxo_do_mes);
    } else if(fluxo_do_mes > 0){
        printf("Fluxo de caixa positivo seu lucro é %.2f",fluxo_do_mes);
    }
}

void fluxo_de_caixa_dia(){
    int mes,dia,ano;
    int i = 0;
    float fluxo_do_dia = 0;
    int ler_mes_ou_dia = 0;
    FILE *arquivo_funcionario;
    funcionario_fx *funcionario_p;
    funcionario_p = (funcionario_fx *)malloc(sizeof(funcionario_fx));
    arquivo_funcionario = fopen("funcionario.txt","rb");
    printf("Digite a data de hoje\n");
    scanf("%d %d %d",&dia,&mes,&ano);
    while (fread(&funcionario_p[i], sizeof(funcionario_p[i]), 1, arquivo_funcionario) == 1){
        funcionario_p = (funcionario_fx *)realloc(funcionario_p,(i+2)*sizeof(funcionario_fx));
        if (dia == funcionario_p[i].data_pagamento.dia){
            fluxo_do_dia = (ler_venda(ler_mes_ou_dia,dia,mes,ano))-(ler_despesa_funcionario() +
                    ler_valor_despesa(ler_mes_ou_dia,dia,mes,ano) + ler_compra(ler_mes_ou_dia,dia,mes,ano));
        } else {
            fluxo_do_dia = (ler_venda(ler_mes_ou_dia,dia,mes,ano))-(ler_valor_despesa(ler_mes_ou_dia,dia,mes,ano) +
                    ler_compra(ler_mes_ou_dia,dia,mes,ano));
        }
        i++;
    }
    fclose(arquivo_funcionario);
    if (fluxo_do_dia < 0){
        printf("Fluxo de caixa negativo, você possui mais despesas que receita sua divida é %.2f\n", fluxo_do_dia);
    } else if(fluxo_do_dia > 0){
        printf("Fluxo de caixa positivo seu lucro é %.2f",fluxo_do_dia);
    }
}