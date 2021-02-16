#include <stdio.h>

int main(void)
{
	float f, c;
	int lower, upper, step;

	lower = -20;
	upper = 200;
	step = 10;

	printf("F C\n\n");
	f = lower;
	while(f <= upper)
	{
		c = (f - 32) * (5.0/9.0);
		printf("%f %f\n", f, c);
		f = f + step;
	}
	return 0;
}
