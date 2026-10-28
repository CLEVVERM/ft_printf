/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/27 15:18:01 by msotnych      #+#    #+#                 */
/*   Updated: 2026/10/28 14:40:45 by msotnych      ########   odam.nl         */
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
	va_start(list, format);
	while (format[c] != '\0')
	{
		if(format[c] == '%')
		{
			c++;
			letter = format[c + 1];
			c += 2;
			res = res + 
			
		}
		else
		{
			write(1, &format[c], 1);
			res++;
			c++;
		}
	}



	va_end(list);
	if (!format)
		return (NULL);
	
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
