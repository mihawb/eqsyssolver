#ifndef _GAUSS_H
#define _GAUSS_H

#include "mat_io.h"

int abs(int x);
void rowOrderModifier(Matrix * m, int x, int y);

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b);

#endif
