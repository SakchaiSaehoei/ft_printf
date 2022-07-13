/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaehoei <ssaehoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 02:26:50 by ssaehoei          #+#    #+#             */
/*   Updated: 2022/07/14 02:26:52 by ssaehoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	count;

	count = 0;
	if (s)
	{
		while (*s)
		{
			count += ft_putchar(*s);
			s++;
		}
	}
	else
	{
		count += write(1, "(null)", 6);
	}
	return (count);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		if (n == -2147483648)
		{
			count += ft_putchar('2');
			n = -147483648;
		}
		n = n * -1;
	}
	if (n < 10)
		count += ft_putchar(n + 48);
	if (n >= 10)
	{
		count += ft_putnbr(n / 10);
		count += ft_putnbr(n % 10);
	}
	return (count);
}
