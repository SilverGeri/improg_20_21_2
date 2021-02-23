#include <stdio.h>
#include <stdlib.h>
// #define NUM 412


int main() {
	srand(0);
	int NUM = rand() % 1000 + 1;
	printf("I am thinking if a number, try to guess it (1-1000)");

	int guess;
	printf("your guess: ");
	scanf("%d", &guess);
	
	while (guess != NUM) {
		if (guess < NUM) {
			printf("Too low!\n");
		} else {
			printf("Too great!\n");
		}

		int diff = guess - NUM;
		if (diff < 0) {
			diff = diff * -1;
		}

		if (diff < 15) {
			printf("You are close...\n");
		}
		printf("New guess: ");
		scanf("%d", &guess);
	}
	
	printf("Congrats!\n");

	return 0;
}
