/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_numb.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/28 17:45:30 by msotnych      #+#    #+#                 */
/*   Updated: 2026/10/30 14:07:32 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long	nb;
	int		c;
	char	str;

	c = 0;
	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
		c++;
	}
	if (nb > 9)
	{
		c += ft_putnbr(nb / 10);
	}
	str = nb % 10 + '0';
	c += write(1, &str, 1);
	return (c);
}

int	ft_putnbr_unsigned(unsigned long nb)
{
	int		c;
	char	str;

	c = 0;
	if (nb > 9)
	{
		c += ft_putnbr_unsigned(nb / 10);
	}
	str = nb % 10 + '0';
	c += write(1, &str, 1);
	return (c);
}

int	ft_putnbr_hex(unsigned long nb)
{
	int		c;
	char	res;
	char	*base;

	base = "0123456789abcdef";
	c = 0;
	if (nb >= 16)
	{
		c += ft_putnbr_hex(nb / 16);
	}
	res = base[nb % 16];
	c += write(1, &res, 1);
	return (c);
}

int	ft_putnbr_cap_hex(unsigned long nb)
{
	int		c;
	char	res;
	char	*base;

	base = "0123456789ABCDEF";
	c = 0;
	if (nb >= 16)
	{
		c += ft_putnbr_cap_hex(nb / 16);
	}
	res = base[nb % 16];
	c += write(1, &res, 1);
	return (c);
}

int	ft_putpointer(char *s)
{
	int	c;

	c = 0;
	if (s == NULL)
	{
		c += 5;
		return (write(1, "(nil)", 5));
	}
	c += write(1, "0x", 2);
	c += ft_putnbr_hex((unsigned long)s);
	return (c);
}
