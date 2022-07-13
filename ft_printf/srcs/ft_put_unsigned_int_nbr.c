/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_int_nbr.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaehoei <ssaehoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 02:24:42 by ssaehoei          #+#    #+#             */
/*   Updated: 2022/07/14 02:25:19 by ssaehoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int	ft_put_unsigned_int_nbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n < 10)
		count += ft_putchar(n + 48);
	if (n >= 10)
	{
		count += ft_putnbr(n / 10);
		count += ft_putnbr(n % 10);
	}
	return (count);
}
