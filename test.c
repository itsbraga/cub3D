#include <stdio.h>

int main(void)
{
	unsigned int	red = 128;
	unsigned int	green = 128;
	unsigned int	blue = 128;
	unsigned long	hex = 0;

	hex = ((unsigned long)red << 16);
	hex = hex | ((unsigned long)green << 8);
	hex = hex | ((unsigned long)blue);

	printf("hex = %x\n", hex);
	return (0);
}
