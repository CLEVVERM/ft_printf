/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/28 17:45:30 by msotnych      #+#    #+#                 */
/*   Updated: 2026/10/28 18:30:49 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int c;

	c = 0;
	while (s[c] != '\0')
	{
		write(1, &s[c], 1);
		c++;
	}
	return (1);
}