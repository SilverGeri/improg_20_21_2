#include <stdio.h>
#include <stdlib.h>


// factorial 5 = 5 * 4 * 3 * 2 * 1
// factorial 4 = 4 * 3 * 2 * 1
// factorial 5 = 5 * factorial(4)
int factorial(int n) {
	if (n == 1) {
		return 1;
	}
	return n * factorial(n - 1);
}


int main(int argc, char* argv[]) {
	if (argc < 2) return 1;

	int n = atoi(argv[1]);
	if (n < 1) {
		printf("Logical error\n");
		return 1;
	}
	printf("%d\n", factorial(n));

	return 0;
}
