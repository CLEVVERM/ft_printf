/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/27 15:18:01 by msotnych      #+#    #+#                 */
/*   Updated: 2026/10/27 17:59:01 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format , ...)
{	
	va_list list; 
	int res;
	int c;

	c = 0;
	va_start(list, format);
	while (format[c] != '\0')
	{
		
	}



	va_end(va_list list);
	if (!format)
		return (NULL);
	
}


