#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
	char nome_produto[30];
	float preco_produto;
	float quantidade_produto;
}produto;

int quantidade_de_prod = 0;
produto *prod;

void cadastra_produto(){
	int opcao = 1;
	int id_prod;
	
	prod = (produto*)malloc((quantidade_de_prod+1)*sizeof(produto));
	
	while(opcao != 0){
		prod = (produto*)realloc(prod,(quantidade_de_prod+1)*sizeof(produto));
		
		printf("Insira o nome do produto: \n");
		scanf("%s", prod[quantidade_de_prod].nome_produto);
		
		for(int j=0; j < id_prod; j++){
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
		
		printf("Digite 1 para continuar o cadastramento\n");
        printf("Digite 0 para voltar ao menu principal\n");
        scanf("%d",&opcao);
        
		id_prod++;
	}
	
}

void exibir_estoque(){
    int id_prod;
	if(quantidade_de_prod==0){
		printf("Estoque vazio!");
	}else{
		for(int j=0; j < id_prod; j++){
			printf("ID %d | Produto: %s | Preco: %.2f | Quantidade %.4f\n", j, prod[j].nome_produto, prod[j].preco_produto, prod[j].quantidade_produto);
		}
	} 
}
