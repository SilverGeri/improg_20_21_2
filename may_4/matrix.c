#include <stdlib.h>

typedef struct Matrix {
	unsigned int row;
	unsigned int column;
	int* data;
} Matrix;

void init_matrix(Matrix* m, unsigned int row, unsigned int column) {
	m->row = row;
	m->column = column;
	m->data = (int*)malloc(row * column * sizeof(int));

	for (unsigned int i = 0; i < row * column; ++i) {
		m->data[i] = 0;
	}
}

void free_matrix(Matrix* m) {
	free(m->data);
	m->data = NULL;
	m->row = 0;
	m->column = 0;
}

int main() {
	Matrix a;
	init_matrix(&a, 4, 5);
	free_matrix(&a);

	init_matrix(&a, 10, 6);
	free_matrix(&a);

	return 0;
}
