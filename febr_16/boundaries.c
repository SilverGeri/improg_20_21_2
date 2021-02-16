#include <stdio.h>

int main() {
	printf("%ld\n", sizeof(int));  // 4 bytes on my machine: 11111111 11111111 11111111 11111111
	int x = 2147483647; // 2^31
	printf("%d\n", x);

	// printf("%ld\n", sizeof(long int));
	printf("unsigned: %ld\n", sizeof(unsigned));

	unsigned u = 2147483647;
	u = u * 2;
	printf("u value: %u\n", u);
	return 0;
}
