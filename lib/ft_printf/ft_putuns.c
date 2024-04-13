/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:14:58 by nseropia          #+#    #+#             */
/*   Updated: 2023/01/30 12:48:48 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* %u Prints an unsigned decimal (base 10) number. */

#include "ft_printf.h"

int	ft_putuns(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr < 10)
	{	
		count += ft_putchar(nbr + '0');
	}
	if (nbr >= 10)
	{
		count += ft_putuns(nbr / 10);
		count += ft_putuns(nbr % 10);
	}
	return (count);
}
