/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/27 15:18:01 by msotnych      #+#    #+#                 */
/*   Updated: 2026/10/28 18:05:31 by msotnych      ########   odam.nl         */
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

int main(void)
{
	printf("%c\n", 'w');
	ft_printf("%c\n", 'f');
}