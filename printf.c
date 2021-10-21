#include <stdarg.h>
#include <unistd.h>

void	putchar(char c, int *chars_printed)
{
	write(1, &c, 1);
	*chars_printed += 1;
}

void	putstr(char *s, int *chars_printed)
{
	if (s == NULL)
		s = "(null)";
	while (*s)
	{
		putchar(*s, chars_printed);
		s++;
	}
}

int	ft_printf(const char *input, ...)
{
	va_list vars;
	int chars_printed = 0;

	va_start(vars, input);
	while(*input)
	{
		if (*input == '%')
		{
			input++;
			linker(input, vars, &chars_printed);
		}
		else
		{
			putchar(*input, &chars_printed);
		}
		input++;
	}
	va_end(vars);
	return (chars_printed);
}
