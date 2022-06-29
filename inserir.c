#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "utilitarios.h"


void RotaRN(No *z, No **ptRaiz, No *externo)
  {
    while (z->pai->cor == 'R')
    {
        if (z->pai == z->pai->pai->esq)
        {
            No (*y) = z->pai->pai->dir;

            if (y->cor == 'R')
            {
                z->pai->cor = y->cor = 'N';
                z->pai->pai->cor = 'R';
                z = z->pai->pai;
            }else
            {
                if (z == z->pai->dir)
                {
                    z = z->pai;
                    RotacaoE(z->pai, ptRaiz, externo); 
                }

                z->pai->cor = 'N';
                z->pai->pai->cor = 'R';
                RotacaoD(z->pai->pai, ptRaiz, externo);
            }
        }
        else
        {
            No (*y) = z->pai->pai->esq;

            if (y->cor ='R')
            {
                z->pai->cor = y->cor = 'N';
                z->pai->pai->cor = 'R';
                z = z->pai->pai;
            }else
            {
                if (z == z->pai->esq)
                {
                    z = z->pai;
                    RotacaoD(z, ptRaiz, externo); 
                }
                
                z->pai->cor = 'N';
                z->pai->pai->cor = 'R';
                RotacaoE(z->pai->pai, ptRaiz, externo);
            }
        }    
    }   

    (*ptRaiz)->cor = 'N';
}


void inserir(No *externo, No *z, No **ptRaiz)
{
    No (*y) = externo;
    No (*pt) = (*ptRaiz);

    while (pt != externo)
    {
        y = pt;

        if (z->chave == pt->chave)
        {
            printf("Chave %d existente!\n", pt->chave);
            y = NULL;
            pt = externo;
        }
        else
        {
            if(z->chave < pt->chave)
            {
                pt = pt->esq;
            }else
            {
                pt = pt->dir;
            }
        }
    }
    if (y != NULL)
    {
        z->pai = y;

        if (y == externo)
        {
            (*ptRaiz) = z;
        }
        else
        {
            if (z->chave < y->chave)
            {
                y->esq = z;
            }
            else
            {
                y->dir = z;
            }
        }

        z->esq = z->dir = externo;
        z->cor = 'R';
        RotaRN(z, ptRaiz, externo);
    }
    
    (*ptRaiz)->cor = 'N';
}

