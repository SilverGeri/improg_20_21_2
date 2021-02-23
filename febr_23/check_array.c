#include <stdio.h>

int main() {
	int arr[] = {1,2,9,4,7};

	int increasing = 1;  // true
	int decreasing = 1;
	for(int i = 0; i < 4; ++i) {
		if (arr[i+1] - arr[i] < 0) {
			increasing = 0; // false
		}
		if (arr[i] - arr[i+1] < 0) {
			decreasing = 0;
		}
	}

	if (increasing) {
		printf("array elements are increasing\n");
	} else if (decreasing) {
		printf("array elements are decreasing\n");
	} else {
		printf("array elements are neither increasing nor decreasing\n");
	}

	return 0;

}
