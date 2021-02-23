#include <stdio.h>

int count = 0;

void a(int param);
void b(int param);

void a(int param) {
	++count;
	param = param / 2;
	if (param > 0) {
		b(param);
	}
}

void b(int param) {
	++count;
	param = param - 1;
	if (param > 0) {
		a(param);
	}
}

int main() {
	int x;
	printf("Give a starting value: ");
	scanf("%d", &x);
	a(x);

	printf("%d number of iterations\n", count);

	return 0;
}
