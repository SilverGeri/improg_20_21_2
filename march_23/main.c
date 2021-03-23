#include <stdio.h>
#include "my_utils.h"
#include "my_utils.h"
#include "my_utils.h"

int main() {
	int x = 3;
	int y = 5;

	int* p = max(&x, &y);
	printf("larger value is %d\n", *p);


	return 0;
}
