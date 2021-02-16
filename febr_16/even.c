#include <stdio.h>

int main() {
	int x = -2;

	if (x % 2 == 0) {
		printf("x is even\n");
	} else {
		printf("x is odd\n");
	}

	if (x > 0) {
		printf("x is positive\n");
	} else if (x < 0) {
		printf("x is negative\n");
	} else {
		printf("x is 0\n");
	}

	return 0;
}
