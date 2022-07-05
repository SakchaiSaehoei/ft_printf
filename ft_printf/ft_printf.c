/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaehoei <ssaehoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 21:37:22 by ssaehoei          #+#    #+#             */
/*   Updated: 2022/07/05 16:28:00 by ssaehoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
		while(*s)
		{
			count += ft_putchar(*s);
			s++;
		}
	}
	return (count);
}

int	ft_putnbr(int n)
{
	int	count;
	count = 0;
	if(n < 0)
	{
		count += ft_putchar('-');
		if (n == -2147483648)
		{
			count += ft_putchar('2');
			n = -147483648;
		}
		n = n * -1;
	}
	if(n < 10)
		count += ft_putchar(n + 48);
	if(n >= 10)
	{
		count += ft_putnbr(n / 10);
		count += ft_putnbr(n % 10);
	}
	return (count);
}

int	ft_put_unsigned_int_nbr(unsigned int n)
{
	int	count;
	count = 0;
	if(n < 10)
		count += ft_putchar(n + 48);
	if(n >= 10)
	{
		count += ft_putnbr(n / 10);
		count += ft_putnbr(n % 10);
	}
	return(count);
}

int	ft_puthex(unsigned int n , int	d)
{	int	count;
	unsigned int	p;
	count = 0;

	if (n>=0 && n <= 16)
	{
		p = n % 16;
		if (n == 0) {
			count += write(1,"0",1);
			return(count);
		}
		if(p == 0)
			count += write(1,"10",2);
		else if(p > 0 && p < 10)
			count += ft_putnbr(p);
		else
			count += ft_putchar(p + d);
	}
	if (n > 16)
	{
		count += ft_puthex(n / 16, d );
		count += ft_puthex(n % 16, d );

	}
	return(count);
}


int	ft_printf(const char *c, ...)
{
	va_list ap;
	va_start(ap,c);
	int	count;
	int	x_definder;
	x_definder = 55;
	count = 0;
	while(*c != '\0')
	{
		if (*c != '%')
		{
		count += ft_putchar(*c);
		}
		else if (*(c+1)== 's') {
			count += ft_putstr(va_arg(ap,char *));
			c++;

		}
		else if (*(c+1)== 'c') {
			count += ft_putchar(va_arg(ap,int));
			c++;
		}
		else if (*(c+1)== 'u') {
			count += ft_put_unsigned_int_nbr(va_arg(ap,unsigned int));
			c++;
		}
		else if (*(c+1)== 'd' || *(c+1)== 'i') {
			count += ft_putnbr(va_arg(ap,int));
			c++;
		}
		else if (*(c+1)== '%') {
			count += ft_putchar('%');
			c++;
		}
		// else if (*(c+1)== 'p') {
		// 	printf("%lu\n",(unsigned long)va_arg(ap,void *));
		// 	ft_put_long_nbr((unsigned long)va_arg(ap,void *));
		// 	c++;
		// }
		else if (*(c+1)== 'X' || *(c+1)== 'x') {
			if (*(c+1)== 'x')
				x_definder = 87;
			count = ft_puthex(va_arg(ap,unsigned int), x_definder);
			c++;
		}

		c++;

	}
	va_end(ap);
	return(count);
}

int main()
{
    char	*s;
	int	count;
	int		i;
	unsigned int	ui;
	int	j;
	s = "YEAN";
	i = 55555555;
	// ui = 150;
	ui = 1234111;
	j = 65;
	// count  = ft_printf("The max value of usigned int %u",ui);
	// printf("\n");
	// ft_printf("%d",count);
	// ft_putchar('a');
	//  i = ft_putchar(j+1);
	// printf("\n");
	// ft_printf("%d",i);
	count  = ft_printf( "%x",ui);
	printf("\n");
	ft_printf("%d",count);
    return 0;
}
