/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_manager.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/28 16:34:30 by msotnych      #+#    #+#                 */
/*   Updated: 2026/10/28 18:26:01 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	manager(char letter, va_list *args)
{
	(void)args;
	if (letter == '%')
		return (ft_putchar('%'));
	if (letter == 'c')
		return (ft_putchar(va_arg(*args, int)));
	if (letter == 's')
		return(ft_putstr(va_arg(*args, int)));
	return (0);
}
