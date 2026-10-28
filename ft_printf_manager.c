/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_manager.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/28 16:34:30 by msotnych      #+#    #+#                 */
/*   Updated: 2026/10/28 18:03:33 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	manager(char letter, va_list *args)
{
	(void)args;
	if (letter == '%')
		ft_putchar('%');
	if (letter == 'c')
		ft_putchar(va_arg(*args, int));
	return (0);
}
