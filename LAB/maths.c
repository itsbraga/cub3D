# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# define HEIGHT 20
# define WIDTH 20

char	**alloc_map(void)
{
	int i = 0;
	char **map;
	map = malloc(HEIGHT * sizeof(char *));
	while (i < HEIGHT)
	{
		map[i] = malloc(WIDTH * sizeof(char));
		i++;
	}
	return (map);
}

typedef struct	s_point
{
	int x;
	int	y;
}	t_point;

void	draw_line(t_point p1, t_point p2, char **map)
{
	int dx = p2.x - p1.x;
	int dy = p2.y - p1.y;
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
	char **map = alloc_map();
	t_point	p1;
	t_point p2;
	(p1.x = 17, p1.y = 4);
	(p2.x = 4, p2.y = 9);
	
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
			map[i][j] = '.';
	}
	map[p1.y][p1.x] = '*';
	map[p2.y][p2.x] = '*';
	draw_line(p1, p2, map);

	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
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
