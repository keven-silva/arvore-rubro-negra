#include "remover.h"


void RemoverRN(No *z, No *externo, No **ptRaiz)
{
	No *corOriginal = noExterno();
    No *x = noExterno();
	No *y = z;
	corOriginal->cor = y->cor;

	if(y->esq == externo) 
    {
		x = z->dir;
		MoverPai(z, z->dir, externo, ptRaiz);
	} else {
        if(y->dir == externo) 
        {
            x = z->esq;
            MoverPai(z, z->esq, externo, ptRaiz);
        } else {
            y = sucessor(z->dir, externo);
            corOriginal->cor = y->cor;
            x = y->dir;

            if(y->pai != z)
            {
               MoverPai(y, x, externo, ptRaiz);
               y->dir = z->dir;
               y->dir->pai = y;
            }else
			{
				x->pai = y;
			}

            MoverPai(z, y, externo, ptRaiz);
            y->esq = z->esq;
            y->esq->pai = y;
			y->cor = z->cor;
        }
    }

	free(z);
	
	if(corOriginal->cor == 'N')
    {
		RotaRemoverRN(x, externo, ptRaiz);
    }
	
}


void RotaRemoverRN(No *z, No *externo, No **ptRaiz)
{
    while(z !=(*ptRaiz) && z->cor != 'R') 
    {
		if(z == z->pai->esq) 
        {
			No *w = z->pai->dir;

			if(w->cor == 'R') 
            {
				z->pai->cor = 'R';
				w->cor = 'N';
				RotacaoE(z->pai, externo, ptRaiz);
				w = z->pai->dir;
			}

			if(w->esq->cor == 'N' && w->dir->cor == 'N') 
            {
				w->cor = 'R';
				z = z->pai;
			} else {
				if(w->dir->cor == 'N') 
                {
					w->esq->cor = 'N';
					w->cor = 'R';
					RotacaoD(w, externo, ptRaiz);
					w = z->pai->dir;
				}

				w->cor = z->pai->cor;
				z->pai->cor = w->dir->cor = 'N';
				RotacaoE(z->pai, externo, ptRaiz);
				z = (*ptRaiz);
			}
		} else {
			No *w = z->pai->esq;

			if(w->cor == 'R') 
			{
				z->pai->cor = 'R';
				w->cor = 'N';
				RotacaoD(z->pai, externo, ptRaiz);
				w = z->pai->esq;
			}

			if(w->dir->cor == 'N' && w->esq->cor == 'N') 
			{
				w->cor = 'R';
				z = z->pai;
			} else {
				if(w->esq->cor == 'N') 
				{
					w->dir->cor = 'N';
					w->cor = 'R';
					RotacaoE(w, externo,  ptRaiz);
					w = z->pai->esq;
				}

				w->cor = z->pai->cor;
				z->pai->cor = w->esq->cor = 'N';
				RotacaoD(z->pai, externo, ptRaiz);
				z = (*ptRaiz);
			}
		}
	}

	z->cor = 'N';
}
