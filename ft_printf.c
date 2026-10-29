/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/28 16:34:30 by msotnych      #+#    #+#                 */
/*   Updated: 2026/10/29 19:06:46 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		res;
	int		c;

	c = 0;
	res = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[c] != '\0')
	{
		if (format[c] == '%')
		{
			if (format[c + 1] == '\0')
				break ;
			res = res + manager(format[c + 1], &args);
			c = c + 1;
		}
		else
			res += write(1, &format[c], 1);
		c++;
	}
	va_end(args);
	return (res);
}

int	manager(char letter, va_list *args)
{
	if (letter == '%')
		return (ft_putchar('%'));
	if (letter == 'c')
		return (ft_putchar(va_arg(*args, int)));
	if (letter == 's')
		return (ft_putstr(va_arg(*args, char *)));
	if (letter == 'd')
		return (ft_putnbr(va_arg(*args, int)));
	if (letter == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	if (letter == 'u')
		return (ft_putnbr_unsigned(va_arg(*args, unsigned int)));
	if (letter == 'x')
		return (ft_putnbr_hex(va_arg(*args, unsigned int)));
	if (letter == 'X')
		return (ft_putnbr_cap_hex(va_arg(*args, unsigned int)));
	if (letter == 'p')
		return (ft_putpointer(va_arg(*args, void *)));
	return (0);
}

// int main(void)
// {
// 	printf("%p\n", "*");
// 	ft_printf("%p\n", "*");
// }