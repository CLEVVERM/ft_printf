/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/27 15:18:01 by msotnych      #+#    #+#                 */
/*   Updated: 2026/10/27 19:05:34 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format , ...)
{	
	va_list list; 
	int res;
	int c;

	c = 0;
	res = 0;
	va_start(list, format);
	while (format[c] != '\0')
	{
		if(format[c] == '%')
		{
			format[c + 1] = 
		}
		else
		{
			write(1, &c, 1);
			res++;
		}
	}



	va_end(va_list list);
	if (!format)
		return (NULL);
	
}

char manager(char letter, )
