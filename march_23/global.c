#include <stdio.h>

int g = 5; // global variable
int error_code = 0;

void inc_g() {
	int x = 10;
	g = g + 1;
}


void f() {
	error_code = 0;
	// do some calculation
	// if there is an error:
	error_code = 1;
}

int main() {
	printf("%d\n", g); // 5
	inc_g();
	printf("%d\n", g); // 6
	inc_g();

	printf("%d\n", g); // 7

	// if error_code is not 0 and we don't check, f() will delete it

	f();
	if (error_code != 0) {
		printf("there was an error during f's evaluation\n");
	}

	//printf("%d\n", x); // compile error
	
	int y = 12;
	printf("%d\n", y);
	{
		printf("%d\n", y);
		int p = 1;
		printf("%d\n", p);
		{
			int qwer = 2;
			// y is visible here
			// p i visible here
			// qwer is visible here
		}
		// y is visible here
		// p is visible here
		// qwer is NOT visible here!!!
	}

	// printf("%d\n", p); // compile error
	//
	
	if (y == 12) {
		int asd = 2; // only visible in true branch
	} else {
		// asd is not visible here
	}

	// asd is not visible here

	return 0;
}
