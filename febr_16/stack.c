#include <stdio.h>

int main() {
	int x = 0;
	int y = 4;

	x;

	int arr[3] = {1, 2, 3}; // [1, 2, 3]
	printf("%d\n", arr[0]); // first element
	printf("%d\n", arr[2]); // third element

	// arr[n] => arr + n * sizeof(int), [4bytes, 4bytes, 4bytes]

	return 0;
}
