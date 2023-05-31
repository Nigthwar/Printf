/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguerrei <cguerrei@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:03:50 by cguerrei          #+#    #+#             */
/*   Updated: 2023/05/31 18:43:01 by cguerrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_counter(long x)
{
	size_t	c;

	c = 0;
	if (x <= 0)
		c++;
	while (x != 0)
	{
		x /= 10;
		c++;
	}
	return (c);
}

static int	ft_unsigCounter(unsigned int n)
{
	int	num;

	num = 0;

	if (n == 0)
	{
		num++;
	}
	while (n != 0)
	{
		n /= 10;
		num++;
	}
	return (num);
}

char	*ft_itoa(long n)
{
	char	*str;
	size_t	len;
	long	num;

	num = n;
	len = ft_counter(num);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len--] = '\0';
	if (num == 0)
		str[0] = '0';
	if (num < 0)
	{
		str[0] = '-';
		num = num * -1;
	}
	while (num > 0)
	{
		str[len] = (num % 10) + '0';
		num = num / 10;
		len--;
	}
	return (str);
}

int	ft_putnbr(int n)
{
	char	*str;
	int		num;

	str = ft_itoa(n);
	num = ft_putstr(str);
	free(str);
	return (num);
}

int	ft_unsigitoa(unsigned int n)
{
	int	cnt;
	int	aux;

	cnt = ft_unsigCounter(n);
	if (n > 9)
	{
		ft_unsigitoa(n / 10);
		ft_unsigitoa(n % 10);
	}
	else
	{
		aux = n + 48;
		write(1, &aux, 1);
	}
	return (cnt);
}

int	ft_unsigputnbr(unsigned int nb)

{
	int count;

	count = ft_unsigitoa(nb);

	return (count);
}
