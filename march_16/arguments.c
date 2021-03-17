#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[]) {
	printf("number of arguments: %d\n", argc);
	for (int i = 0; i < argc; ++i) {
		printf("%d: %s\n", i, argv[i]);
	}

	if (argc < 3) {
		printf("There is not enough arguments!\n");
		return 1;
	}

	int left = atoi(argv[1]);
	int right = atoi(argv[2]);
	// printf("%d\n", left * right);
	
	int result = 0;
	for (int i = 0; i < left; ++i) {
		result += right;
	}
	printf ("result: %d\n", result);

	return 0;
}
