#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char buffer[20];

	char* store[5];

	for (int i = 0; i < 5; ++i) {
		scanf("%s", buffer);
		store[i] = (char*)malloc((strlen(buffer)+1) * sizeof(char));
		strcpy(store[i], buffer);
	}


	for (int i = 4; i >= 0; --i) {
		printf("%s\n", store[i]);
	}

	for (int i = 0; i < 5; ++i) {
		free(store[i]);
	}

	return 0;
}
