#include "remover.h"


void RemoverRN(No *z, No *externo, No **ptRaiz)
{
    No *x, *coOriginal;
	No *y = z;
	coOriginal->cor = y->cor;

	if(z->esq == externo) 
    {
		x = z->dir;
		// MoverPai(z, z->dir, externo, ptRaiz);
	} else {
        if(z->dir == externo) 
        {
            x = z->esq;
            // MoverPai(z, z->esq, externo, ptRaiz);
        } else {
            y = sucessor(z->dir, externo);
            coOriginal->cor = y->cor;
            x = y->dir;

            if(y->pai != z)
            {
                // MoverPai(y, x, externo, ptRaiz);
               y->dir = z->dir;
               y->pai = y;
            }

            // MoverPai(z, y, externo, ptRaiz);
            y->esq = z->esq;
            y->esq->pai = y;
        }
    }

	if(coOriginal->cor == 'N')
    {
		RotaRemoverRN(x, externo, ptRaiz);
    }

}


void RotaRemoverRN(No *z, No *externo, No **ptRaiz)
{
    while(z !=(*ptRaiz) && z->cor == 'N') 
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
				z->pai->cor = 'N';
				w->dir->cor = 'N';
				RotacaoE(z->pai, externo, ptRaiz);
				z =(*ptRaiz);
			}
		} else {
			No *w = z->pai->esq;

			if(w->cor == 'R') {
				z->pai->cor = 'R';
				w->cor = 'N';
				RotacaoD(z->pai, externo, ptRaiz);
				w = z->pai->esq;
			}

			if(w->dir->cor == 'N' && w->esq->cor == 'N') {
				w->cor = 'R';
				z = z->pai;
			} else {
				if(w->esq->cor == 'N') {
					w->dir->cor = 'N';
					w->cor = 'R';
					RotacaoE(w, externo,  ptRaiz);
					w = z->pai->esq;
				}

				w->cor = z->pai->cor;
				z->pai->cor = 'N';
				w->esq->cor = 'N';
				RotacaoD(z->pai, externo, ptRaiz);
				z =(*ptRaiz);
			}
		}
	}

	z->cor = 'N';
}
