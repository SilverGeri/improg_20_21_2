#include <stdio.h>

int foo(int x) {
	if (x < 0) return 1;

	return 0;
}

int main() {
	int x = 10;
	printf("%d\n", ++x);
	printf("%d\n", x);

	for(int i = 0; i < 10; ++i) {
        	printf("It's running\n");
    	}

	for(int i=0; 10>=i--; i+=2) {
		printf("Fut %d\n", i);
	}

	// i = 0 -> -1
	// i = 1 -> 0
	//

	int a;
	for(int i=5; a == foo(i); i--) {
        	printf("still running %d\n", i);
   	}

	// = assignment
	// == equality check
	

	return 0;
}
