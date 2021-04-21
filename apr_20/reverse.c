#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse_in_place(char* str) {
	unsigned int length = strlen(str);
	for (unsigned int i = 0; i < length / 2; ++i) {
		char temp = str[i];
		str[i] = str[length-i-1];
		str[length-i-1] = temp;
	}
}

// malloc length + 1 because of nullcharacter/ nullterminator: \0
// nullterminated strings ends with \0
char* reverse(const char* const str) {
	unsigned int length = strlen(str);
	char* result = (char*)malloc((length+1) * sizeof(char));

	//e.g.: str is "asdf", length is going to be 4
	// i = 3: f -> length - i - 1 = 0
	// i = 2: d -> length - i - 1 = 1
	// i = 1: s -> length - i - 1 = 2
	// i = 0: a -> length - i - 1 = 3
	for (int i = length - 1; i >= 0; --i) {
		result[length - i - 1] = str[i];
	}

	// result[4] in the example
	result[length] = '\0';

	return result;
}


int main() {
	char str[] = "something";

	printf("%s\n", str);
	reverse_in_place(str);
	printf("%s\n", str);

	char* reversed = reverse(str);
	printf("%s\n", reversed);

	free(reversed);

	return 0;
}
