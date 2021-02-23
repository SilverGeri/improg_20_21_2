#include <stdio.h>

int a(int param, int count);
int b(int param, int count);

int a(int param, int count) {
	++count;
	param = param / 2;
	if (param > 0) {
		return b(param, count);
	}

	return count;
}

int b(int param, int count) {
	++count;
	param = param - 1;
	if (param > 0) {
		return a(param, count);
	}

	return count;
}

int main() {
	int x;
	printf("Give a starting value: ");
	scanf("%d", &x);

	int count = a(x, 0);

	printf("%d number of iterations\n", count);

	return 0;
}
