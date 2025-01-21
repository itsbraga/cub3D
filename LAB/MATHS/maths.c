# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "../MLX/mlx.h"


# define W_HEIGHT 1000
# define W_WIDTH 1000

typedef struct	s_point
{
	int x;
	int	y;
}	t_point;

void	draw_line(t_point p1, t_point p2, char **map)
{
	int dx = abs(p2.x - p1.x);
	int dy = abs(p2.y - p1.y);
	int y = p1.y;
	int eps = 0;

	for (int x = p1.x; x <= p2.x; x++)
	{
		map[y][x] = '*';
		eps += dy;
		if ((eps << 1) >= dx)
		{
			y++;
			eps -= dx;
		}
	}
}

int	main(void)
{
	t_mlx	mlx;
	t_data	data;
	t_point	p1;
	t_point p2;
	(p1.x = 17, p1.y = 4);
	(p2.x = 4, p2.y = 9);
	
	init_mlx(&mlx, &data);
	draw_line(p1, p2, map);

	for (int i = 0; i < W_HEIGHT; i++)
	{
		for (int j = 0; j < W_WIDTH; j++)
			printf("%c", map[i][j]);
		printf("\n");
	}
	printf("\n");
	if ((p2.x - p1.x) > (p2.y - p1.y))
		printf("la ligne est plus horizontale que verticale\n");
	else
		printf("la ligne est plus verticale que horizontale\n");
	return (0);
}
