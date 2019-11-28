//
// Created by jjuni on 20/11/2019.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome_despesa[50];
    float valor_despesa;
}despesa;

   void cadastra_despesa(){
       FILE *arquivo_despesa;
       despesa *custo;
       int i=0;
       int opcao = 1;
       custo = (despesa*)malloc((i+1)*sizeof(despesa));
       while (opcao != 0){
           custo = realloc(custo,(i+1)*sizeof(despesa));
           printf("Digite o nome da despesa\n");
           scanf("%s",custo[i].nome_despesa);
           printf("Digite o valor da despesa\n");
           scanf("%f", &custo[i].valor_despesa);
           printf("Digite 1 para continuar o cadastramento\n");
           printf("Digite 0 para voltar ao menu principal\n");
           scanf("%d",&opcao);
           i++;
           if (opcao == 0){
               arquivo_despesa = fopen("nome_despesa.txt","w");
               for (int j = 0; j < i ; j++) {
                   printf("%s\n", custo[j].nome_despesa);
                   printf("%f\n", custo[j].valor_despesa);
                   fprintf(arquivo_despesa,"%s\n",custo[j].nome_despesa);
                   fprintf(arquivo_despesa,"%f\n",custo[j].valor_despesa);
               }
           }

       }
   }
