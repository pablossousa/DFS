#include "pilha.h"

int main() {
	Pilha p;
	int iteracoes;

	FPVazia(&p);

	preencheMatrix();
	printMatrix();
	iteracoes=DFS(&p);
	printf("Foram necessarias %d iteracoes para chegar a essa conclusao.\n",iteracoes);
	printMatrix();

	return 0;
}