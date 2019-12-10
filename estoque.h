#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct{
    char nome_produto[30];
    float preco_produto;
    float quantidade_produto;
}produto;

typedef struct{
    float quantidade_acai_trezentos, quantidade_acai_quinhentos;
    float valor_compra;
}venda;

typedef struct{
    int acompanhamento_um;
    int acompanhamento_dois;
    int acompanhamento_tres;
}acompanhamentos;

typedef struct{
    float quantidade_add;
    float valor_unit;
}adicionados;

//protótipo das funções
void cadastra_produto();
void adicionar_no_estoque();
void vender();
void exibir_estoque();
void cardapio();

//variáveis globais
float preco_acai_trezentos = 8;
float preco_acai_quinhentos = 13;
int adicoes_estoque=0;
int acompanhamento_um, acompanhamento_dois, acompanhamento_tres;
adicionados *add;
acompanhamentos *guarnicao;

void cadastra_produto(){
    produto *prod;
    int opcao = 1;
    int quantidade_de_prod=0;
    adicoes_estoque = 0;
    FILE *arquivo_estoque;
    prod = (produto*)malloc((1)*sizeof(produto));
    add = (adicionados*)malloc((adicoes_estoque+1)*sizeof(adicionados));
    arquivo_estoque = fopen("estoque.txt","ab");
    while(opcao != 0){
        prod = (produto*)realloc(prod,(quantidade_de_prod+1)*sizeof(produto));
        add = (adicionados*)realloc(add,(adicoes_estoque+1)*sizeof(adicionados));

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

        printf("Insira o preco do produto: \n");
        scanf("%f", &prod[quantidade_de_prod].preco_produto);
        printf("Insira a quantidade do produto: \n");
        scanf("%f", &prod[quantidade_de_prod].quantidade_produto);
        printf("Produto cadastrado com sucesso! \n");

        add[adicoes_estoque].valor_unit = prod[quantidade_de_prod].preco_produto;
        add[adicoes_estoque].quantidade_add = prod[quantidade_de_prod].quantidade_produto;

        printf("Digite 1 para continuar o cadastramento\n");
        printf("Digite 0 para voltar ao menu principal\n");
        scanf("%d",&opcao);

        fwrite(&prod[quantidade_de_prod], sizeof(prod[quantidade_de_prod]), 1, arquivo_estoque);
        quantidade_de_prod++;
        adicoes_estoque++;
    }
    if (opcao == 0){
        fclose(arquivo_estoque);
    }
}

void adicionar_no_estoque(){
    produto *prod;
    int opcao = 1;
    int alterar;
    int k = 0;
    float quantidade_alterar;
    prod = (produto *)malloc(sizeof(produto));

    add = (adicionados*)malloc((adicoes_estoque+1)*sizeof(adicionados));
    FILE *arquivo_compra;
    FILE *arquivo_estoque;
    arquivo_compra = fopen("compra.txt", "ab");
    arquivo_estoque = fopen("estoque.txt", "rb");

    if (arquivo_estoque == NULL){
        printf("erro de abertura\n");
    }else{
        while (fread(&prod[k], sizeof(prod[k]), 1, arquivo_estoque) == 1) {
            prod = (produto*) realloc(prod, (k + 2) * sizeof(produto));
            k++;
        }
        fclose(arquivo_estoque);

        while(opcao!=0){
            if(arquivo_estoque == NULL){
                printf("Estoque vazio! Impossível adicionar");
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
                printf("Digite 0 para voltar ao menu principal\n");
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
    int k;
    venda *vende;

    vende = (venda*)malloc((quantidade_de_vendas+1)*sizeof(venda));
    prod = (produto*)malloc((1)*sizeof(produto));

    FILE *arquivo_venda;
    FILE *arquivo_estoque;
    arquivo_venda = fopen("venda.txt","ab");
    arquivo_estoque = fopen("estoque.txt","rb");
    if (arquivo_estoque == NULL){
        printf("erro de abertura\n");
    }else{
        while (fread(&prod[k], sizeof(prod[k]), 1, arquivo_estoque) == 1) {
            prod = (produto*) realloc(prod, (k + 2) * sizeof(produto));
            k++;
        }

        fclose(arquivo_estoque);
        guarnicao = (acompanhamentos*)malloc((quantidade_de_vendas+1)*sizeof(acompanhamentos));

        while(opcao!=0){

            vende = (venda*)realloc(vende,(quantidade_de_vendas+1)*sizeof(venda));
            guarnicao = (acompanhamentos*)realloc(guarnicao,(quantidade_de_vendas+1)*sizeof(acompanhamentos));
            if(arquivo_estoque==NULL){
                printf("Estoque vazio, não há nada para vender!");
            }else{
                printf("Insira a quantidade de açaís de 300ml a ser vendidos: \n");
                scanf("%f", &vende[quantidade_de_vendas].quantidade_acai_trezentos);
                printf("Insira a quantidade de açaís de 500ml a ser vendidos: \n");
                scanf("%f", &vende[quantidade_de_vendas].quantidade_acai_quinhentos);

//cardapio();

                if(&vende[quantidade_de_vendas].quantidade_acai_trezentos > 0){
                    for(i = 0; i < vende[quantidade_de_vendas].quantidade_acai_trezentos; i++){
                        printf("Selecione o primeiro acompanhamento do açaí de 300ml número %d: (pelo ID)\n", i);
                        scanf("%d", &guarnicao[quantidade_de_vendas].acompanhamento_um);
                        printf("Selecione o segundo acompanhamento do açaí de 300ml número %d: (pelo ID)\n", i);
                        scanf("%d", &guarnicao[quantidade_de_vendas].acompanhamento_dois);
                        printf("Selecione a cobertura do açaí de 300ml número %d: (pelo ID)\n", i);
                        scanf("%d", &guarnicao[quantidade_de_vendas].acompanhamento_tres);

                        prod[acompanhamento_um].quantidade_produto = prod[acompanhamento_um].quantidade_produto - 1;
                        prod[acompanhamento_dois].quantidade_produto = prod[acompanhamento_dois].quantidade_produto - 1;
                        prod[acompanhamento_tres].quantidade_produto = prod[acompanhamento_tres].quantidade_produto - 1;

                    }
                }
                if(&vende[quantidade_de_vendas].quantidade_acai_quinhentos>0){
                    for(i=0; i<vende[quantidade_de_vendas].quantidade_acai_quinhentos; i++){
                        printf("Selecione o primeiro acompanhamento do açaí de 500ml número %d: (pelo ID)\n", i);
                        scanf("%d", &guarnicao[quantidade_de_vendas].acompanhamento_um);
                        printf("Selecione o segundo acompanhamento do açaí de 500ml número %d: (pelo ID)\n", i);
                        scanf("%d", &guarnicao[quantidade_de_vendas].acompanhamento_dois);
                        printf("Selecione a cobertura do açaí de 500ml número %d: (pelo ID)\n", i);
                        scanf("%d", &guarnicao[quantidade_de_vendas].acompanhamento_tres);

                        prod[acompanhamento_um].quantidade_produto = prod[acompanhamento_um].quantidade_produto - 1;
                        prod[acompanhamento_dois].quantidade_produto = prod[acompanhamento_dois].quantidade_produto - 1;
                        prod[acompanhamento_tres].quantidade_produto = prod[acompanhamento_tres].quantidade_produto - 1;
                    }
                }
                arquivo_estoque = fopen("estoque.txt","wb");
                for(i=0; i < k; i++){
                    fwrite(&prod[i], sizeof(prod[i]), 1, arquivo_estoque);
                }
                fclose(arquivo_estoque);

                vende[quantidade_de_vendas].valor_compra = (((vende[quantidade_de_vendas].quantidade_acai_trezentos) * (preco_acai_trezentos)) + ((vende[quantidade_de_vendas].quantidade_acai_quinhentos) * (preco_acai_quinhentos)));

                fwrite(&vende[quantidade_de_vendas], sizeof(vende[quantidade_de_vendas]), 1, arquivo_venda);

                printf("Digite 1 para realizar outra venda\n");
                printf("Digite 0 para voltar ao menu principal\n");
                scanf("%d",&opcao);

                quantidade_de_vendas++ ;
            }
        }
    }
}

void exibir_estoque(){
    produto *prod;
    FILE *arquivo_estoque;
    int k;
    int quantidade_de_prod=0;
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
        for(int j=0; j<k; j++){
            printf("ID %d | Produto: %s | Preco unitário: %.2f | Quantidade %.4f\n",
                   j, prod[j].nome_produto, prod[j].preco_produto, prod[j].quantidade_produto);
        }
    }
}

/*void cardapio(){
for(int j=0; j<quantidade_de_prod; j++){
printf("ID %d | Acompanhamento/Cobertura %s", j, prod[j].nome_produto);
}
}*/