#include <stdio.h>

int main() {
	int first;
	int second;  // double second;

	printf("add first number: ");
	scanf("%d", &first);

	printf("add second number: ");
	scanf("%d", &second);

	printf("The result of %d / %d is %d, remains %d\n", first, second, first / second, first % second);
	

//	char str[25];
//	scanf("%[^\n]s", str);

//	printf("the read name is %s\n", str);

	return 0;
}
