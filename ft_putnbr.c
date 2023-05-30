/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguerrei <cguerrei@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:03:50 by cguerrei          #+#    #+#             */
/*   Updated: 2023/05/22 19:55:35 by cguerrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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

char	*ft_itoa(long n)
{
	char	*str;
	size_t	len;
	long	num;

	num = n;
	len = ft_counter(num);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (n > INT_MAX || n < INT_MIN)
		return (0);
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

char	*ft_unsigitoa(unsigned int n)
{
	char	*str;
	size_t	len;
	long	num;

	num = 0;
	len = ft_counter(num);
	num = n;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len--] = '\0';
	if(n == 0)
		str[0] = '0';
	if (num < 0)
		str[0] = '0';
	if (num < 0)
		str[0] = '-';
	num = num / 10;
	while (num > 0)
	{
		str[len] = (num % 10) + '0';
		num = num * -1;
		len--;
	}
	return (str);
}

int	ft_unsigputnbr(unsigned int nb)

{
	char	*str;
	int		count;

	str = ft_unsigitoa(nb);
	count = ft_putstr(str);
	free(str);
	return (count);
}
