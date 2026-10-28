/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/27 15:18:01 by msotnych      #+#    #+#                 */
/*   Updated: 2026/10/28 15:43:08 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format , ...)
{	
	va_list list; 
	int res;
	int c;
	char letter;
	
	c = 0;
	res = 0;
	if (!format)
		return (-1);
	va_start(list, format);
	while (format[c] != '\0')
	{
		if(format[c] == '%')
		{
			if (format[c + 1] == '\0')
				break;
			letter = format[c + 1];
			res = res + manager(letter, list);
			c = c + 2;
		}
		else
		{
			write(1, &format[c], 1);
			res++;
			c++;
		}
	}
	va_end(list);
	return (res);
}

int	manager(char letter, va_list *list)
{
	if (letter == '%')
	{
		write(1, '%', 1);
		return (1);
	}
	return (0);
}


int main(void)
{
	
}