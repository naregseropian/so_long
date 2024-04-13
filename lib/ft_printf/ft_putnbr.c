/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:12:31 by nseropia          #+#    #+#             */
/*   Updated: 2023/01/30 12:48:21 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* %d Prints a decimal (base 10) number.
%i Prints an integer in base 10. */

#include "ft_printf.h"

int	ft_putnbr(int nbr)
{
	int	count;

	count = 0;
	if (nbr == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nbr >= 0 && nbr < 10)
	{	
		count += ft_putchar(nbr + '0');
	}
	if (nbr < 0)
	{
		count += ft_putchar('-');
		count += ft_putnbr(nbr * -1);
	}
	if (nbr >= 10)
	{
		count += ft_putnbr(nbr / 10);
		count += ft_putnbr(nbr % 10);
	}
	return (count);
}
