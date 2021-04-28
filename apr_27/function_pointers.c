#include <stdio.h>

int scalar(int* lhs, int* rhs, int length) {
	int result = 0;
	for (int i = 0; i < length; ++i) {
		result += lhs[i] * rhs[i];
	}

	return result;
}

int foldl(int* arr, int length, int (*f)(int, int), int initial_value) {
	int result = initial_value;
	for (int i = 0; i < length; ++i) {
		result = (*f)(result, arr[i]);
	}

	return result;
}

int add(int a, int b) {
	return a+b;
}

int multiply(int a, int b) {
	return a*b;
}

int main() {
	int a[] = {1, 2, 5};
	int b[] = {3, 4, 5};
	printf("scalar: %d\n", scalar(a, b, 3));

	printf("sum: %d, product: %d\n", foldl(a, 3, add, 0), foldl(a, 3, multiply, 1));


	// int *p;
	int (*f_ptr)(int, int) = add;

	printf("sum of 4 and 5: %d\n", (*f_ptr)(4, 5));

	return 0;
}
