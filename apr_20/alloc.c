#include <stdio.h>
#include <string.h> // strlen, strcpy
#include <stdlib.h> // malloc, free

int main() {
	char buffer[20];
	printf("Type something that's less than 20 chars: ");
	scanf(" %[^\n]", buffer);

	char* copy = (char*)malloc((strlen(buffer) + 1) * sizeof(char)); // memory garbage
	strcpy(copy, buffer);

	printf("original: %s\n", buffer);
	printf("copy:     %s\n", copy);

	// always needed when we use malloc otherwise it's memory leak!!!
	free(copy);

	return 0;
}

/*
malloc in other languages: new
*/

