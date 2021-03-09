#include <stdio.h>
#include <stdlib.h>

int sum(int* arr, int size) {

	// printf("size: %d\n", size);
	// printf("sizeof result: %ld\n", sizeof(arr)); // always the same (8 bytes on my machine)

	int retval = 0;
	for (int i = 0; i < size; ++i) {
		retval += arr[i];
	}

	return retval;
}

int sum_with_arithmetics(int* arr, int size) {
	int retval = 0;
	for(int* actual = arr; actual < arr + size; ++actual) {
		printf("%p\n", actual);
		retval += *actual;
	}

	return retval;
}

int sum_with_pointer_end(int* begin, int* end) {
	int retval = 0;
	for (int* actual = begin; actual < end; ++actual) {
		retval += *actual;
	}

	return retval;
}

void print_array(int* arr, int size) {
	printf("[");
	for (int i = 0; i < size - 1; ++i) {
		printf("%d, ", arr[i]);
	}
	if (size > 0) {
		printf("%d", arr[size-1]);
	}
	printf("]\n");
}

void swap(int* left, int* right) {
	int temp = *left;
	*left = *right;
	*right = temp;
}

// error
int* return_local() {
	int x = 5;
	return &x;
}

int* max(int* arr, int size) {
	if (size == 0) {
		return NULL;
	}

	int* greatest = &arr[0];
	for (int i = 1; i < size; ++i) {
		if (arr[i] > *greatest) {
			greatest = &arr[i];
		}
	}

	return greatest;
}


int main() {
	int data[10] = {1, 2, 30, 4, 5, 60, 7, 8, 9, 10};
	int size = sizeof(data) / sizeof(int);
	int result = sum(data, size);
	int result_arithm = sum_with_arithmetics(data, size);
	int result_pointer_end = sum_with_pointer_end(data, data+10);
	int* greatest = max(data, size/2);

	printf("%d\n", result);
	printf("%d\n", result_arithm);
	printf("%d\n", result_pointer_end);
	if (greatest != NULL) {
		printf("max value: %d\n", *greatest);
	} else {
		printf("There was no greatest element in the array\n");
	}

	int x = 1, y = 2;
	printf("x: %d, y: %d\n", x, y);
	swap(&x, &y);
	printf("x: %d, y: %d\n", x, y);

	print_array(data, size);
	swap(&data[2], &data[5]);
	print_array(data, size);

	
	int* p = &x;           // int* = &int
	printf("x: %d\n", x);
	*p = 3;
	printf("x: %d\n", x);

	int** p2 = &p;
	**p2 = 4;
	printf("x: %d\n", x);

	// int* p3;            // int* = &int*
	// p3 = &p3;

	// int *p4 = get_pointer();
	// printf("%d\n", *p4);
	
	int* invalid = return_local();
	// printf("%d\n", *invalid); // undefined behaviour, probably segfault
	
	int* nil = NULL;
	// *nil; // cannot dereference
	char* c = NULL;
	if (c == NULL) {}

	int* greatest_of_one = max(&x, 1);
	printf("max of one: %d, address: %p, x address: %p\n", *greatest_of_one, greatest_of_one, &x);
	
	return 0;
}
