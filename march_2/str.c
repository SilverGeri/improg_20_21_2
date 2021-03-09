#include <stdio.h> 
#include <string.h>


unsigned strlen2(char* str) {
	unsigned length = 0;
	while (str[length] != '\0') {
		++length;
	}
	
	return length;
}

void alpha_ord(char* str1, char* str2) {
	int i = 0;
	unsigned long size1 = strlen(str1);
	unsigned long size2 = strlen(str2);
	if (size1 == 0 || str1[i] < str2[i]) {
		printf("first string is before second\n");
		return;
	} else if (size2 == 0 || str2[i] < str1[i]) {
		printf("second string is before first\n");
		return;
	}

	while (str1[i] == str2[i] && i < size1 && i < size2) {
		if (str1[i] < str2[i]) {
			printf("first string is before second\n");
			return;
		} else if ( str2[i] < str1[i]) {
			printf("second string is before first\n");
			return;
		} else {
			++i;
		}
	}

	if (size1 == size2) {
		printf("they are the same\n");
	} else if (size1 < size2) {	
		printf("first string is before second\n");
	} else {
		printf("second string is before first\n");	
	}
}


int main() {
	char str[] = "asfasfasdf";

	unsigned length = strlen(str);

	printf("%d\n", length);
	printf("%d\n", strlen(str));
	printf("%d\n", strlen2(str));

	alpha_ord(str, str);
	alpha_ord("asdf", "sdfa");
	alpha_ord("fdsa", "asdf");
	alpha_ord("as", "asdf");

	return 0;
}
