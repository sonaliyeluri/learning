#include <stdio.h>
#include <stdlib.h>

unsigned int power(unsigned int x, unsigned int y)
{
    if (y == 0)
        return 1;
    else if (y%2 == 0)
        return power(x, y/2)*power(x, y/2);
    else
        return x*power(x, y/2)*power(x, y/2);
}
 
/* Program to test function power */
int main()
{
    unsigned int x = 2;
    unsigned int y = 16;
 
    printf("2 4 %d\n",power(2, 4));
	printf("2 -1 %d\n",power(2, -1));
	printf("2 0 %d\n",power(2, 0));
	printf("1 -2 %d\n",power(1, -2));
	printf("0 0 %d\n",power(0, 0));
	printf("-1 -1 %d\n",power(-1, -1));
	printf("2 16 %d\n",power(2, 16));
	printf("65535 0 %d\n",power(65535, 0));
	printf("0 65535 %d\n",power(0, 65535));
	printf("4294967295 1 %d\n",power(4294967295, 1));
    printf("\n");
    return 0;
}
