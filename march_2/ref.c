#include <stdio.h>

int multiply(int* x) {
	printf("multiply's x location: %p\n", x);
	*x = *x * -1;
	return *x;
}

int negate(int x) {
	printf("negate's x location: %p\n", &x);
	return x * -1;
}

int main() {
	int x = 5;
	printf("orignal x location: %p\n", &x);


	printf("%d\n", multiply(&x));
	// printf("original: %d\n", x);

	// multiply(&x);
	x = negate(x);
	return 0;
}

