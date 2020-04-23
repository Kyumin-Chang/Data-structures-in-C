#include "smatrix.h"
// Time complexity = O(n^2)
int same_value(matrix a, element b, int num);

void smadd(matrix a, matrix b, matrix d) {
	assert((a != NULL) && (b != NULL) && (d != NULL));
	if (a[0].row != b[0].row || a[0].col != b[0].col) { printf("두 행렬의 크기가 다릅니다."); }
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