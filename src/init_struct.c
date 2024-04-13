/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:24:28 by nseropia          #+#    #+#             */
/*   Updated: 2023/05/18 16:41:08 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_init_struct(t_game *v)
{
	v->fd = 0;
	v->arg_len = 0;
	v->temp = NULL;
	v->line = NULL;
	v->map = NULL;
	v->map_len = 0;
	v->line_len = 0;
	v->num_c = 0;
	v->num_p = 0;
	v->num_e = 0;
	v->p_x = 0;
	v->p_y = 0;
	v->moves = 0;
}
