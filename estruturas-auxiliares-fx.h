//
// Created by jjuni on 11/12/2019.
//
typedef struct {
    int dia;
    int mes;
    int ano;
}data_despesa_fx;

typedef struct{
    data_despesa_fx vencimento;
    char nome_despesa[50];
    float valor_despesa;
}despesa_fx;

typedef struct {
    int dia;
    int mes;
    int ano;
}data_estoque_fx;

typedef struct{
    data_estoque_fx dataEstoque_venda;
    float quantidade_acai_trezentos, quantidade_acai_quinhentos;
    float valor_venda;
}venda_fx;

typedef struct{
    data_estoque_fx dataEstoque_compra;
    float quantidade_add;
    float valor_unit;
}adicionados_fx;

typedef struct {
    int dia;
    int mes;
    int ano;
}data_funcionario_fx;

typedef struct{
    char nome_funcionario[50];
    char cpf_funcionario[20];
    data_funcionario_fx data_nascimento;
    data_funcionario_fx data_pagamento;
    float salario_funcionario;
}funcionario_fx;
