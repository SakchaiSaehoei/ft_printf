/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaehoei <ssaehoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 21:37:22 by ssaehoei          #+#    #+#             */
/*   Updated: 2022/06/07 21:59:57 by ssaehoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_printf(const char *s)
{
	while (*s)
	{
		ft_putchar(*s);
		s++;
	}
}

int main()
{
    char	*s;
	s = "yean asdfasdf asdfasdf";
	ft_printf(s);
    return 0;
}
