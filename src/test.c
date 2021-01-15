#include "mat_io.h"
#include "test_1.h"

void check(char* solution, Matrix* x) {

	Matrix* sol = readFromFile(solution);

	int i, j, sol_i, x_i;
	for (i = 0; i < sol->r; i++) {
		for (j = 0; j < sol->c; j++) {
			sol_i = sol->data[i][j] * 10000000;         //jak tego nie bylo to nie dzialalo bo wynik roznil sie na jakims milionowym miejscu po przecinku, 
			x_i = x->data[i][j] * 10000000;             //pomimo ze wynik by³ np 2,123 to ten obliczony w programie by³ 2,123000000000000000000000000000000012 
			if (sol_i != x_i) {
				printf("Zly wynik");
				return 1;
			}
		}
	}

	printf("Dobry wynik");
}