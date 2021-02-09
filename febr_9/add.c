#include <stdio.h>

int main() {
	int first;
	int second;

	printf("add first number: ");
	scanf("%d", &first);

	printf("add second number: ");
	scanf("%d", &second);

	printf("The result of %d + %d is %d\n", first, second, first + second);
	// c++:
	// cout << "The result of " << first << " + " << second << " is " << frist + second << endl;

	return 0;
}
