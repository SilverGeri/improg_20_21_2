#include <stdio.h>

void f(int x, int y);
//void g(int x, int y);

int main() {
	f(3, 4);

	return 0;
}


void f(int left, int right) {
	printf("product: %d\n", left * right);
}
