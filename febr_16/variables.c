#include <stdio.h>

void f() {
	int x;
	printf("%d\n", x);
}

int abs(int param) {
	if (param < 0) {
		return -param;
	}

	return param;
}

int main() {

	//int x;

	//printf("%d\n", x);
	
	f();

	printf("%d\n", abs(3));
	printf("%d\n", abs(-2));
	printf("%d\n", abs(32));
	printf("%d\n", abs(-43));
	printf("%d\n", abs(0));

	return 0;
}
