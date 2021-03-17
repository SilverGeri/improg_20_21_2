#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE* file = fopen("even_numbers.txt", "r");

	// check if exist
	
	char buffer[10];
	int result = 0;


	while (fgets(buffer, 10, file) != NULL) {
		result += atoi(buffer);
	}
	fclose(file);
	printf("sum: %d\n", result);

	return 0;
}

//exercise 8: in string.h header, there is strcmp function, the exercise can be done with it
