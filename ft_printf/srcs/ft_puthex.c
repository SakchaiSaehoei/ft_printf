/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaehoei <ssaehoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 02:21:49 by ssaehoei          #+#    #+#             */
/*   Updated: 2022/07/14 03:05:44 by ssaehoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, int d)
{
	int				count;
	unsigned int	p;

	count = 0;
	if (n >= 0 && n <= 16)
	{
		p = n % 16;
		if (n == 0)
		{
			count += write(1, "0", 1);
			return (count);
		}
		if (p == 0)
			count += write(1, "10", 2);
		else if (p > 0 && p < 10)
			count += ft_putnbr(p);
		else
			count += ft_putchar(p + d);
	}
	if (n > 16)
	{
		count += ft_puthex(n / 16, d);
		count += ft_puthex(n % 16, d);
	}
	return (count);
}
