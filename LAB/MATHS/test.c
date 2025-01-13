#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct s_point
{
	int x;
	int y;
}	t_point;


static	void	swap_point(t_point *p0, t_point *p1)
{
	int x_tmp;
	int y_tmp;

	x_tmp = p0->x;
	y_tmp = p0->y;
	p0->x = p1->x;
	p0->y = p1->y;
	p1->x = x_tmp;
	p1->y = y_tmp;
}

int main() 
{
	t_point p0;
	t_point p1;
	p0.x = 13, p0.y = 42;
	p1.x = 7, p1.y = 66;
	swap_point(&p0, &p1);
	printf("p0.x = %d | p0.y = %d\np1.x = %d | p1.y = %d\n", p0.x, p0.y, p1.x, p1.y);
    return 0;
}
