#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "estruturas-auxiliares-st.h"

typedef struct{
	int conta;
	data_estoque data_estatistica;
}count;

void mais_pedidos(){
	produto_st *prod;
	acai_st *acai_p;
	count *contador;
	
	FILE *arquivo_estoque;
	FILE *arquivo_venda;
	FILE *arquivo_estatistica;
	int k=0;
	int i=0;
	int l=0;
	
	contador = (count *)malloc((1)*sizeof(count));
	prod = (produto_st*)malloc((1)*sizeof(produto_st));
	acai_p = (acai_st*)malloc((1)*sizeof(acai_st));
	
	arquivo_estoque = fopen("estoque.txt", "rb");
	arquivo_venda = fopen("venda.txt", "rb");
	arquivo_estatistica = fopen("estatistica.txt", "ab");

	if(arquivo_estoque == NULL){
		printf("ERRO!\n");
	}else{
		while(fread(&prod[l], sizeof(prod[l]), 1, arquivo_estoque) == 1){
			prod = (produto_st*) realloc(prod,(l+2) * sizeof(produto_st));
			l++;
		}
		fclose(arquivo_estoque);
		if(arquivo_venda == NULL){
		printf("Nenhuma venda realizada\n");
		}else{
			while(fread(&acai_p[k], sizeof(acai_p[k]), 1, arquivo_venda) == 1){
				acai_p = (acai_st*) realloc(acai_p,(k+2) *  sizeof(acai_st));
				k++;
			}
			fclose(arquivo_venda);
			
			for(i=0; i<k; i++){
				contador[i].conta = 0;
			}

			for(i=0; i<k; i++){
				if(acai_p[i].acompanhamento_um == i){
					contador[i].conta = contador[i].conta + 1; 
				}
				if(acai_p[i].acompanhamento_dois == i){
					contador[i].conta = contador[i].conta + 1; 
				}
				if(acai_p[i].acompanhamento_tres == i){
					contador[i].conta = contador[i].conta + 1; 
				}
			}
			for(i=0;i<k;i++){
				fwrite(&contador[i], sizeof(contador[i]), 1, arquivo_estatistica);
			}
			fclose(arquivo_estatistica);
			for(i=0;i<k;i++){
				printf("ID: %d | Produto: %s | Quantidade de vezes pedido: %d\n", i, prod[i].nome_produto, contador[i].conta);
			}
		}
	}
}
