#include <stdio.h>

void fill_zero(int* arr, int size) {
	// arr is a pointer to the first element of the array
	// arr[n] position: arr + n * sizeof(int)


	for (int i = 0; i < size; ++i) {
		arr[i] = 0;
	}
}


int sum(int* arr, int size) {
	int retval = 0;
	for(int i = 0; i < size; ++i) {
		retval += arr[i];
	}

	return retval;
}

// we assume arr and weights have the same size
int weighted_sum(int* arr, int* weights, int length) {
	int retval = 0;

	for (int i = 0; i < length; ++i) {
		retval += arr[i] * weights[i];
	}

	return retval;
}


void print_greatest(int* arr, int size) {
	if (size <= 0) {
		printf("Empty array has no greatest element!\n");
		return;
	}

	int max = arr[0];
	for (int i = 1; i < size; ++i) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}

	printf("max: %d\n", max);
}

int main() {
	int arr[3] = {1,2,3};
	unsigned length = sizeof(arr) / sizeof(int);

	for (unsigned i = 0; i < length; ++i) {
		printf("%d, ", arr[i]);
	}
	printf("\n");

	printf("sum: %d\n", sum(arr, length));
	printf("weighted sum: %d\n", weighted_sum(arr, arr, length));
	print_greatest(arr, length);

	fill_zero(arr, length);
		
	for (unsigned i = 0; i < length; ++i) {
		printf("%d, ", arr[i]);
	}
	printf("\n");

	int arr2[0];
	print_greatest(arr2, 0);

	return 0;

}
