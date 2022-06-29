#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "inserir.h"

void testes();

int main(){
    testes();

    return 0;
}


void testes()
{
    int i;
    int list[] = { 11, 2, 14, 1, 7, 15, 5, 8, 4};
    
    No *externo = noExterno();

    ptRaiz = (No**)malloc(sizeof(No*) * sizeof(list));    
    ptRaiz[0] = externo;    


    for ( i = 0; i < (sizeof(list) / sizeof(list[0])); i++)
    {
        No *z = criarNo(list[i], externo);
        inserir(externo, z, &(ptRaiz[0]));

    }

    int count = contaNos(ptRaiz[0], externo);
    printf("QTD: %d\n", count);
    
    outputOrd(ptRaiz[0], externo);
}

// Prepara as arvores a serem criadas
/*
void testeDeInsercao() {
    int alturaTotal;
    int i;
    // alocando memória para as raizes
    roots = (No**)malloc(sizeof(No*) * QTD_AVL);
    // Inicializando cada raiz para apontar para NULL
    for (i = 0; i < QTD_AVL; i++) {
        roots[i] = NULL;
    }
    
    // Inserindo a quantidade definida de nós em cada árvore
    for(i = 0; i < QTD_AVL; i++) {
        int nos = 0;
        alturaTotal = 0;
        // Enquanto nao ocorrerem as N insercoes, o laco continua
        while (nos < QTD_NOS) {
            int key = rand() % RAND_LIMITER;
            inseriNo(key, &(roots[i]), &alturaTotal);
            nos = contaNos(roots[i]);
        }
        // Atualizando a altura da arvore apos as inserções
        atualizaAltura(roots[i]);
    }
}*/