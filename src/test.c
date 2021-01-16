#include "mat_io.h"
#include "test_1.h"
#include <math.h>

double my_round(double x, unsigned int digits) {
	if (digits > 0) {
		return my_round(x * 10.0, digits - 1) / 10.0;
	}
	else {
		return round(x);
	}
}

void check(char* solution, Matrix* x) {

	Matrix* sol = readFromFile(solution);

	int i, j;
	double sol_r, x_r;
	for (i = 0; i < sol->r; i++) {
		for (j = 0; j < sol->c; j++) {

			sol_r = my_round(sol->data[i][j], 5);
			x_r = my_round(x->data[i][j], 5);

			if (sol_r != x_r) {
				printf("Zly wynik");
				return 1;
			}
		}
	}

	printf("Dobry wynik");
}