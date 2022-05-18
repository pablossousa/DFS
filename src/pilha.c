#include "pilha.h"

void FPVazia(Pilha *p){
	p->base = (Block*) malloc (sizeof(Block));
	p->top  = p->base;
	p->base->prox = NULL;
}


void Push(Pilha *p, Item d){
	Block *aux = (Block*) malloc (sizeof(Block));
	aux->data = d;
	aux->prox = p->top;
	p->top = aux;
}


void Pop(Pilha *p, Item *d){
	Block *aux;

	if(p->base == p->top || p == NULL){
		printf("PILHA VAZIA!\n");
		return;
	}
	
	aux = p->top;
	p->top = aux->prox;
	*d = aux->data;
	free(aux);
}


void PImprime(Pilha *p){
	Block *aux;

	aux = p->top;
	while(aux != p->base){
		printf("%d\n", aux->data.val);
		aux = aux->prox;
	}

}


void printMatrix() {
	for (int i = 0; i < tamanhoMatrix; i++) {
		for (int j = 0; j < tamanhoMatrix; j++)
			printf("%d ",matrix[i][j]);
		printf("\n");
	}
}


void preencheMatrix(){
    FILE *f;
	char arquivo[80];
	char barreira[100];
	int barreirai,barreiraj;
	printf("Qual o nome do arquivo do labirinto? (Max 80)\n");
	fgets(arquivo,80,stdin);
	arquivo[strlen(arquivo)-1]='\0';
    if (!(f=fopen(arquivo,"r"))) {
        printf("Erro ao abrir arquivo.\n");
        exit(1);
    }
	fscanf(f,"%d",&tamanhoMatrix);
	fclose(f);
	matrix=(int**) malloc(sizeof(int*)*(tamanhoMatrix+1));
	for (int i = 0; i < tamanhoMatrix+1; i++) {
		matrix[i]=(int*)malloc(sizeof(int)*tamanhoMatrix);
		for (int j = 0; j < tamanhoMatrix; j++)
			matrix[i][j]=0;
	}
	f=fopen(arquivo,"r");
	fscanf(f,"%s",barreira);
	fscanf(f,"%s",barreira);
	while (!feof (f)) {
		barreirai=barreira[0]-'0';
		barreiraj=barreira[2]-'0';
		matrix[barreirai][barreiraj]=1;
		fscanf(f,"%s",barreira);
	}
	barreirai=barreira[0]-'0';
	barreiraj=barreira[2]-'0';
	matrix[barreirai][barreiraj]=1;
    fclose(f);
}

void DFS(Pilha *p) {

	Item aux;

	int tam = tamanhoMatrix;

	// for (int i = 0; i < tamanhoMatrix; i++) {
	// 	for (int j = 0; j < tamanhoMatrix; j++) {
	// 		aux.val = matrix[i][j];
	// 		Push(p, aux);
	// 	}
	// 	printf("\n");
	// }

	aux.val = matrix[0][0];
	Push(p, aux);

	for (int i = 0; i < tam; i++) {
		for (int j = 0; j < tam; j++) {
			if (matrix[j][i+1] != 1) {
				aux.val = matrix[i+1][j];
				Push(p, aux);
				matrix[i+1][j] = 2;
				i++;
			} else if (matrix[j][i+1] != 1) {
				aux.val = matrix[i+1][j];
				Push(p, aux);
				matrix[i+1][j] = 2;
				i++;
			}
		}
	}

	printf("\n");

	for (int i = 0; i < tamanhoMatrix; i++) {
		for (int j = 0; j < tamanhoMatrix; j++)
			printf("%d ",matrix[i][j]);
		printf("\n");
	}

}