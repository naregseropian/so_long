/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:13:34 by nseropia          #+#    #+#             */
/*   Updated: 2023/01/30 12:48:16 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* %p The void * pointer argument has to be printed in hexadecimal format. */

#include "ft_printf.h"

int	ft_putptr(unsigned long ptr)
{
	int	count;

	count = 0;
	if (!ptr)
		return (write(1, "(nil)", 5));
	count += write(1, "0x", 2);
	count += ft_putptr_2(ptr);
	return (count);
}

int	ft_putptr_2(unsigned long ptr)
{
	int	count;

	count = 0;
	if (ptr < 16)
	{	
		if (ptr <= 9)
			count += ft_putchar(ptr + '0');
		else
			count += ft_putchar(ptr + 87);
	}
	if (ptr >= 16)
	{
		count += ft_putptr_2(ptr / 16);
		count += ft_putptr_2(ptr % 16);
	}
	return (count);
}
