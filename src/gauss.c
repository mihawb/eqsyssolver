#include "gauss.h"
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b)
{
        int c,r;
        double wsp;
        int j,i,p;
        double tmp;;
        for(c=0;c<mat->c-1;c++)
        {
                for(c=0;c<mat->c-1;c++)
                {
                        /*Wybieramy element główny - Równanie posiadające największą co do modułu wartośc w kolumnie*/
                        int rmax = c;
                        for(i=c+1;i<mat->r;i++)
                        {
                                if(fabs(mat->data[i][c])>fabs(mat->data[rmax][c]))
                                        rmax = i;
                        }
                        /*Podmieniamy równania*/
                        if(rmax != c)
                        {
                                for(p=c;p<mat->c;p++)
                                {
                                        tmp = mat->data[rmax][p];
                                        mat->data[rmax][p] = mat->data[c][p];
                                        mat->data[c][p] = tmp;
                                }
                                tmp = b->data[rmax][0];
                                b->data[rmax][0] = b->data[c][0];
                                b->data[c][0] = tmp;
                        }
                        /*Zerujemy kolumnę*/
                        for(r=c+1;r<mat->r;r++)
                        {
				if(data[c][c] == 0)
					return 1;
                                wsp = mat->data[r][c]/mat->data[c][c];
                                for(j=c;j<mat->c;j++)
                                {
                                        mat->data[r][j] -= mat->data[c][j]*wsp;
                                }
                                b->data[r][0] -= b->data[c][0]*wsp;
                        }
                }
        }
                return 0;
}


