/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguerrei <cguerrei@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:06:30 by cguerrei          #+#    #+#             */
/*   Updated: 2023/05/22 19:55:46 by cguerrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

/*
Bibliotecas necesarias para los programas.
*/
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <strings.h>
# include <unistd.h>

/*
Programas
*/

int			ft_printf(char const *str, ...);
int			ft_putchar(int a);
int			ft_putstr(char *str);
int			ft_putptr(unsigned long ptr);
int			ft_puthexa(unsigned long long num, int spc);
char		*ft_itoa(long n);
int			ft_putnbr(int n);
char		*ft_unsigitoa(unsigned int n);
int			ft_unsigputnbr(unsigned int nb);
int			ft_comprobador(va_list obj, const char str, int contador);
#endif
