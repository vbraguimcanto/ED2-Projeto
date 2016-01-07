#include <stdio.h>
#include <stdlib.h>
#define MAX 100
void algoritmoDijkstra(int origem, int destino, int M[][MAX], int n, int *v, int *min, int *via){
	int i, k, minimo, dist, cost;
	k = origem;
    minimo = 0;
    while(v[destino] != 2){
	    v[k] = 2;
	    for(i=0;i<n;i++){
	        if(M[k][i] && v[i] != 2){
	            dist = minimo + M[k][i];
	            if(dist < min[i]){
	                min[i] = dist;
	                via[i] = k;
	            }
	            v[i] = 1;
	        }
    }
    minimo = 99999;
    for(i=0;i<n;i++)
        if(v[i] == 1 && min[i] < minimo){
            minimo = min[i];
            k = i;
        }
    }
    printf("O menor caminho entre %d e %d: %d\n", origem, destino, min[destino]);
}



int *alocaVetor(int n){
	return (int *)(malloc(sizeof(int)*n));
}
void buscaProfundidade(int inicio, int M[][MAX], int *v, int n)
{
    int j, i=inicio;
    printf("%d\n", i);
    v[i]=1;
    for(j=0;j<n;j++)
       if(v[j]==0 && M[i][j]==1)
            buscaProfundidade(j,M,v,n);
}
void insereArestaDirecionada(int M[][MAX],int n){
	char op[1];
	int origem, destino, peso;
	printf("Grafo ponderado?\n");
	printf("(s/n): ");
	scanf("%s", op);
	if(op[0]=='n' || op[0]=='N'){
		printf("Insira as arestas:\nEx.: origem destino\n");
		printf("Obs.: -1 -1 termina a insercao!\n");
		printf("Digite: ");
		scanf("%d %d", &origem, &destino);
		while(origem!=-1 && destino!=-1){
			M[origem][destino] = 1;
			printf("Digite: ");
			scanf("%d %d", &origem, &destino);
		}
	}
	else{
		printf("Insira as arestas:\nEx.: origem destino peso\n");
		printf("Obs.: -1 -1 termina a insercao!\n");
		printf("Digite: ");
		scanf("%d %d %d", &origem, &destino, &peso);
		while(origem!=-1 && destino!=-1){
			M[origem][destino] = peso;
			printf("Digite: ");
			scanf("%d %d %d", &origem, &destino, &peso);
		}
	}
}

void insereArestaNaoDirecionada(int M[][MAX],int n){
	char op[1];
	int origem, destino, peso;
	printf("Grafo ponderado?\n");
	printf("(s/n): ");
	scanf("%s", op);
	if(op[0]=='n' || op[0]=='N'){
		printf("Insira as arestas:\nEx.: origem destino\n");
		printf("Obs.: -1 -1 termina a insercao!\n");
		printf("Digite: ");
		scanf("%d %d", &origem, &destino);
		while(origem!=-1 && destino!=-1){
			M[origem][destino] = 1;
			M[destino][origem] = 1;
			printf("Digite: ");
			scanf("%d %d", &origem, &destino);
		}
	}
	else{
		printf("Insira as arestas:\nEx.: origem destino peso\n");
		printf("Obs.: -1 -1 termina a insercao!\n");
		printf("Digite: ");
		scanf("%d %d %d", &origem, &destino, &peso);
		while(origem!=-1 && destino!=-1){
			M[origem][destino] = peso;
			M[destino][origem] = peso;
			printf("Digite: ");
			scanf("%d %d %d", &origem, &destino, &peso);
		}
	}
}

void insereArestas(int M[][MAX], int n){
	char op[1];
	printf("Grafo direcionado?\n");
	printf("(s/n): ");
	scanf("%s", op);
	if(op[0]=='s' || op[0]=='S')
		insereArestaDirecionada(M,n);
	else
		insereArestaNaoDirecionada(M,n);
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