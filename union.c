#include "unistd.h"

int check(char **argv, char c, int i, int j)
{
	int find1 = 0;
	int find2 = 0;
	int c_j;

	if (i == 1)
	{
		c_j = 0;
		while (c_j < j)
		{
			if (c == argv[1][c_j])
				find1 = 1;
			c_j++;
		}
	}

	else
	{
		c_j = 0;
		while (argv[1][c_j] != '\0')
		{
			if (argv[1][c_j] == c)
				find2 = 1;
			c_j++;
		}
		c_j = 0;
		while (c_j < j)
		{
			if (c == argv[2][c_j])
				find2 = 1;
			c_j++;
		}
	}
	return (find1 + find2);
}

int	main(int argc, char **argv)
{
	int i;
	int j;

	if (argc != 3)
		return (-1);
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (check(argv, argv[i][j], i, j) == 0)
				write(1, &argv[i][j], 1);
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
}