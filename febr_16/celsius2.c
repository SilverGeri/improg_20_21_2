#include <stdio.h>

int main(void)
{
        for (float f = -20; f <= 200; f += 10)
        {
                float c = (f - 32) * (5.0 / 9.0);
                printf("%f %f\n", f, c);
        }
        return 0;
}

