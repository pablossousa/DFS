#include "pilha.h"

int tamanhoMatrix;
int **matrix;

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


void Pop(Pilha *p){
    Block *aux;

    if(p->base == p->top || p == NULL){
        printf("PILHA VAZIA!\n");
        return;
    }
    
    aux = p->top;
    p->top = aux->prox;
    free(aux);
}


void PImprime(Pilha *p){
    Block *aux;

    aux = p->top;
    while(aux != p->base){
        printf("%d,%d - ", aux->data.lin, aux->data.col);
        aux = aux->prox;
    }
    printf("\n");

}


void printMatrix(){
    for (int i = 0; i < tamanhoMatrix; i++)
    {
        for (int j = 0; j < tamanhoMatrix; j++)
            printf("%d ",matrix[i][j]);
        printf("\n");
    }
}


void preencheMatrix(){
    FILE *f;
    char arquivo[80];
    int barreirai,barreiraj;
    printf("Qual o nome do arquivo do labirinto? (Max 80)\n");
    fgets(arquivo,80,stdin);
    arquivo[strlen(arquivo)-1]='\0';
    if(!(f=fopen(arquivo,"r"))){
        printf("Erro ao abrir arquivo.\n");
        exit(1);
    }
    fscanf(f,"%d",&tamanhoMatrix);
    matrix=(int**) malloc(sizeof(int*)*(tamanhoMatrix+1));
    for (int i = 0; i < tamanhoMatrix+1; i++){
        matrix[i]=(int*)malloc(sizeof(int)*tamanhoMatrix);
        for (int j = 0; j < tamanhoMatrix; j++)
            matrix[i][j]=0;
    }
    while(!feof (f)){
        fscanf(f,"%d",&barreirai);
        fgetc(f);
        fscanf(f,"%d",&barreiraj);
        matrix[barreirai][barreiraj]=1;
    }
    fclose(f);
}

void logPilha(Pilha *pilha){
    FILE *f;
    char str[500]="\0";
    char numero[7];
    f=fopen("Log.txt","a");
    Block *aux;
    aux = pilha->top;
    while(aux != pilha->base){
        sprintf(numero, "%d", aux->data.lin);
        strcat(str,numero);
        strcat(str,",");
        sprintf(numero, "%d", aux->data.col);
        strcat(str,numero);
        strcat(str," - ");
        aux = aux->prox;
    }
    strcat(str,"\n");
    fprintf(f, "%s",str);
    fclose(f);
}

int DFS(Pilha *pilha){
    int iteracoes=0;
    int posicoesLinha[4] = { 0, -1, 0, 1 };
    int posicoesColuna[4] = { -1, 0, 1, 0 };
    Item item;
    item.col=0;
    item.lin=0;
    matrix[0][0]=2;

    Push(pilha,item);

    while ((!((item.col==tamanhoMatrix-1)&&(item.lin==tamanhoMatrix-1)))&&pilha->top->prox!=NULL) {
        int x = pilha->top->data.lin;
        int y = pilha->top->data.col;
        matrix[x][y]=2;
        Pop(pilha);
 
        for (int i = 0; i < 4; i++) {
            int adjx = x + posicoesLinha[i];
            int adjy = y + posicoesColuna[i];
            if (isValid(adjx,adjy)) {
                item.lin=adjx;
                item.col=adjy;
                Push(pilha,item);
            }
        }
        iteracoes++;
        logPilha(pilha);
    }
    if (pilha->top->prox!=NULL)
        printf("Chega no final\n");
    else
        printf("Não chega no final\n");
    return iteracoes;
}

bool isValid(int lin, int col){
    if (lin < 0 || col < 0 || lin >= tamanhoMatrix || col >= tamanhoMatrix){
        return false;
    }
    else if (matrix[lin][col]==1||matrix[lin][col]==2){
        return false;
    }
    else
        return true;
}
