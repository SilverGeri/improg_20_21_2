#include <stdio.h>

void asdf() {
	static int count = 0;
	printf("%d. call\n", ++count);
}


int main() {
	asdf();
	asdf();
	asdf();
	asdf();
	asdf();
	asdf();
	asdf();
	asdf();

	return 0;
}
