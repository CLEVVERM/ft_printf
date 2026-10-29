/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/27 15:17:39 by msotnych      #+#    #+#                 */
/*   Updated: 2026/10/29 19:08:47 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
// # include <stdio.h>

int	ft_printf(const char *format, ...);
int	manager(char letter, va_list *args);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_putnbr_unsigned(unsigned long nb);
int	ft_putnbr_hex(unsigned long nb);
int	ft_putnbr_cap_hex(unsigned long nb);
int	ft_putpointer(char *s);

#endif