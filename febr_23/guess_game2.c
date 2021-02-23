#include <stdio.h>
#include <stdlib.h>


int get_target() {
	return rand() % 1000 + 1;
}


int guessing() {
	int guess;
	printf("guess: ");
	scanf("%d", &guess);

	return guess;
}

int evaluate(int target, int guess) {
	if (guess < target) {
		printf("Too low!\n");
	} else if (guess > target) {
		printf("Too great!\n");
	} else {
		// must be equal
		printf("Congrats, you've found it!\n");
		return 1; // we found the target
	}

	int diff = guess - target;
	if (diff < 0) {
		diff = diff * -1;
	}

	if (diff < 15) {
		printf("You are close...\n");
	}

	// we haven't found the target
	return 0;
}


int main() {
	srand(0);
	int NUM = get_target();
	printf("I am thinking if a number, try to guess it (1-1000)");

	int guess = guessing();

	while (evaluate(NUM, guess) == 0) {
		guess = guessing();
	}

	return 0;
}
