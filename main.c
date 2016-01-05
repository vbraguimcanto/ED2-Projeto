#include <stdio.h>
#include <stdlib.h>
//falta inserir peso no grafo
typedef struct tipoLista{
	int chave;
	struct tipoLista *prox;
}tipoLista;
typedef struct tabelaHash{
	int indice;
	tipoLista *primeiro;
}tabelaHash;
void buscaProfundidade(tabelaHash *p, int n){
	int origem, *v, *pilha, i, cont=0, cmp;
	tipoLista *aux;
	printf("Digite o no origem: ");
	scanf("%d", &origem);
	v = (int *)(malloc(sizeof(int)*n));
	pilha = (int *)(malloc(sizeof(int)*n));
	for(i=0;i<n;i++)
		v[i] = 0;
	while(cont<n){
		if(v[origem]==0){
			v[origem] = 1;
			pilha[cont] = origem;
			cont++;
		}
		else{
			aux = p[origem].primeiro;
			while(aux!=NULL){
				cmp = (aux->chave);
				if(v[cmp]==0){
					origem = cmp;
					break;
				}
				aux = aux->prox;
			}
		}
	}
	for(i=cont-1;i>-1;i--)
		printf("%d ", pilha[i]);
	printf("\n");
}


void insereArestaDirecionada(tabelaHash *p, int n){
	int origem, destino;
	tipoLista *aux;
	printf("Utilize a forma numpilhaertice_origem numVertice_destino\n");
	printf("Atencao, -1 -1 termina a insercao!\n");
	printf("Digite: ");
	scanf("%d %d", &origem, &destino);
	while(origem!=-1 && destino!=-1){
		if((p[origem].primeiro)==NULL){
			(p[origem].primeiro) = (tipoLista *)(malloc(sizeof(tipoLista)));
			((p[origem].primeiro)->chave) = destino;
			((p[origem].primeiro)->prox) = NULL;
		}
		else{
			aux = p[origem].primeiro;
			p[origem].primeiro = (tipoLista *)(malloc(sizeof(tipoLista)));
			((p[origem].primeiro)->chave) = destino;
			((p[origem].primeiro)->prox) = aux;
		}
		printf("Digite: ");
		scanf("%d %d", &origem, &destino);
	}
}
void insereArestaNaoDirecionada(tabelaHash *p, int n){
	int origem, destino;
	tipoLista *aux;
	printf("Utilize a forma numVertice_origem numVertice_destino\n");
	printf("Atencao, -1 -1 termina a insercao!\n");
	printf("Digite: ");
	scanf("%d %d", &origem, &destino);
	while(origem!=-1 && destino!=-1){
		if((p[origem].primeiro)==NULL){
			(p[origem].primeiro) = (tipoLista *)(malloc(sizeof(tipoLista)));
			((p[origem].primeiro)->chave) = destino;
			((p[origem].primeiro)->prox) = NULL;
		}
		else{
			aux = p[origem].primeiro;
			p[origem].primeiro = (tipoLista *)(malloc(sizeof(tipoLista)));
			((p[origem].primeiro)->chave) = destino;
			((p[origem].primeiro)->prox) = aux;
		}
		if((p[destino].primeiro)==NULL){
			(p[destino].primeiro) = (tipoLista *)(malloc(sizeof(tipoLista)));
			((p[destino].primeiro)->chave) = origem;
			((p[destino].primeiro)->prox) = NULL;
		}
		else{
			aux = p[destino].primeiro;
			p[destino].primeiro = (tipoLista *)(malloc(sizeof(tipoLista)));
			((p[destino].primeiro)->chave) = origem;
			((p[destino].primeiro)->prox) = aux;
		}
		printf("Digite: ");
		scanf("%d %d", &origem, &destino);
	}
}
void insereArestas(tabelaHash *p, int n){
	char op[1];
	int dir;
	if(n==0 || p==NULL){
		printf("Ooops! Crie primeiro as arestas!\n");
		return;
	}
	printf("Grafo direcionado(s/n)? ");
	scanf("%s", op);
	if(op[0]=='s')
		insereArestaDirecionada(p,n);
	else
		insereArestaNaoDirecionada(p,n);
}
tabelaHash *insereVertices(int n){
	int i;
	tabelaHash *p;
	p = (tabelaHash *)(malloc(sizeof(tabelaHash)*n));
	if(p==NULL){
		printf("Oops! Falha na alocacao!\n");
		return;
	}
	for(i=0;i<n;i++){
		p[i].indice = i;
		p[i].primeiro = NULL;
	}
	return p;
}

void opcoes(){
	printf("------------------------------------------------\n");
	printf("Projeto da Disciplina de Estrutura de Dados 2\n");
	printf("Universidade Estadual Paulista - UNESP\n");
	printf("------------------------------------------------\n");
	printf("Escolha uma opcao:\n");
	printf("(1) \tInserir Vertices\n");
	printf("(2) \tInserir Arestas\n");
	printf("(3) \tBusca em Profundidade\n");
	printf("(4) \tOrdenacao Topologica\n");
	printf("(5) \tAlgoritmo de Dijkstra\n");
	printf("(0) \tSair\n");
	printf("------------------------------------------------\n");
	printf("Digite a opcao: ");
}
int main(void)
{
	int op, n=0;
	tabelaHash *p;
	opcoes();
	scanf("%d", &op);
	while(op!=0){
		system("clear");
		switch(op){
			case 1:
				printf("Digite a quantidade de vertices do grafo: ");
				scanf("%d", &n); 
				p = insereVertices(n);
				break;
			case 2:
				insereArestas(p,n);
				break;
			case 3:
				buscaProfundidade(p,n);
				break;
			case 4:
				//ordenacaoTopologica();
				break;
			case 5:
				//algoritmoDijkstra();
				break;
			default:
				printf("OOPs! Opcao Invalida!\n\n\n");
				break;

		}
		opcoes();
		scanf("%d", &op);
	}
	return 0;
}