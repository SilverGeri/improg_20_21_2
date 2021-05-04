#include <stdlib.h>

typedef struct Matrix {
	unsigned int row;
	unsigned int column;
	int* data;
} Matrix;

void init_matrix(Matrix* m, unsigned int row, unsigned int column) {
	m->row = row;
	m->column = column;

	// we can check invalid matrix this way
	if (row == 0 || column == 0) {
		m->data = NULL;
		return;
	}
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

int* at(const Matrix* const m, int row, int col) {
	return &m->data[row * m->column + col];
}

Matrix mmultiply(const Matrix* const lhs, const Matrix* const rhs) {
	Matrix result;
	if (lhs->column != rhs->row) {
		init_matrix(&result, 0, 0);
		return result;
	}

	init_matrix(&result, lhs->row, rhs->column);

	for (unsigned int i = 0; i < lhs->row; ++i) {
		for (unsigned int j = 0; j < rhs->column; ++j) {
			int value = 0;
			for (unsigned int k = 0; k < lhs->column; ++k) {
				value += *at(lhs, i, k) * *at(rhs, k, j);
			}
			*at(&result, i, j) = value;
		}
	}

	return result;
}

int main() {
	Matrix a;
	init_matrix(&a, 4, 5);
	free_matrix(&a);

	init_matrix(&a, 10, 6);
	free_matrix(&a);


	Matrix m1, m2;
	init_matrix(&m1, 4, 5);
	init_matrix(&m2, 5, 7);

	// shallow copy, because of aliasing, there is no memory leak if we free res
	Matrix res = mmultiply(&m1, &m2);

	free_matrix(&m1);
	free_matrix(&m2);
	free_matrix(&res);

	return 0;
}
