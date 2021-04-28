#include <stdio.h>

#define MAX(a, b) a < b ? b : a

#define PRINT(p) printf("%s\n", #p)

#define SIZE 5
#define N 500


int main() {
	int a = 4;
	int b = 5;
	// MAX(a++, b--) a++ < b-- ? b-- : a++
	int x = MAX(a++, b--);
	printf("a: %d, b: %d, max: %d\n", a, b, x);

	PRINT(5);
	PRINT("asdf");

	return 0;
}
