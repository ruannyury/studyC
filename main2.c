#include <stdio.h>
#include <stdlib.h>

typedef struct no{
   int valor;
   struct no *proximo;
}No;

void inserirFila(No **fila, int valor){

    No *aux, *novo = malloc(sizeof(No)); //Aloca memória pra a criação do endereço de
                                              //memória do novo nó.

    if(novo != NULL){ //Verifica se memória foi alocada corretamente: endereço é diferente de nulo
        //Cria o novo nó:
        novo -> valor = valor;
        novo -> proximo = NULL;
        if(*fila == NULL){ //Verifica se a fila está vazia, se sim basta adicionar o elemento
            *fila = novo;
        }
        else{ //Se não estiver vazia
            aux = *fila; //Se utilizar o *fila pra percorrer lista, perderemos valores
            while(aux -> proximo != NULL){ //Verifica se o próximo é diferente de Nulo
                                           //e procura até encontrar um que o próximo seja nulo
                                           //pois será o final
                aux = aux -> proximo; //É como se ele tivesse iterando num vetor, porque cada nó guarda
                                     //o próximo elemento
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
    if(*fila != NULL){ //Verificar se a fila está vazia, se não estiver, entra no loop
        remover = *fila; //Cria ponteiro para o primeiro elemento da fila
        *fila = remover -> proximo; //Faz a fila apontar pro próximo elemento, fazendo ele
                                   //virar o primeiro elemento
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
    No* noAtual = fila; //Copia a fila pra uma variável temporária
                        //pra não alterar os valores da fila original
    while(noAtual != NULL){
        if(noAtual->valor % 2 == 0){
            cont++;
        }
        noAtual = noAtual->proximo; //Itera nos nós da fila como se fosse um vetor
    }
    return cont;
}

void buscaMaiorSegMaior(No *fila, int *maior, int *segMaior){

    if (fila == NULL) {
        *maior = *segMaior = -1; // Retorna -1 se a fila estiver vazia
        return;
    }

    *maior = fila->valor;
    *segMaior = -1; // Inicializa o segundo maior como -1, caso não exista

    No* noAtual = fila; //Pega o primeiro nó da fila
    while (noAtual != NULL) {
        if (noAtual->valor > *maior) {//Verifica se o valor atual do nó atual é maior do
            //o maior conhecido

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

