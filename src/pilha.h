#ifndef PILHA_H 
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Item Item;
typedef struct Block Block;
typedef struct Pilha Pilha;

struct Item{
    int lin;
    int col;
};

struct Block{
    Item data;
    Block *prox;
};

struct Pilha{
    Block *base;
    Block *top;
};

void FPVazia(Pilha *p);
void Push(Pilha *p, Item d);
void Pop(Pilha *p);
void PImprime(Pilha *p);
void preencheMatrix();
void printMatrix();
int DFS(Pilha *p);
bool isValid(int lin, int col);
void logFila(Pilha *pilha);

#endif
