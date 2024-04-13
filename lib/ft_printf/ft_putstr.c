/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:12:38 by nseropia          #+#    #+#             */
/*   Updated: 2023/01/30 12:48:19 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* %s Prints a string (as defined by the common C convention). */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{
		write(1, &(str[i]), 1);
		i++;
	}
	return (i);
}
