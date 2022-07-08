#include "util.h"


void MoverPai(No **u, No **v, No *externo, No **ptRaiz)
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


void RotacaoD(No *z, No *externo, No **ptRaiz)
{
    No *y = z->esq;
    z->esq = y->dir;
    
    if (z->dir != externo)
    {
        y->dir->pai = z;
    }

    y->pai = z->pai;

    if (z->pai == externo)
    {
        (*ptRaiz) = y;
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


void RotacaoE(No *z, No *externo, No **ptRaiz)
{
    No *y = z->dir;
    z->dir = y->esq;
    
    if (z->esq != externo)
    {
        z->esq->pai = z;
    }

    y->pai = z->pai;

    if (z->pai == externo) 
    {
        (*ptRaiz) = y;
    }
    else if (z == z->pai->esq)
    {
        z->pai->esq = y;
    }else
    {
        z->pai->dir = y;
    }   

    y->esq = z;
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

void imprimirOrdem(No *pt, No *externo)
{
    // printf("Chave: %d | Cor: %c\n", pt->chave, pt->cor);
    if (pt->esq != externo)
    {
        imprimirOrdem(pt->esq, externo);
    }
    
    printf("Chave: %d | Cor: %c\n", pt->chave, pt->cor);

    if (pt->dir != externo)
    {
        imprimirOrdem(pt->dir, externo);
    }

    // printf("Chave: %d | Cor: %c\n", pt->chave, pt->cor);
}


No* buscarNo(No *z, int key, No *externo) 
{
    while(z != externo && key != z->chave)
    {
        if(key < z->chave) 
        {
            z = z->esq;
        }else {
           z = z->dir;
        }

    }   

    return z;
}


No* sucessor(No *z, No* externo) 
{
    No (*y) = z;

    while(y->esq != externo)
        y = y->esq;

    return y;
}
