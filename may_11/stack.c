#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CAPACITY 10

typedef struct Box {
	int weight;
	struct Box* next;
} Box;

Box* top;
int size;

void init() {
	top = NULL;
	size = 0;
}

bool isEmpty(Box* b) {
	return b == NULL;
}

int peek() {
	if (isEmpty(top)) {
		return -1;
	}

	return top->weight;
}

bool push(int value) {
	if (size == CAPACITY) {
		return false;
	}

	Box* new_box = (Box*)malloc(sizeof(Box));
	new_box->weight = value;
	new_box->next = top;
	top = new_box;
	return true;
}

int pop() {
	if (isEmpty(top)) {
		return -1;
	}

	Box* prev = top;
	top = top->next;
	int retval = prev->weight;
	free(prev);

	return retval;
}

void copyTop() {
	Box* new_top = (Box*)malloc(sizeof(Box));
	new_top->weight = top->weight;
	new_top->next = top;
	top = new_top;
}

void print() {
	Box* actual = top;
	while (actual != NULL) {
		printf("%d -> ", actual->weight);
		actual = actual->next;
	}
	printf("NULL\n");
}


// 4 -> 3 -> 5 -> NULL
void free_box(Box* b) {
	if (b->next != NULL) {
		free_box(b->next);
		b->next = NULL;
	}

	free(b);
}

// bad, aliasing
void copyTopShallow() {
	Box* new_top = top;
	new_top->next = top;
	top = new_top;
}


int main() {
	init();

	push(5);
	push(3);
	push(4);
	print();
	printf("%d\n", peek());
	pop();
	print();

	free_box(top);
	return 0;
}
