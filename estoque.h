#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
    int dia;
    int mes;
    int ano;
}data_estoque;

typedef struct{
    char nome_produto[30];
    float preco_produto;
    float quantidade_produto;
    int id;
}produto;

typedef struct{
    data_estoque dataEstoque_venda;
    float quantidade_acai_trezentos, quantidade_acai_quinhentos;
    float valor_venda;
}venda;

typedef struct{
	int	acompanhamento_um;
	int	acompanhamento_dois;
	int	acompanhamento_tres;
	int tamanho;
}acai;

typedef struct{
    data_estoque dataEstoque_compra;
    float quantidade_add;
    float valor_unit;
}adicionados;

//protótipo das funções
void cadastra_produto();
void adicionar_no_estoque();
void vender();
void exibir_estoque();


void cadastra_produto(){
    produto *prod;
    adicionados *add;
    int adicoes_estoque=0;
    int opcao = 1;
    int quantidade_de_prod=0;
    adicoes_estoque = 0;
    FILE *arquivo_estoque;
    FILE *arquivo_compra;

    prod = (produto*)malloc((1)*sizeof(produto));
    add = (adicionados*)malloc((adicoes_estoque+1)*sizeof(adicionados));

    arquivo_estoque = fopen("estoque.txt","ab");
    arquivo_compra = fopen("compra.txt", "ab");
    while(opcao != 0){
        prod = (produto*)realloc(prod,(quantidade_de_prod+1)*sizeof(produto));
        add = (adicionados*)realloc(add,(adicoes_estoque+1)*sizeof(adicionados));
        printf("Digite o data de hoje\n");
        scanf("%d %d %d", &add[adicoes_estoque].dataEstoque_compra.dia,
              &add[adicoes_estoque].dataEstoque_compra.mes,
              &add[adicoes_estoque].dataEstoque_compra.ano);
        printf("Insira o nome do produto: \n");
        scanf("%s", prod[quantidade_de_prod].nome_produto);

        for(int j=0; j<quantidade_de_prod;j++){
            int retorno;
            retorno = strcmp(prod[j].nome_produto, prod[quantidade_de_prod].nome_produto);
            if(retorno==0){
                printf("Produto com este nome já cadastrado! Id do produto: %d", j);
                break;
            }
        }

        printf("Insira o valor unitário do produto: \n");
        scanf("%f", &prod[quantidade_de_prod].preco_produto);
        printf("Insira a quantidade do produto: (L ou Kg) \n");
        scanf("%f", &prod[quantidade_de_prod].quantidade_produto);
        prod[quantidade_de_prod].id = quantidade_de_prod;

        printf("Produto cadastrado com sucesso! \n");

        add[adicoes_estoque].valor_unit = prod[quantidade_de_prod].preco_produto;
        add[adicoes_estoque].quantidade_add = prod[quantidade_de_prod].quantidade_produto;

        printf("Digite 1 para continuar o cadastramento\n");
        printf("Digite 0 para voltar ao menu estoque\n");
        scanf("%d",&opcao);

        fwrite(&prod[quantidade_de_prod], sizeof(prod[quantidade_de_prod]), 1, arquivo_estoque);
        fwrite(&add[adicoes_estoque], sizeof(add[adicoes_estoque]), 1, arquivo_compra);
        quantidade_de_prod++;
        adicoes_estoque++;
    }
    fclose(arquivo_estoque);
    fclose(arquivo_compra);
}

void adicionar_no_estoque(){
    produto *prod;
    adicionados *add;
    int adicoes_estoque = 0;
    int opcao = 1;
    int alterar;
    int k = 0;
    float quantidade_alterar;
    prod = (produto*)malloc(sizeof(produto));

    add = (adicionados*)malloc((adicoes_estoque+1)*sizeof(adicionados));
    FILE *arquivo_compra;
    FILE *arquivo_estoque;
    arquivo_compra = fopen("compra.txt", "ab");
    arquivo_estoque = fopen("estoque.txt", "rb");

    if (arquivo_estoque == NULL){
        printf("Erro de abertura\n");
    }else{
        while (fread(&prod[k], sizeof(prod[k]), 1, arquivo_estoque) == 1) {
            prod = (produto*) realloc(prod, (k + 2) * sizeof(produto));
            k++;
        }
        fclose(arquivo_estoque);

        while(opcao != 0){
            if(arquivo_estoque == NULL){
                printf("Estoque vazio! Impossível adicionar\n");
            }else{
                add = (adicionados*)realloc(add,(adicoes_estoque+1)*sizeof(adicionados));

                exibir_estoque();

                printf("Id do produto que terá sua quantidade acrescentada: \n");
                scanf("%d", &alterar);
                printf("Quantidade a ser adicionado de %s: \n", prod[alterar].nome_produto);
                scanf("%f", &quantidade_alterar);

                prod[alterar].quantidade_produto = prod[alterar].quantidade_produto + quantidade_alterar;

                add[adicoes_estoque].valor_unit = prod[alterar].preco_produto;
                add[adicoes_estoque].quantidade_add = quantidade_alterar;

                fwrite(&add[adicoes_estoque], sizeof(add[adicoes_estoque]), 1, arquivo_compra);

                printf("Digite 1 para realizar outra adição\n");
                printf("Digite 0 para voltar ao menu estoque\n");
                scanf("%d",&opcao);

                adicoes_estoque++;
            }
        }
        fclose(arquivo_compra);
        arquivo_estoque = fopen("estoque.txt", "wb");
        for(int i = 0; i < k; i++){
            fwrite(&prod[i], sizeof(prod[i]), 1, arquivo_estoque);
        }
        fclose(arquivo_estoque);
    }
}

void vender(){
    produto *prod;
    int quantidade_de_vendas=0;
    int opcao = 1;
    int i = 0;
    int k = 0;
    venda *vende;
    acai *acai_p;


    vende = (venda*)malloc((quantidade_de_vendas+1)*sizeof(venda));
    prod = (produto*)malloc((1)*sizeof(produto));

    FILE *arquivo_venda;
    FILE *arquivo_estoque;
    arquivo_venda = fopen("venda.txt","ab");
    arquivo_estoque = fopen("estoque.txt","rb");
    if (arquivo_estoque == NULL){
        printf("Erro de abertura\n");
    }else{
        while (fread(&prod[k], sizeof(prod[k]), 1, arquivo_estoque) == 1) {
            prod = (produto*) realloc(prod, (k + 2) * sizeof(produto));
            k++;
        }

        fclose(arquivo_estoque);
        acai_p = (acai*)malloc((quantidade_de_vendas+1)*sizeof(acai));

        while(opcao!=0){
            vende = (venda*)realloc(vende,(quantidade_de_vendas+1)*sizeof(venda));
            acai_p = (acai*)realloc(acai_p,(quantidade_de_vendas+1)*sizeof(acai));
            
            printf("Digite o data de hoje\n");
            scanf("%d %d %d", &vende[quantidade_de_vendas].dataEstoque_venda.dia,
				  &vende[quantidade_de_vendas].dataEstoque_venda.mes,
                  &vende[quantidade_de_vendas].dataEstoque_venda.ano);
                  
            if(arquivo_estoque==NULL){
                printf("Estoque vazio, não há nada para vender!");
            }else{

                printf("Insira o tamanho do açaí a ser vendido: (300 ml ou 500 ml) \n");
                scanf("%d", &acai_p[quantidade_de_vendas].tamanho);
				int aux_tamanho = acai_p[quantidade_de_vendas].tamanho;
				//cardapio();
				
                if(aux_tamanho == 300){
                    for(i=0; i<1; i++){
                        printf("Selecione o primeiro acompanhamento do açaí de 300ml número %d: (pelo ID)\n", i);
                        scanf("%d", &acai_p[i].acompanhamento_um);
                        printf("Selecione o segundo acompanhamento do açaí de 300ml número %d: (pelo ID)\n", i);
                        scanf("%d", &acai_p[i].acompanhamento_dois);
                        printf("Selecione a cobertura do açaí de 300ml número %d: (pelo ID)\n", i);
                        scanf("%d", &acai_p[i].acompanhamento_tres);
                        
						prod[0].quantidade_produto = prod[0].quantidade_produto - 0.3; //subtrair acai

                        prod[acai_p[i].acompanhamento_um].quantidade_produto = prod[acai_p[i].acompanhamento_um].quantidade_produto - 0.02;
                        prod[acai_p[i].acompanhamento_dois].quantidade_produto = prod[acai_p[i].acompanhamento_dois].quantidade_produto - 0.02;
                        prod[acai_p[i].acompanhamento_tres].quantidade_produto = prod[acai_p[i].acompanhamento_tres].quantidade_produto - 0.02;

                    }
                    vende[quantidade_de_vendas].valor_venda = 8;
                }
                
                if(aux_tamanho == 500){
                    for(i=0; i<1; i++){
                        printf("Selecione o primeiro acompanhamento do açaí de 500ml número %d: (pelo ID)\n", i);
                        scanf("%d", &acai_p[i].acompanhamento_um);
                        printf("Selecione o segundo acompanhamento do açaí de 500ml número %d: (pelo ID)\n", i);
                        scanf("%d", &acai_p[i].acompanhamento_dois);
                        printf("Selecione a cobertura do açaí de 500ml número %d: (pelo ID)\n", i);
                        scanf("%d", &acai_p[i].acompanhamento_tres);

                        prod[0].quantidade_produto = prod[0].quantidade_produto - 0.5; //subtrair acai
                        
                        prod[acai_p[i].acompanhamento_um].quantidade_produto = prod[acai_p[i].acompanhamento_um].quantidade_produto - 0.02;
                        prod[acai_p[i].acompanhamento_dois].quantidade_produto = prod[acai_p[i].acompanhamento_dois].quantidade_produto - 0.02;
                        prod[acai_p[i].acompanhamento_tres].quantidade_produto = prod[acai_p[i].acompanhamento_tres].quantidade_produto - 0.02;
                    }
                    vende[quantidade_de_vendas].valor_venda = 13;
                }
                arquivo_estoque = fopen("estoque.txt","wb");
                for(i=0; i < k; i++){
                    fwrite(&prod[i], sizeof(prod[i]), 1, arquivo_estoque);
                }
                fclose(arquivo_estoque);

                fwrite(&vende[quantidade_de_vendas], sizeof(vende[quantidade_de_vendas]), 1, arquivo_venda);
				fwrite(&acai_p[quantidade_de_vendas], sizeof(acai_p[quantidade_de_vendas]), 1, arquivo_venda);
				
                printf("Digite 1 para realizar outra venda\n");
                printf("Digite 0 para voltar ao menu estoque\n");
                scanf("%d",&opcao);

                quantidade_de_vendas++ ;
            }
        }	
        fclose(arquivo_venda);
    }
}

void exibir_estoque(){
    produto *prod;
    FILE *arquivo_estoque;
    int k = 0;
    int quantidade_de_prod=0;
    int opcao = 1;
    arquivo_estoque = fopen("estoque.txt","rb");
    prod = (produto*)malloc((quantidade_de_prod+1)*sizeof(produto));

    if (arquivo_estoque == NULL){
        printf("Erro de abertura\n");
    }else{
        while (fread(&prod[k], sizeof(prod[k]), 1, arquivo_estoque) == 1) {
            prod = (produto*) realloc(prod, (k + 2) * sizeof(produto));
            k++;
        }
        fclose(arquivo_estoque);
        while (opcao != 0){
            for(int j=0; j<k; j++){
                printf("ID %d | Produto: %s | Preco unitário: %.2f | Quantidade %.4f(L ou Kg)\n",
                       j, prod[j].nome_produto, prod[j].preco_produto, prod[j].quantidade_produto);
            }
            printf("Digite 0 para voltar ao menu estoque\n");
            scanf("%d",&opcao);
        }
    }
}
