/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaehoei <ssaehoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 21:37:22 by ssaehoei          #+#    #+#             */
/*   Updated: 2022/07/14 03:23:26 by ssaehoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	ft_putchar(char c)
// {
// 	return (write(1, &c, 1));
// }

// int	ft_putstr(char *s)
// {
// 	int	count;

// 	count = 0;
// 	if (s)
// 	{
// 		while (*s)
// 		{
// 			count += ft_putchar(*s);
// 			s++;
// 		}
// 	}
// 	else
// 	{
// 		count += write(1, "(null)", 6);
// 	}
// 	return (count);
// }

// int	ft_putnbr(int n)
// {
// 	int	count;

// 	count = 0;
// 	if (n < 0)
// 	{
// 		count += ft_putchar('-');
// 		if (n == -2147483648)
// 		{
// 			count += ft_putchar('2');
// 			n = -147483648;
// 		}
// 		n = n * -1;
// 	}
// 	if (n < 10)
// 		count += ft_putchar(n + 48);
// 	if (n >= 10)
// 	{
// 		count += ft_putnbr(n / 10);
// 		count += ft_putnbr(n % 10);
// 	}
// 	return (count);
// }

// int	ft_put_unsigned_int_nbr(unsigned int n)
// {
// 	int	count;

// 	count = 0;
// 	if (n < 10)
// 		count += ft_putchar(n + 48);
// 	if (n >= 10)
// 	{
// 		count += ft_putnbr(n / 10);
// 		count += ft_putnbr(n % 10);
// 	}
// 	return (count);
// }

// int	ft_put_ptr(size_t n)
// {
// 	int		count;
// 	size_t	p;

// 	count = 0;
// 	if (n >= 0 && n <= 16)
// 	{
// 		p = n % 16;
// 		if (n == 0)
// 		{
// 			count += write (1, "0", 1);
// 			return (count);
// 		}
// 		if (p == 0)
// 			count += write(1, "10", 2);
// 		else if (p > 0 && p < 10)
// 			count += ft_putnbr(p);
// 		else
// 			count += ft_putchar(p + 87);
// 	}
// 	if (n > 16)
// 	{
// 		count += ft_put_ptr(n / 16);
// 		count += ft_put_ptr(n % 16);
// 	}
// 	return (count);
// }

// int	ft_puthex(unsigned int n, int d)
// {
// 	int				count;
// 	unsigned int	p;

// 	count = 0;
// 	if (n >= 0 && n <= 16)
// 	{
// 		p = n % 16;
// 		if (n == 0)
// 		{
// 			count += write(1, "0", 1);
// 			return (count);
// 		}
// 		if (p == 0)
// 			count += write(1, "10", 2);
// 		else if (p > 0 && p < 10)
// 			count += ft_putnbr(p);
// 		else
// 			count += ft_putchar(p + d);
// 	}
// 	if (n > 16)
// 	{
// 		count += ft_puthex(n / 16, d);
// 		count += ft_puthex(n % 16, d);
// 	}
// 	return (count);
// }

int	print_and_define_type(va_list ap, const char *c)
{
	int	count;

	count = 0;
	if (*c == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (*c == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (*c == 'u')
		count += ft_put_unsigned_int_nbr(va_arg(ap, unsigned int));
	else if (*c == 'd' || *c == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (*c == 'p')
	{
		count += write(1, "0x", 2);
		count += ft_put_ptr((size_t)va_arg(ap, void *));
	}
	else if (*c == 'x')
		count += ft_puthex(va_arg(ap, unsigned int), 87);
	else if (*c == 'X')
		count += ft_puthex(va_arg(ap, unsigned int), 55);
	return (count);
}

int	ft_printf(const char *c, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, c);
	count = 0;
	while (*c != '\0')
	{
		if (*c != '%')
		{
		count += ft_putchar(*c);
		}
		else if (*(c + 1) == '%')
		{
			count += ft_putchar('%');
			c++;
		}
		else
		{
			count += print_and_define_type(ap, (c + 1));
			c++;
		}
		c++;
	}
	va_end(ap);
	return (count);
}

// int main()
// {
//     char	*s;
// 	int	count;
// 	int		i;
// 	int	*ptr = &i;
// 	unsigned int	ui;
// 	int	j;
// 	size_t	t;
// 	*s = 's';
// 	i = 55555555;
// 	// t = 18446744073709551615;
// 	// ui = 150;
// 	ui = 1234111;
// 	j = 65;
// 	// count  = ft_printf("The max value of usigned int %u",ui);
// 	// printf("\n");
// 	// ft_printf("%d",count);
// 	// ft_putchar('a');
// 	//  i = ft_putchar(j+1);
// 	// printf("\n");
// 	// ft_printf("%d",i);
// 	printf("expected : %s",NULL);
// 	printf("\n");
// 	count = ft_printf("Result : %s",NULL);
// 	// count  = ft_printf( "%x   %X",ui,ui);
// 	printf("\n");
// 	ft_printf("%d",count);
//     return 0;
// }
