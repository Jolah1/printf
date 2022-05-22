#include "main.h"

/**
 * print_bigS - Non printable characters
 * (0 < ASCII value < 32 or >= 127)
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: number of char
 */

int print_bigS(va_list l, flags_t *f)
{
	int i, count = 0;
	char *res;
	char *s = va_arg(l, char *);

	(void)f;
	if (!s)
		return (_puts("(null)"));

	for (i = 0; s[i]; i++)
	{
		if (s[i] > 0 && (s[i] < 32 || s[i] >= 127))
		{
			_puts("\\x");
			count += 2;
			res = convert(s[i], 16, 0);
			if (!res[1])
				count += _putchar('0');
			count += _puts(res);
		}
		else
			count += _putchar(s[i]);
	}
	return (count);
}

/**
 * print_rev - prints a string in reverse
 * @l: argument from _printf
 * @f: pointer to the struct flags that
 * determines if a flag is passed to _printf
 * Return: length of the printed string
 */

int print_rev(va_list l, flags_t *f)
{
	int i = 0, j;
	char *s = va_arg(l, char *);

	(void)f;
	if (!s)
		s = "(null)";

	while (s[i])
		i++;

	for (j = i - 1; j >= 0; j--)
		_putchar(s[j]);


	return (i);
}

/**
 * print_rot13 - prints a string using rot13
 * @l: list of arguments
 * @f: pointer to the struct
 * Return: length ot the printed string
 */

int print_rot13(va_list l, flags_t *f)
{
	int i, j;
	int counter = 0;
	char rot13[] = "NOPQRSTUVWXYZABCDEFGHIJKLM	nopqrstuvwxyzabcdefghijklm";
	char *s = va_arg(l, char *);

	(void)f;

	i = 0;
	j = 0;

	while (s[i])
	{
		if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
		{
			j = s[i] - 65;
			counter += _putchar(rot[j]);
		}
		else
			counter += _putchar(s[i]);
		i++;
	}

	return (counter);

}

/**
 * print_percent - prints a percent
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags in which we turn the flags on
 * Return: number of char printed
 */

int print_percent(va_list l, flags_t *f)
{
	(void)l;
	(void)f;

	return (_putchar('%'));
}
