#include <stdio.h>

int main() {
	void swap(int* left, int* right) {
		int temp = *left;
		*left = *right;
		*right = temp;
	}

	int x = 3;
	int y = 5;

	swap(&x, &y);
	printf("x: %d, y: %d\n", x, y);

	return 0;
}
