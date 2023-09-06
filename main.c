#include <stdio.h>
#include <stdlib.h>

typedef struct no{
   int valor;
   struct no *proximo;
}No;

void inserirFila(No **fila, int valor){

    No *aux, *novo = malloc(sizeof(No));

    if(novo != NULL){
        novo -> valor = valor;
        novo -> proximo = NULL;
        if(*fila == NULL){
            *fila = novo;
        }
        else{
            aux = *fila;
            while(aux -> proximo != NULL){
                aux = aux -> proximo;
            }
            aux -> proximo = novo;
        }
    }
    else{
        printf("\nErro ao alocar memória.\n");
    }
}

No* removerFila(No **fila){
    No *remover = NULL;
    if(*fila != NULL){
        remover = *fila;
        *fila = remover -> proximo;
    }
    else{
        printf("\tFila vazia.\n");
    }
    return remover;
}

void imprimir(No *fila){
    printf("\t------- FILA -------\n\t");
    while(fila != NULL){
        printf("%d ", fila->valor);
        fila = fila->proximo;
    }
    printf("\n\t------- FIm FILA -------\n");
}

int buscaPares(No *fila){
    int cont = 0;
    No* noAtual = fila;
    while(noAtual != NULL){
        if(noAtual->valor % 2 == 0){
            cont++;
        }
        noAtual = noAtual->proximo;
    }
    return cont;
}

void buscaMaiorSegMaior(No *fila, int *maior, int *segMaior){

    if (fila == NULL) {
        *maior = *segMaior = -1;
        return;
    }

    *maior = fila->valor;
    *segMaior = -1;

    No* noAtual = fila;
    while (noAtual != NULL) {
        if (noAtual->valor > *maior) {

            *segMaior = *maior;
            *maior = noAtual->valor;

        } else if (noAtual->valor > *segMaior && noAtual->valor != *maior) {

            *segMaior = noAtual->valor;

        }
        noAtual = noAtual->proximo;
    }
}

int main(){
    No *fila = NULL;

    inserirFila(&fila, 5);
    inserirFila(&fila, 6);
    inserirFila(&fila, 8);
    inserirFila(&fila, 9);
    inserirFila(&fila, 3);
    inserirFila(&fila, 1);
    inserirFila(&fila, 15);
    imprimir(fila);

    removerFila(&fila);
    imprimir(fila);

    int cont = buscaPares(fila);
    printf("\nA fila possui %d numeros pares.", cont);
    int maior = 0, segundoMaior = 0;
    buscaMaiorSegMaior(fila, &maior, &segundoMaior);
    printf("\nO maior valor da fila é %d e o segundo maior é %d", maior, segundoMaior);

}

