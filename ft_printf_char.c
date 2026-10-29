/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_char.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/29 18:28:56 by msotnych      #+#    #+#                 */
/*   Updated: 2026/10/29 18:37:44 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	c;

	c = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[c] != '\0')
	{
		write(1, &s[c], 1);
		c++;
	}
	return (c);
}
