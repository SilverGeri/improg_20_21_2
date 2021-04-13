#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define SIZE 10

#define UNREVEALED -2
#define MINE -1

#define LOST 0
#define WON 1
#define IN_GAME 2

// https://stackoverflow.com/questions/2347770/how-do-you-clear-the-console-screen-in-c/36253316
void clearScreen()
{
  const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
  write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}

void fill(int table[SIZE][SIZE], int value) {
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			table[i][j] = value;
		}
	}
}

void print_table(int table[SIZE][SIZE]) {
	clearScreen();
	for (int i = 0; i < SIZE; ++i) {
		printf(" %d", i);
	}
	printf("\n");

	for (int row = 0; row < SIZE; ++row) {
		printf("%c", 'A' + row);
		for (int col = 0; col < SIZE; ++col) {
			if (table[row][col] == UNREVEALED) {
				printf("  ");
			} else if (table[row][col] == MINE) {
				printf(" X");
			} else {
				printf(" %d", table[row][col]);
			}
		}
		printf("\n");
	}

	printf("\n\n");
}

void inc_if_regular(int table[SIZE][SIZE], int row, int col) {
	if (row >= 0 && col >= 0 && row < SIZE && col < SIZE && table[row][col] != MINE) {
		++table[row][col];
	}
}

void put_mines(int table[SIZE][SIZE], unsigned int N) {
	srand(time(0));
	unsigned int mines_put = 0;
	while (mines_put < N) {
		int row = rand() % SIZE;
		int col = rand() % SIZE;
		if (table[row][col] != -1) {
			table[row][col] = -1;
			++mines_put;
			for (int i = row - 1; i < row + 2; ++i) {
				for (int j = col - 1; j < col + 2; ++j) {
					inc_if_regular(table, i, j);
				}
			}
		}
	}
}

int check_table(int table[SIZE][SIZE]) {
	int unrevealed = 0;

	for (int row = 0; row < SIZE; ++row) {
		for (int col = 0; col < SIZE; ++col) {
			if (table[row][col] == MINE) {
				return LOST;
			}
			if (table[row][col] == UNREVEALED) {
				++unrevealed;
			}
		}
	}

	if (unrevealed > 0) {
		return IN_GAME;
	}

	return WON;
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		printf("Not enough argmument!\n");
		return 1;
	}

	unsigned int N = atoi(argv[1]);
	if (N < 3 || N > 30) {
		printf("Number of mines should be between 3 and 30\n");
		return 1;
	}

	int data[SIZE][SIZE];
	int table_to_show[SIZE][SIZE];
	fill(data, 0);
	fill(table_to_show, UNREVEALED);

	put_mines(data, N);

	int row;
	int col;
	char guess[2];

	int state = check_table(table_to_show);
	print_table(table_to_show);

	while (state == IN_GAME) {
		printf("\n\n\nField to reveal: ");
		scanf("%s", guess);
		row = guess[0] - 'A';
		col = guess[1] - '0';
		table_to_show[row][col] = data[row][col];
		state = check_table(table_to_show);
		print_table(table_to_show);
	}

	if (state == WON) {
		printf("Congratulations, you have won!\n");
	} else {
		printf("You have lost :/\n");
	}

	return 0;
}
