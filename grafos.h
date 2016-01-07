#include <stdio.h>
#include <stdlib.h>
#define MAX 100

#ifndef GRAFOS_H
#define GRAFOS_H

void insereArestaDirecionada(int M[][MAX],int n);

void insereArestaNaoDirecionada(int M[][MAX],int n);

void insereArestas(int M[][MAX], int n);

void opcoes();

int *alocaVetor(int n);

void buscaProfundidade(int inicio, int M[][MAX], int *v, int n);
#endif