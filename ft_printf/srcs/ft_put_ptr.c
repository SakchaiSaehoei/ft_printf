/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaehoei <ssaehoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 02:20:36 by ssaehoei          #+#    #+#             */
/*   Updated: 2022/07/14 02:25:15 by ssaehoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int	ft_put_ptr(size_t n)
{
	int		count;
	size_t	p;

	count = 0;
	if (n >= 0 && n <= 16)
	{
		p = n % 16;
		if (n == 0)
		{
			count += write (1, "0", 1);
			return (count);
		}
		if (p == 0)
			count += write(1, "10", 2);
		else if (p > 0 && p < 10)
			count += ft_putnbr(p);
		else
			count += ft_putchar(p + 87);
	}
	if (n > 16)
	{
		count += ft_put_ptr(n / 16);
		count += ft_put_ptr(n % 16);
	}
	return (count);
}
