#include <stdio.h>

int main() {
	int x = 5;

	printf("give me a number: ");
	scanf("%d", &x);

	printf("%d -> ", x);

	while (x > 0) {
		int current = x % 10;
		printf("%d", current);
		x = x / 10;
	}
	printf("\n");

	// input: 12345
	// 1: 12345 % 10 -> 5
	// 2: 1234 % 10 -> 4
	// 3: 123 % 10 -> 3
	// 4: 12 % 10 -> 2
	// 5: 1 % 10 -> 1
	// x == 0, quits loop

	return 0;
}
