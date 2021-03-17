#include <stdio.h>
#include <string.h>


void toLowerCase(char* str) {
	int diff = 'a' - 'A';
	for (unsigned i = 0; i < strlen(str); ++i) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] += diff;
		} else {
			continue;
		}
	}
}

int main() {
	char str[] = "safdaAADEQRads asdRT  asd";
	printf("%s\n", str);
	toLowerCase(str);
	printf("%s\n", str);


	return 0;
}
