#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Person {
	char name[30];
	int* age;
} Person;

void print_person(Person* p) {
	printf("%s: %d\n", p->name, *p->age);
}


int main() {
	Person p;
	strcpy(p.name, "safdas");
	p.age = (int*)malloc(sizeof(int));
	*p.age = 23;

	Person p2 = p;
	print_person(&p);
	print_person(&p2);

	*p.age = 24;
	print_person(&p);
	print_person(&p2);

	Person p3;
	strcpy(p3.name, p.name);
	p3.age = (int*)malloc(sizeof(int));
	*p3.age = *p.age;
	*p3.age = 32;

	print_person(&p);
	print_person(&p3);
	
	free(p.age);
	free(p3.age);

	return 0;
}
