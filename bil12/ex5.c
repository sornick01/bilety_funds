#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>

int	is_simple(int n)
{
	if (n == 1)
		return (0);
	if (n == 2)
		return (1);
	if (n % 2 == 0)
		return (0);
	for (int i = 3; i <= sqrt((double)n); i+=2)
	{
		if (n % i == 0)
			return (0);
	}
	return (1);
}

int	func(int(*callback)(int), size_t n, ...)
{
	int	res;
	va_list	args;

	res = 0;
	va_start (args, n);
	while (n--)
	{
		if ((callback)(va_arg(args, int)) != 0)
		{
			res++;
		}
	}
	va_end(args);
	return (res);
}

int main()
{
	printf("amount simples = %d", func((is_simple), 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10));
}