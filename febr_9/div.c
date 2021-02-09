#include <stdio.h>

int main() {
	float first;
	float second;  // double second;

	printf("add first number: ");
	scanf("%f", &first);

	printf("add second number: ");
	scanf("%f", &second);

	printf("The result of %f / %f is %f\n", first, second, first / second);
	

	char str[25];
	scanf(" %[^\n]", str);

	printf("the read name is %s\n", str);

	return 0;
}
