#include <unistd.h>

int main(int argc, char **argv)
{
	int j = 0;
	int c_j;
	int find1;
	int find2;

	if (argc != 3)
		return (-1);

	while (argv[1][j] != '\0')
	{
		c_j = 0;
		find1 = 0;
		while (argv[2][c_j] != '\0')
		{
			if (argv[2][c_j] == argv[1][j])
			{
				find1 = 1;
			}
			c_j++;
		}

		c_j = 0;
		find2 = 0;
		while (c_j < j)
		{
			if (argv[1][j] == argv[1][c_j])
			{
				find2 = 1;
			}
			c_j++;
		}

		if (find1 == 1 && find2 == 0)
			write(1, &(argv[1][j]), 1);
		j++;
	}
	write(1, "\n", 1);
}