#include "gauss.h"

int abs(int x) {
    if (x < 0)
        return -x;
    return x;
}

void rowOrderModifier(Matrix * m, int x, int y) {
    double *tmp = m->data[x];
    m->data[x] = m->data[y];
    m->data[y] = tmp;
}

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
    int ir, ic;
    int i;              
    double rMaxElem;    // do poszukiwania elementu glownego
    int rMaxIndex;      // i numeru wiersza w ktorym sie znajduje

    for (ir = 0; ir < mat->r; ir++) {
        rMaxElem = abs(mat->data[ir][ir]);          // [ir][ir] bo to element diagonalny w danym wierszu
        for (i = ir; i < mat->r; i++) {             // poszukiwanie elementu glownego w kolumnie
            if (abs(mat->data[i][ir]) > rMaxElem) {
                rMaxElem = mat->data[i][ir];
                rMaxIndex = i;
            }
        }
        if (rMaxElem > abs(mat->data[ir][ir])) {    // jesli element glowny nie znajduje sie w ir, zamien wiersze 
            rowOrderModifier(mat, ir, rMaxIndex);
            rowOrderModifier(b, ir, rMaxIndex);
        }
    }

	return 0;
}

