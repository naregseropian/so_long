/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:09:18 by nseropia          #+#    #+#             */
/*   Updated: 2023/01/30 12:48:08 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * check_type - check that character is a valid specifier
 * and assigns an appraopriate function for its printing.
 * 
 * 
 * @return: pointer to a function
 */

#include "ft_printf.h"

int	check_type(char c, va_list args)
{
	if (c == '%')
		return (ft_putchar('%'));
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'u')
		return (ft_putuns(va_arg(args, unsigned int)));
	if (c == 'x' || c == 'X')
		return (ft_puthex(va_arg(args, unsigned int), c));
	if (c == 'p')
		return (ft_putptr(va_arg(args, unsigned long)));
	return (0);
}
