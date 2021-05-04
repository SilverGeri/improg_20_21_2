#include <stdio.h>
#include <stdlib.h>

enum Type {BSc, MSc, PhD};

typedef struct ImpactFactor {
	double highest;
	int erdos_number;
} ImpactFactor;

struct Student {
	double average;
	int ID;
	int age;
	enum Type type;

	// int total_courses; // for bsc
	// double creadit_index; // for msc
	// ImpactFactor impact_factor; // for phd

	union {
		int total_courses;
		double credit_index;
		ImpactFactor impact_factor;
	} extra;
};

typedef struct Student Student;

typedef struct Something {
	int x;
	int y;
} Something;


int highestAverage(Student* arr, int size) {
	if (size == 0) return -1;

	int highest_index = 0;
	for (int i = 1; i < size; ++i) {
		if (arr[i].average > arr[highest_index].average) {
			highest_index = i;
		}
	}

	return arr[highest_index].ID;
}

Student* student_init(enum Type type) {
	Student* student = (Student*)malloc(sizeof(Student));
	student->type = type;

	if (type == BSc) {
		student->extra.total_courses = 4;
	} else if (type == MSc) {
		student->extra.credit_index = 5.5;
	} else if (type == PhD) {
		student->extra.impact_factor.highest = 6.7;
		student->extra.impact_factor.erdos_number = 12;
	}

	return student;
}

int main() {
	struct Student s;
	printf("%d, %f, %d\n", s.ID, s.average, s.age);
	printf("%p\n\n", &s);
	printf("size: %ld\n", sizeof(s));
	printf("%p\n%p\n%p\n", &s.ID, &s.average, &s.age);
	printf("%ld, %ld, %ld\n", sizeof(s.ID), sizeof(s.average), sizeof(s.age));

	Student s2;
	Something s3;

	// Student arr[3] = {{4.5, 1, 14, BSc}, {3.2, 2, 15, BSc}, {5.0, 3, 14, MSc}};
	// printf("highest average ID: %d\n", highestAverage(arr, 3));
	
	Student* s4 = student_init(PhD);
	// s4->ID // need -> because s4 is pointer
	printf("extra: tc: %d, ci: %f, if: %f, %d\n", 
			s4->extra.total_courses,
		       	s4->extra.credit_index,
		       	s4->extra.impact_factor.highest,
			s4->extra.impact_factor.erdos_number);

	free(s4);

	return 0;
}
