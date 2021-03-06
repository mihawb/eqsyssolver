#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include "test.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char ** argv) {  // gdy uzywa sie programu test nalezy jako 3 argument podać plik z poprawnymi wynikami
	int res;
	Matrix * A = readFromFile(argc > 1 ? argv[1] : "A");
	Matrix * b = readFromFile(argc > 2 ? argv[2] : "b");
	Matrix * x;

	if (A == NULL) return -1;
	if (b == NULL) return -2;
	printToScreen(A);
	printToScreen(b);

	res = eliminate(A,b);

    if (res != 0) {
        fprintf(stderr, "Element o indeksach 1x1 rowny 0 lub niewlasciwe rozmiary macierzy\n");
    }
    
    /*
    printf("debug eliminacji gaussa\n");
    printToScreen(A);
    printToScreen(b);
     */
    
	x = createMatrix(b->r, 1);
	if (x != NULL) {
		res = backsubst(x,A,b);
		if(res == 1)
			printf("Macierz osobliwa. Wyznacznik równy 0\n");	
		
		else if(res == 2)
			printf("Błąd! Złe wymiary macierzy\n");
		else	
			printToScreen(x);

		if (argc > 3)
			check(argv[3], x);  //do sprawdzania

	    freeMatrix(x);
	} else {
		fprintf(stderr,"Błąd! Nie mogłem utworzyć wektora wynikowego x.\n");
	}

	freeMatrix(A);
	freeMatrix(b);

	return 0;
}
