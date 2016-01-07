#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"
#define MAX 100
int main(void)
{
	int op, n=0, M[MAX][MAX], i, j, inicio, *v;
	opcoes();
	scanf("%d", &op);
	while(op!=0){
		system("clear");
		switch(op){
			case 1:
				printf("Digite a quantidade de vertices do grafo: ");
				scanf("%d", &n);
				for(i=0;i<n;i++)
					for(j=0;j<n;j++)
						M[i][j] = 0;
				break;
			case 2:
				insereArestas(M,n);
				break;
			case 3:
				printf("Digite o no para iniciar a busca: ");
				scanf("%d", &inicio);
				v = alocaVetor(n);
				buscaProfundidade(inicio,M,v,n);
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