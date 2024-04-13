/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:12:20 by nseropia          #+#    #+#             */
/*   Updated: 2023/01/30 12:48:14 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* %x Prints a number in hexadecimal (base 16) lowercase format.
%X Prints a number in hexadecimal (base 16) uppercase format. */

#include "ft_printf.h"

int	ft_puthex(unsigned int nbr, char c)
{
	int	count;

	count = 0;
	if (nbr < 16)
	{	
		if (nbr <= 9)
			count += ft_putchar(nbr + '0');
		else
		{
			if (c == 'x')
				count += ft_putchar(nbr + 87);
			if (c == 'X')
				count += ft_putchar(nbr + 55);
		}
	}
	if (nbr >= 16)
	{
		count += ft_puthex(nbr / 16, c);
		count += ft_puthex(nbr % 16, c);
	}
	return (count);
}
