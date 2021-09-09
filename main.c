#include <stdio.h>
#include <stdlib.h>

typedef struct item{
    int id;
    struct item *prox;
}node;

void criaPilha(node *pilha){
    pilha->prox = NULL;
}

int vazia(node pilha){
    if(pilha.prox == NULL){
        return 1;
    }else{
        return 0;
    }
}

void push(node *pilha, int id){
    node *novo = (node*) malloc(sizeof(node));

    if(novo==NULL){
        printf("Sem memoria disponivel");
    }else{
        novo->id = id;
        novo->prox = NULL;
        if(vazia(*pilha)==1){
            pilha->prox = novo;
        }else{
            node *aux = pilha->prox;
            while(aux->prox != NULL){
                aux = aux->prox;
            }
            aux->prox = novo;
        }
    }
}

int pop(node *pilha){
    if(vazia(*pilha)==1){
        printf("A pilha esta vazia!\n");
    }else{
        node *ultimo = pilha->prox;
        node *penultimo = pilha;
        while(ultimo->prox != NULL){
            penultimo = ultimo;
            ultimo = ultimo->prox;
        }
        penultimo->prox = NULL;
        return ultimo->id;
    }
}

void imprimir(node pilha){

    if(vazia(pilha)==1){
        printf("A pilha esta vazia");
    }else{
        node *aux = pilha.prox;
        printf("Elementos da Pilha:\n");
        while(aux != NULL){
            printf("%d\n", aux->id);
            aux = aux->prox;
        }
        printf("\n");
    }
}

void inverte(node pilha){
    node pilhaAux1;
    criaPilha(&pilhaAux1);

    if(vazia(pilha)==1){
        printf("A pilha esta vazia 1\n");
    }else{
        node *aux = pilha.prox;
        while(aux != NULL){
            int invertido = pop(&pilha);
            push(&pilhaAux1, invertido);
            aux = aux->prox;
        }
    }
    printf("\n pilha\n");
    imprimir(pilha);

    printf("\n pilhaAux1\n");
    imprimir(pilhaAux1);
}

void zerar(node *pilha){
    if(vazia(*pilha)==0){
        node *prox, *atual;
        atual = pilha->prox;

        while(atual != NULL){
            prox = atual->prox;
            free(atual);
            atual = prox;
        }
        criaPilha(pilha);
    }
}

int main()
{

    node pilha;

    criaPilha(&pilha);

    push(&pilha, 1);
    push(&pilha, 2);
    push(&pilha, 3);
    push(&pilha, 4);
    push(&pilha, 5);
    push(&pilha, 6);
    push(&pilha, 7);
    imprimir(pilha);

    inverte(pilha);

    node *retirado = pop(&pilha);

    printf("Elemento retirado: %d\n\n", retirado->id);

    zerar(&pilha);

    imprimir(pilha);


    return 0;
}
