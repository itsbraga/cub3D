#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() 
{
	int dx = 0;
	int dy = 0;
	float slope = 0;
	printf("# PREMIER OCTANT #\n");
	int x0 = 10; int y0 = 10; int x1 = 15; int y1 = 6;
	dx = x1 - x0;
	dy = y1 - y0;
	slope = dy / dx;
	printf("dx = %d\ndy = %d\nslope = %f\nint slope = %d\n\n", dx, dy, slope, (int)round(slope));
	printf("# SECOND OCTANT #\n");
	x0 = 10; y0 = 10; x1 = 15; y1 = 4; 
	dx = x1 - x0;
	dy = y1 - y0;
	slope = dy / dx;
	printf("dx = %d\ndy = %d\nslope = %f\nint slope = %d\n\n", dx, dy, slope, (int)round(slope));
	printf("# TROISIEME OCTANT #\n");
	x0 = 10; y0 = 10; x1 = 6; y1 = 4; 
	dx = x1 - x0;
	dy = y1 - y0;
	slope = dy / dx;
	printf("dx = %d\ndy = %d\nslope = %f\nint slope = %d\n\n", dx, dy, slope, (int)round(slope));
	printf("# QUATRIEME OCTANT #\n");
	x0 = 10; y0 = 10; x1 = 6; y1 = 6; 
	dx = x1 - x0;
	dy = y1 - y0;
	slope = dy / dx;
	printf("dx = %d\ndy = %d\nslope = %f\nint slope = %d\n\n", dx, dy, slope, (int)round(slope));
	printf("# CINQUIEME OCTANT #\n");
	x0 = 10; y0 = 10; x1 = 6; y1 = 13; 
	dx = x1 - x0;
	dy = y1 - y0;
	slope = dy / dx;
	printf("dx = %d\ndy = %d\nslope = %f\nint slope = %d\n\n", dx, dy, slope, (int)round(slope));
	printf("# SIXIEME OCTANT #\n");
	x0 = 10; y0 = 10; x1 = 6; y1 = 17; 
	dx = x1 - x0;
	dy = y1 - y0;
	slope = dy / dx;
	printf("dx = %d\ndy = %d\nslope = %f\nint slope = %d\n\n", dx, dy, slope, (int)round(slope));
	printf("# SEPTIEME OCTANT #\n");
	x0 = 10; y0 = 10; x1 = 13; y1 = 17; 
	dx = x1 - x0;
	dy = y1 - y0;
	slope = dy / dx;
	printf("dx = %d\ndy = %d\nslope = %f\nint slope = %d\n\n", dx, dy, slope, (int)round(slope));
	printf("# HUITIEME OCTANT #\n");
	x0 = 10; y0 = 10; x1 = 17; y1 = 17; 
	dx = x1 - x0;
	dy = y1 - y0;
	slope = dy / dx;
	printf("dx = %d\ndy = %d\nslope = %f\nint slope = %d\n\n", dx, dy, slope, (int)round(slope));

    return 0;
}
