#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
	char nome_produto[30];
	float preco_produto;
	float quantidade_produto;
}produto;

typedef struct{
	int quantidade_acai_trezentos, quantidade_acai_quinhentos;	
	float valor_compra;
}venda;

typedef struct{
	int acompanhamento_um;
	int acompanhamento_dois;
	int acompanhamento_tres;
}acompanhamentos;

typedef struct{
	char nome_despesas_estoque[50];
	float valor_despesas_estoque;
}despesas_estoque;

//protótipo das funções
void cadastra_produto();
void adicionar_no_estoque();
void vender();
void exibir_estoque();
void cardapio();

//variáveis globais
float preco_acai_trezentos = 8; 
float preco_acai_quinhentos = 13;
int quantidade_de_prod=0;
int adicoes_estoque=0;
int quantidade_de_vendas=0;
produto *prod;
despesas_estoque *produtos_add;
produtos_add = (despesas_estoque*)malloc((adicoes_estoque+1)*sizeof(despesas_estoque));

void cadastra_produto(){
	int opcao=1;
	
	prod = (produto*)malloc((quantidade_de_prod+1)*sizeof(produto));
	
	while(opcao != 0){
		prod = (produto*)realloc(prod,(quantidade_de_prod+1)*sizeof(produto));
		produtos_add = (despesas_estoque*)realloc(produtos_add,(adicoes_estoque+2)*sizeof(despesas_estoque));
		
		printf("Insira o nome do produto: \n");
		scanf("%s", prod[quantidade_de_prod].nome_produto);
		
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
		scanf("%s", produtos_add[adicoes_estoque].nome_despesa_estoque);
		
		produtos_add[adicoes_estoque].valor_despesa_estoque += prod[quantidade_de_prod].preco_produto * prod[quantidade_de_prod].quantidade_produto;
		
		
		printf("Digite 1 para continuar o cadastramento\n");
        printf("Digite 0 para voltar ao menu principal\n");
        scanf("%d",&opcao);
        
		quantidade_de_prod++;
		adicoes_estoque++;
	}
	
}

void adicionar_no_estoque(){
	int opcao=1;
	int alterar;
	float quantidade_alterar;
	
	while(opcao!=0){
		produtos_add = (despesa*)realloc,(produtos_add(adicoes_estoque+2)*sizeof(despesa));
		
		printf("Qual o id do produto que terá sua quantidade acrescentada? \n");
		scanf("%d", &alterar);
		printf("Qual a quantidade a ser adicionado de %s? \n", prod[alterar].nome_produto);
		scanf("%f", &quantidade_alterar);
		
		prod[alterar].quantidade_produto = prod[alterar].quantidade_produto + quantidade_alterar;
		
		printf("Adicione um nome a despesa da compra: \n");
		scanf("%s", produtos_add[adicoes_estoque].nome_despesa_estoque);
		produtos_add[adicoes_estoque].valor_despesa_estoque += prod[alterar].preco_produto * quantidade_alterar;
		
		printf("Produto alterado com sucesso!\n");
		
		printf("Digite 1 para realizar outra adição\n");
        printf("Digite 0 para voltar ao menu principal\n");
        scanf("%d",&opcao);	
        
        adicoes_estoque++;
	}
}

void vender(){
	int opcao=1;
	int i;
	venda *vender;
	vender = (venda*)malloc((quantidade_de_vendas+1)*sizeof(venda)); 
	
	acompanhamentos *guarnicao;
	guarnicao = (acompanhamentos*)malloc((quantidade_de_vendas+1)*sizeof(acompanhamentos));
	
	while(opcao!=0){
		vender = (venda*)realloc(vender,(quantidade_de_vendas+2)*sizeof(venda));
		guarnicao = (acompanhamentos*)realloc(guarnicao,(quantidade_de_vendas+2)*sizeof(acompanhamentos));
		
		printf("Insira a quantidade de açaís de 300ml a ser vendidos: \n");
		scanf("%d", &vender[quantidade_de_vendas].quantidade_acai_trezentos);
		printf("Insira a quantidade de açaís de 300ml a ser vendidos: \n");
		scanf("%d", &vender[quantidade_de_vendas].quantidade_acai_quinhentos);
		
		cardapio();
		
		if(&vender[quantidade_de_vendas].quantidade_acai_trezentos>0){
			for(i=0; i<vender[quantidade_de_vendas].quantidade_acai_trezentos; i++){
				printf("Selecione o primeiro acompanhamento do açaí de 300ml número %d: (pelo ID)\n", i);
				scanf("%d", &guarnicao[quantidade_de_vendas].acompanhamento_um);
				printf("Selecione o primeiro acompanhamento do açaí de 300ml número %d: (pelo ID)\n", i);
				scanf("%d", &guarnicao[quantidade_de_vendas].acompanhamento_dois);
				printf("Selecione a cobertura do açaí de 500ml número %d: (pelo ID)\n", i);
				scanf("%d", &guarnicao[quantidade_de_vendas].acompanhamento_tres);
			}
		}
		if(&vender[quantidade_de_vendas].quantidade_acai_quinhentos>0){
			for(i=0; i<vender[quantidade_de_vendas].quantidade_acai_quinhentos; i++){
				printf("Selecione o primeiro acompanhamento do açaí de 300ml número %d: (pelo ID)\n", i);
				scanf("%d", &guarnicao[quantidade_de_vendas].acompanhamento_um);
				printf("Selecione o primeiro acompanhamento do açaí de 300ml número %d: (pelo ID)\n", i);
				scanf("%d", &guarnicao[quantidade_de_vendas].acompanhamento_dois);
				printf("Selecione a cobertura do açaí de 500ml número %d: (pelo ID)\n", i);
				scanf("%d", &guarnicao[quantidade_de_vendas].acompanhamento_tres);
			}
		}
		
		vender[quantidade_de_vendas].valor_compra = (vender[quantidade_de_vendas].quantidade_acai_trezentos * vender.preco_acai_trezentos) + (vender[quantidade_de_vendas].quantidade_acai_quinhentos * vender.preco_acai_quinhentos);
		
		printf("Digite 1 para realizar outra venda\n");
        printf("Digite 0 para voltar ao menu principal\n");
        scanf("%d",&opcao);
        
        quantidade_de_vendas++;
	}
}

void exibir_estoque(){
	if(quantidade_de_prod==0){
		printf("Estoque vazio!");
	}else{
		for(int j=0; j<quantidade_de_prod; j++){
			printf("ID %d | Produto: %s | Preco unitário: %.2f | Quantidade %.4f\n", j, prod[j].nome_produto, prod[j].preco_produto, prod[j].quantidade_produto);
		}
	} 
}

void cardapio(){
	if(quantidade_de_prod==0){
		printf("Cardápio vazio!");
	}else{
		for(int i=0; i<quantidade_de_prod; i++){
			printf("ID %d | Acompanhamento: %s", i, prod[i].nome_produto);
		}
	}
}
