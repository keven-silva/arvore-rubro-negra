#include <stdio.h>
#include <stdlib.h>
#include "struct.h"


void MoverPai(No *externo, No **u, No **v, No **ptRaiz)
{   
    if((*u)->pai == externo)
    {
        (*ptRaiz)  = (*v);
    }else{
        if ((*u) == (*u)->pai->esq)
        {
            (*u)->pai->esq = (*v);
        }
        else
        {
            (*u)->pai->dir = (*v);   
        }
    }

    (*v)->pai = (*u)->pai;
}


void RotacaoE(No *z, No **ptRaiz, No *externo)
{
    No *y = z->dir;

    z->dir = y->esq;
    if (z->dir != externo)
    {
        z->dir->pai = z;
    }

    y->pai = z->pai;

    if (z->pai == externo)
        *ptRaiz = y;
    else if (z == z->pai->esq)
        z->pai->esq = y;
    else
        z->pai->dir = y;

    y->esq = z;
    z->pai = y;
}


void RotacaoD(No *z, No **ptRaiz, No *externo)
{
    No *y = z->esq;
    z->esq = y->dir;
    if (z->esq != externo)
    {
        z->esq->pai = z;
    }

    y->pai = z->pai;

    if (z->pai == externo) 
    {
        *ptRaiz = y;
    }
    else if (z == z->pai->esq)
    {
        z->pai->esq = y;
    }else
    {
        z->pai->dir = y;
    }   

    y->dir = z;
    z->pai = y;
}


No *noExterno()
{
    No *novo = (No*) malloc(sizeof(No));

    novo->chave = 0;
    novo->cor = 'N';
    novo->esq = NULL;
    novo->dir = NULL;
    novo->pai = NULL;

    return novo;
}

No *criarNo(int key, No *externo)
{
    No *novo = (No*) malloc(sizeof(No));

    novo->chave = key;
    novo->cor = 'N';
    novo->esq = externo;
    novo->dir = externo;
    novo->pai = externo;

    return novo;
}

int contaNos(No *pt, No *externo)
{
    int _count;

    if (pt == externo)
    {
        return 0;
    }
    else
    {
        _count = contaNos(pt->esq, externo);
        _count += contaNos(pt->dir, externo);
        _count++;
    }

    return _count;
}

void imprimiArvores(No *pt, No *externo) 
{
    int i;
    int nos;

    for(i = 0; i < 7; i++) {
        if(pt != externo) {
            nos = contaNos(pt, externo); // contando os nos
            printf("Arvore %d | Quantidade de nos = %d\n", i, nos);
        }else printf("Arvore %d | NULL\n", i);
    }
}

void outputOrd(No *pt, No *externo)
{
    printf("Chave: %d | Cor: %c\n", pt->chave, pt->cor);
    if (pt->esq != externo)
        outputOrd(pt->esq, externo);
    // printf("%d (%d);\n", pt->chave, pt->cor);
    if (pt->dir != externo)
        outputOrd(pt->dir, externo);
    /* printf("%d (%d);\n", pt->chave, pt->cor); */
}
