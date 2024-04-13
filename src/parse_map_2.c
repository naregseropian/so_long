/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 22:09:40 by nseropia          #+#    #+#             */
/*   Updated: 2023/05/18 17:39:17 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_put_all_images(t_game *vars)
{
	if (ft_put_image_ground(vars) == 1)
		mlx_terminate(vars->mlx);
	if (ft_put_image_wall(vars) == 1)
		mlx_terminate(vars->mlx);
	if (ft_put_image_collectible(vars) == 1)
		mlx_terminate(vars->mlx);
	if (ft_put_image_end(vars) == 1)
		mlx_terminate(vars->mlx);
	if (ft_put_image_player(vars) == 1)
		mlx_terminate(vars->mlx);
	return (0);
}

int	ft_check_collectible_image(t_game *vars)
{
	if (vars->map[vars->image_player->\
	instances[0].y / 50][vars->image_player->instances[0].x / 50] == 'C')
	{	
		vars->num_c -= 1;
		return (1);
	}
	return (0);
}

void	ft_open_exit(t_game *vars)
{
	int	x;
	int	y;

	y = vars->image_player->instances[0].y / 50;
	x = vars->image_player->instances[0].x / 50;
	if (vars->map[y][x] == 'E')
		mlx_close_window(vars->mlx);
}
