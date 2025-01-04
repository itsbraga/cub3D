# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ps;

	ps = (unsigned char *)s;
	while (n--)
	{
		*ps = c;
		ps++;
	}
	return (s);
}