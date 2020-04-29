#include "smatrix.h"
#include <stdio.h>
#include <stdlib.h>

// Time complexity = O(n^2)
int same_value(matrix a, element b, int num);

void smadd(matrix a, matrix b, matrix d) {
	assert((a != NULL) && (b != NULL) && (d != NULL));
	assert(a[0].row == b[0].row && a[0].col == b[0].col);
	int totalA = a[0].value;
	int totalB = b[0].value;	

	memcpy(d, a, sizeof(element) * (totalA + 1));

	for (int i = 1; i <= totalB; i++) {
		int sv = same_value(d, b[i], totalA);
		if (!sv) { 
			totalA += 1;
			d[totalA] = b[i]; }
		else { d[sv].value += b[i].value; }
	}
	d[0].value = totalA;
}

int same_value(matrix a, element b, int num) {
	for (int i = 1; i <= num; i++) {
		if (a[i].row == b.row && a[i].col == b.col) { return i; }
	}
	return 0;
}

void main()
{
	//matrix a = create(3, 5);

	matrix a = malloc(sizeof(element) * 9);
	a[0].row = 6; a[0].col = 6; a[0].value = 8;
	//matrix b = malloc(sizeof(element)*9);

	a[1].row = 0; a[1].col = 0; a[1].value = 15;
	a[2].row = 0; a[2].col = 3; a[2].value = 22;
	a[3].row = 0; a[3].col = 5; a[3].value = -15;
	a[4].row = 1; a[4].col = 1; a[4].value = 11;
	a[5].row = 1; a[5].col = 2; a[5].value = 3;
	a[6].row = 2; a[6].col = 3; a[6].value = -6;
	a[7].row = 4; a[7].col = 0; a[7].value = 91;
	a[8].row = 5; a[8].col = 2; a[8].value = 28;

	matrix b;
	smcreate(&b, 3, 5);
	smtranspose(a, b);

	matrix d;
	smcreate(&d, 5, 5);

	smvisualprint(a, false);
	printf("+\n");
	smvisualprint(b, false);
	printf("=\n");

	smadd(a, b, d);
	smvisualprint(d, false);

	free(a);
	smremove(&b);
}