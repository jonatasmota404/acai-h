#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "despesas.h"

typedef struct{
	char nome_produto[30];
	float preco_produto;
	float quantidade_produto;
}produto;

typedef struct{
	int quantidade_acai_trezentos, quantidade_acai_quinhentos;	
	float valor_compra;
}venda;

float preco_acai_trezentos = 8; 
float preco_acai_quinhentos = 13;
int quantidade_de_prod=0;
int adicoes_estoque=0;
produto *prod;
despesa *produtos_add;
produtos_add = (despesa*)malloc((adicoes_estoque+1)*sizeof(despesa));

void cadastra_produto(){
	int opcao=0;
	
	prod = (produto*)malloc((quantidade_de_prod+1)*sizeof(produto));
	
	while(opcao != 0){
		prod = (produto*)realloc(prod(quantidade_de_prod+1)*sizeof(produto));
		produtos_add = (despesa*)realloc(produtos_add(adicoes_estoque+2)*sizeof(despesa));
		
		printf("Insira o nome do produto: \n");
		scanf("%c", &prod[quantidade_de_prod].nome_produto);
		
		for(int j=0; j<quantidade_de_prod; j++){
			if(prod[quantidade_de_prod].nome_produto == prod[j].nome_produto){
				printf("Produto com este nome já cadastrado! Id do produto: %d", j);
				break;
			}
		}
		
		printf("Insira o preco do produto: \n");
		scanf("%f", &prod[quantidade_de_prod].preco_produto);
		printf("Insira a quantidade do produto: \n");
		scanf("%f", &prod[quantidade_de_prod].quantidade_produto);
		printf("Produto cadastrado com sucesso!");
		
		printf("Agora registre a despesa. Insira o nome da despesa: ");
		scanf("%s", &produtos_add[adicoes_estoque].nome_despesa);
		
		produtos_add[adicoes_estoque].valor_despesa += prod[quantidade_de_prod].preco_produto * prod[quantidade_de_prod].quantidade_produto;
		
		
		printf("Digite 1 para continuar o cadastramento\n");
        printf("Digite 0 para voltar ao menu principal\n");
        scanf("%d",&opcao);
        
		quantidade_de_prod++;
		adicoes_estoque++;
	}
	
}

void adicionar_no_estoque(){
	int opcao=0;
	int alterar;
	float quantidade_alterar;
	
	while(opcao!=0){
		produtos_add = (despesa*)realloc(produtos_add(adicoes_estoque+2)*sizeof(despesa));
		
		printf("Qual o id do produto que terá sua quantidade acrescentada? \n");
		scanf("%d", &alterar);
		printf("Qual a quantidade a ser adicionado de %s? \n", prod[alterar].nome_produto);
		scanf("%f", &quantidade_alterar);
		
		prod[alterar-1].quantidade_produto = prod[alterar-1].quantidade_produto + quantidade_alterar;
		
		printf("Adicione um nome a despesa da compra: \n");
		scanf("%s", &produtos_add[adicoes_estoque].nome_despesa);
		produtos_add[adicoes_estoque].valor_despesa += prod[alterar-1].preco_produto * quantidade_alterar;
		
		printf("Produto alterado com sucesso!\n");
		
		printf("Digite 1 para realizar outra adição\n");
        printf("Digite 0 para voltar ao menu principal\n");
        scanf("%d",&opcao);	
        
        adicoes_estoque++;
	}
}

void vender(){
	
}

void exibir_estoque(){
	if(quantidade_de_prod==0){
		printf("Estoque vazio!");
	}else{
		for(int j=0; j<id_prod; j++){
			printf("ID %d | Produto: %c | Preco unitário: %.2f | Quantidade %.4f\n", j+1, prod[j].nome_produto, prod[j].preco_produto, prod[j].quantidade_produto);
		}
	} 
}
