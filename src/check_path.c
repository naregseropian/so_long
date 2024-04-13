/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:18:49 by nseropia          #+#    #+#             */
/*   Updated: 2023/05/18 16:41:07 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_check_path(t_game *temp, int p_y, int p_x)
{
	if (temp->map[p_y][p_x] == '1')
		return (0);
	if (temp->map[p_y][p_x] == 'C')
		temp->num_c -= 1;
	if (temp->map[p_y][p_x] == 'E')
	{	
		temp->num_e = 1;
		return (0);
	}
	temp->map[p_y][p_x] = '1';
	if (ft_check_path(temp, p_y, p_x - 1))
		return (1);
	if (ft_check_path(temp, p_y, p_x + 1))
		return (1);
	if (ft_check_path(temp, p_y - 1, p_x))
		return (1);
	if (ft_check_path(temp, p_y + 1, p_x))
		return (1);
	return (0);
}

int	ft_flood_fill(t_game *vars)
{
	t_game	temp;
	int		i;

	temp.map_len = vars->map_len;
	temp.line_len = vars->line_len;
	temp.num_c = vars->num_c;
	temp.p_x = vars->p_x;
	temp.p_y = vars->p_y;
	temp.num_e = 0;
	temp.map = (char **)malloc(temp.map_len * sizeof(char *));
	if (!temp.map)
		return (ft_error_message("temp.map Malloc failed"), 1);
	i = 0;
	while (i < temp.map_len)
	{
		temp.map[i] = ft_strdup(vars->map[i]);
		i++;
	}
	ft_check_path(&temp, temp.p_y, temp.p_x);
	if (!(temp.num_e == 1 && temp.num_c == 0))
		return (ft_free_grid(temp.map, temp.map_len), \
		ft_error_message("No valid path available"), 1);
	ft_free_grid(temp.map, temp.map_len);
	return (0);
}
