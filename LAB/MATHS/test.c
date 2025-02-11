#include <stdio.h>
#include <stdlib.h>
#include <math.h>

# define PI 3.1415926535


typedef struct s_point
{
	int x;
	int y;
}	t_point;


// static	void	swap_point(t_point *p0, t_point *p1)
// {
// 	int x_tmp;
// 	int y_tmp;

// 	x_tmp = p0->x;
// 	y_tmp = p0->y;
// 	p0->x = p1->x;
// 	p0->y = p1->y;
// 	p1->x = x_tmp;
// 	p1->y = y_tmp;
// }

float	norm_angle2(float rad)
{
	if (rad < 0)
		rad += (2 * PI);
	else if (rad > 0)
		rad -= (2 * PI);
	return (rad);
}

float	norm_angleians(float rad)
{
	float normalized;

	normalized = fmod(rad, (2 * PI));
	if (normalized < 0)
		normalized += (2 * PI);
	return(normalized);
}

int main() 
{
	float rad = 7.050273;
	printf("rad fmod = %f\n", norm_angleians(rad));
	printf("rad newfunc = %f\n", norm_angle2(rad));
    return 0;
}
