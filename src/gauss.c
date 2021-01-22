#include "gauss.h"
#include <math.h>

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
    int ir, jr, jc;
    int i;
    double constInR;              
    double rMaxElem;    // do poszukiwania elementu glownego
    int rMaxIndex;      // i numeru wiersza w ktorym sie znajduje

    for (ir = 0; ir < mat->r; ir++) {
        rMaxElem = fabs(mat->data[ir][ir]);          // [ir][ir] bo to element diagonalny w danym wierszu
        for (i = ir; i < mat->r; i++) {             // poszukiwanie elementu glownego w kolumnie
            if (fabs(mat->data[i][ir]) > rMaxElem) {
                rMaxElem = mat->data[i][ir];
                rMaxIndex = i;
            }
        }
        if (rMaxElem > fabs(mat->data[ir][ir])) {    // jesli element glowny nie znajduje sie w ir, zamien wiersze 
            rowOrderModifier(mat, ir, rMaxIndex);
            rowOrderModifier(b, ir, rMaxIndex);
        }

        for (jr = ir + 1; jr < mat->r; jr++) {                      // dla wszystkich wierszy pod diagonala (pod w. aktualnie okreslonym przez ir)
            constInR = mat->data[jr][ir] / mat->data[ir][ir];       // o ta stala trzeba przemnozyc kazdy element w wierszu wiec dla jasnosci dalej uzywa sie zmiennej
            for (jc = ir; jc < mat->c; jc++)                        // dla wszystkich elementow wiersza za diagonala
                mat->data[jr][jc] -= constInR * mat->data[ir][jc];
            b->data[jr][0] -= constInR * b->data[ir][0];
        }
    }

	return 0;
}