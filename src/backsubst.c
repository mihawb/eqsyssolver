#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int backsubst(Matrix *x, Matrix *mat, Matrix *b) 
{
	int k,w;
	double sum;
	for(w = mat->r-1;w>=0;w--)
	{
		sum = 0;	
		for(k = w+1;k<mat->c;k++)
			sum += mat->data[w][k] * x->data[k][0];
	
		x->data[w][0] = (b->data[w][0] - sum) / mat->data[w][w];
		
	}
	return 0;
}


