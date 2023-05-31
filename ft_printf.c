/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguerrei <cguerrei@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:02:51 by cguerrei          #+#    #+#             */
/*   Updated: 2023/05/31 15:58:50 by cguerrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_comprobador(va_list obj, const char str, int contador)
{
	if (str == 'c')
		contador += ft_putchar(va_arg(obj, int));
	else if (str == 's')
		contador += ft_putstr(va_arg(obj, char *));
	else if (str == 'p')
		contador += ft_putptr(va_arg(obj, unsigned long));
	else if (str == 'd' || str == 'i')
		contador += ft_putnbr(va_arg(obj, int));
	else if (str == 'u')
		contador += ft_unsigputnbr(va_arg(obj, unsigned int));
	else if (str == 'x')
		contador += ft_puthexa(va_arg(obj, unsigned int), 0);
	else if (str == 'X')
		contador += ft_puthexa(va_arg(obj, unsigned int), 1);
	else if (str == '%')
		contador += ft_putchar('%');
	return (contador);
}

int	ft_printf(char const *str, ...)

{
	int			unidad;
	int			x;
	int			count;
	va_list		arg_list;

	va_start(arg_list, str);
	unidad = 0;
	x = 0;
	count = 0;
	while (str[x])
	{
		if (str[x] == '%')
		{
			unidad += ft_comprobador(arg_list, str[x + 1], count);
			x++;
		}
		else
		{
			unidad += ft_putchar(str[x]);
		}
		x++;
	}
	va_end(arg_list);
	return (unidad);
}
