#include <stdio.h>
#include <stdlib.h>


typedef struct DynArray {
	unsigned int count; // how many elements you have in it
	unsigned int capacity; // for how many elements memory is allocated
	int* data;
} DynArray;


void init_dyn_array(DynArray* arr) {
	arr->count = 0;
	arr->capacity = 8;
	arr->data = (int*)malloc(arr->capacity * sizeof(int));
}

void free_dyn_array(DynArray* arr) {
	free(arr->data);
	arr->data = NULL;
	arr->count = 0;
	arr->capacity = 0;
}

void push_back_dyn_array(DynArray* arr, int value) {
	if (arr->capacity <= arr->count) {
		// allocate a bigger memoryspace
		arr->capacity *= 2;
		arr->data = (int*)realloc(arr->data, arr->capacity * sizeof(int));
	}

	arr->data[arr->count++] = value;
}

void print(DynArray* arr) {
	printf("[");
	for (int i = 0; i < arr->count; ++i) {
		printf("%d, ", arr->data[i]);
	}
	printf("]\n");
}


int main() {
	DynArray myArray;
	init_dyn_array(&myArray);

	push_back_dyn_array(&myArray, 5);
	push_back_dyn_array(&myArray, 3);
	push_back_dyn_array(&myArray, 7);
	push_back_dyn_array(&myArray, 2);
	push_back_dyn_array(&myArray, 1);
	push_back_dyn_array(&myArray, 5);
	push_back_dyn_array(&myArray, 5);
	push_back_dyn_array(&myArray, 5);
	push_back_dyn_array(&myArray, 5);
	push_back_dyn_array(&myArray, 5);
	push_back_dyn_array(&myArray, 5);
	push_back_dyn_array(&myArray, 5);
	push_back_dyn_array(&myArray, 5);
	push_back_dyn_array(&myArray, 5);
	push_back_dyn_array(&myArray, 5);
	push_back_dyn_array(&myArray, 5);
	push_back_dyn_array(&myArray, 5);
	push_back_dyn_array(&myArray, 5);
	push_back_dyn_array(&myArray, 5);
	print(&myArray);

	free_dyn_array(&myArray);
}
