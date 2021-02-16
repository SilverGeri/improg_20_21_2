#include <stdio.h>
#include <stdbool.h>

int main() {
	// int x = 5.99999; // truncate decimal
	// int x = 'A';     // ascii code
	// int x = false;   // false is 0, true is 1
	// int x = "asdf";  // memory address with warning

	int x = 5;
	printf("%d\n", x);

	char c = 'A';
	printf("%c\n", c);

	bool stuff = true;
	printf("stuff: %d\n", stuff);
	stuff = !stuff;
	printf("stuff: %d\n", stuff);

	char str[] = "safasdf";
	printf("%s\n", str);

	return 0;

}
