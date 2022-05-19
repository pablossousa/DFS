#include "pilha.h"

int main() {

    FILE *arquivo;
    arquivo=fopen("Log.txt","w");
    fprintf(arquivo, "%s","Inicio:\n");
    fclose(arquivo);

    Pilha p;
    int iteracoes;

    FPVazia(&p);

    preencheMatrix();
    printMatrix();
    iteracoes=DFS(&p);
    printf("Foram necessarias %d iteracoes para chegar a essa conclusao.\n",iteracoes);
    printMatrix();

    arquivo=fopen("Log.txt","a");
    fprintf(arquivo, "%s","Fim.");
    fclose(arquivo);

    return 0;
}
