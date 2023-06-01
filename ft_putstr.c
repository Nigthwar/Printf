/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguerrei <cguerrei@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:04:54 by cguerrei          #+#    #+#             */
/*   Updated: 2023/06/01 16:25:19 by cguerrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//imprime un caracter dado por parametro
int	ft_putchar(int a)
{
	write(1, &a, 1);
	return (1);
}
//escribe la str pasado por comando

int	ft_putstr(char *str)

{
	int	x;

	x = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[x])
	{
		write(1, &str[x], 1);
		x++;
	}
	return (x);
}
/*imprime la direccion de memoria
en Hexadecimal con el prefijo "0x" y 2 como formato*/

int	ft_putptr(unsigned long ptr)

{
	int	x;

	x = 2;
	write(1, "0x", 2);
	x += ft_puthexa(ptr, 0);
	return (x);
}
//divide en fragmentos de 16 la direccion de memoria dada de forma recursiva

int	ft_puthexa(unsigned long long num, int spc)

{
	unsigned long long	x;

	x = 0;
	if (num >= 16)
		x += ft_puthexa(num / 16, spc);
	if (spc == 0)
		ft_putchar("0123456789abcdef"[num % 16]);
	else
		ft_putchar("0123456789ABCDEF"[num % 16]);
	x++;
	return (x);
}
/*
 ▄████▄    ▄████  █    ██ ▓█████  ██▀███   ██▀███  ▓█████  ██▓    
▒██▀ ▀█   ██▒ ▀█▒ ██  ▓██▒▓█   ▀ ▓██ ▒ ██▒▓██ ▒ ██▒▓█   ▀ ▓██▒    
▒▓█    ▄ ▒██░▄▄▄░▓██  ▒██░▒███   ▓██ ░▄█ ▒▓██ ░▄█ ▒▒███   ▒██▒    
▒▓▓▄ ▄██▒░▓█  ██▓▓▓█  ░██░▒▓█  ▄ ▒██▀▀█▄  ▒██▀▀█▄  ▒▓█  ▄ ░██░    
▒ ▓███▀ ░░▒▓███▀▒▒▒█████▓ ░▒████▒░██▓ ▒██▒░██▓ ▒██▒░▒████▒░██░    
░ ░▒ ▒  ░ ░▒   ▒ ░▒▓▒ ▒ ▒ ░░ ▒░ ░░ ▒▓ ░▒▓░░ ▒▓ ░▒▓░░░ ▒░ ░░▓      
  ░  ▒     ░   ░ ░░▒░ ░ ░  ░ ░  ░  ░▒ ░ ▒░  ░▒ ░ ▒░ ░ ░  ░ ▒ ░    
░        ░ ░   ░  ░░░ ░ ░    ░     ░░   ░   ░░   ░    ░    ▒ ░    
░ ░            ░    ░        ░  ░   ░        ░        ░  ░ ░      
░                                                                 
 ▄████▄   ▒█████   ███▄ ▄███▓ ██▓███   ██▓ ██▓    ▓█████   ██████ 
▒██▀ ▀█  ▒██▒  ██▒▓██▒▀█▀ ██▒▓██░  ██▒▓██▒▓██▒    ▓█   ▀ ▒██    ▒ 
▒▓█    ▄ ▒██░  ██▒▓██    ▓██░▓██░ ██▓▒▒██▒▒██░    ▒███   ░ ▓██▄   
▒▓▓▄ ▄██▒▒██   ██░▒██    ▒██ ▒██▄█▓▒ ▒░██░▒██░    ▒▓█  ▄   ▒   ██▒
▒ ▓███▀ ░░ ████▓▒░▒██▒   ░██▒▒██▒ ░  ░░██░░██████▒░▒████▒▒██████▒▒
░ ░▒ ▒  ░░ ▒░▒░▒░ ░ ▒░   ░  ░▒▓▒░ ░  ░░▓  ░ ▒░▓  ░░░ ▒░ ░▒ ▒▓▒ ▒ ░
  ░  ▒     ░ ▒ ▒░ ░  ░      ░░▒ ░      ▒ ░░ ░ ▒  ░ ░ ░  ░░ ░▒  ░ ░
░        ░ ░ ░ ▒  ░      ░   ░░        ▒ ░  ░ ░      ░   ░  ░  ░  
░ ░          ░ ░         ░             ░      ░  ░   ░  ░      ░  
*/