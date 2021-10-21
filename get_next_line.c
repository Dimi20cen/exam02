#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	int rd;
	int i = 0;
	char c;
	char *buffer = malloc(100000);

	while ((rd = read(fd, &c, 1)) > 0)
	{
		buffer[i++] = c;
		if (c == '\n')
			break ;
	}
	if (rd == -1 || (rd == 0 && !buffer[i - 1]))
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer[i] = '\0';
	return (buffer);
}

int main()
{
    int fd = open("testfile", O_RDONLY);
    for (size_t i = 0; i < 30; i++)
    {
        char *s = get_next_lin(fd);
        printf("%s", s);
        free(s);
		s = NULL;
    }
    close(fd);
}

