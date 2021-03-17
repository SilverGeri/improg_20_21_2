#include <stdio.h>
#include <stdlib.h> // because of NULL

int main() {
	FILE* file = fopen("player.txt", "w");
	
	if (file == NULL) {
		printf("Could not open file!\n");
		return 1;
	}

	fputs("Gergely\n", file);
	fprintf(file, "Gergely with fprintf\n");
	fclose(file);

	file = fopen("even_numbers.txt", "a");

	int arr[] = {12, 234, 5445, 456, 5, 3};
	for (int i = 0; i < 6; ++i) {
		if (arr[i] % 2 == 0) {
			fprintf(file, "%d\n", arr[i]);
		}
	}
	fclose(file);

	return 0;
}
