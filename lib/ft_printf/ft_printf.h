/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:41:12 by nseropia          #+#    #+#             */
/*   Updated: 2023/01/30 12:43:25 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>

int		ft_printf(const char *format, ...);
char	*ft_strchr(const char *s, int c);
int		check_type(char c, va_list args);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_putnbr(int nbr);
int		ft_putuns(unsigned int nbr);
int		ft_puthex(unsigned int nbr, char c);
int		ft_putptr(unsigned long ptr);
int		ft_putptr_2(unsigned long ptr);

#endif