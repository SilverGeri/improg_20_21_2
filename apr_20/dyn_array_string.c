#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// quiz solution:
int count_vowels(char* str) {
	int result = 0;
	for (int i = 0; i < strlen(str); ++i) {
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
			++result
		}
	}

	return result;
}


int main(int argc, char* argv[]) {
	// no extra check now
	int count = atoi(argv[1]);
	int actually_read = 0;
	char buffer[20];

	char** store = (char**)malloc(count * sizeof(char*));

	for (int i = 0; i < count; ++i) {
		scanf("%s", buffer);
		store[i] = (char*)malloc((strlen(buffer)+1) * sizeof(char));
		strcpy(store[i], buffer);
		++actually_read;
		if (strcmp(buffer, "END") == 0) {
			break;
		}
	}

	printf("\n");

	for (int i = 0; i < actually_read; ++i) {
		printf("%s\n", store[actually_read-i-1]);
	}


	for (int i = 0; i < actually_read; ++i) {
		free(store[i]);
	}

	free(store);

	return 0;
}



