/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:39:53 by nseropia          #+#    #+#             */
/*   Updated: 2023/05/18 19:27:05 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_del_all_images(t_game *vars)
{
	mlx_delete_xpm42(vars->xpm_ground);
	mlx_delete_xpm42(vars->xpm_wall);
	mlx_delete_xpm42(vars->xpm_player);
	mlx_delete_xpm42(vars->xpm_collectible);
	mlx_delete_xpm42(vars->xpm_end);
	mlx_delete_image(vars->mlx, vars->image_ground);
	mlx_delete_image(vars->mlx, vars->image_wall);
	mlx_delete_image(vars->mlx, vars->image_player);
	mlx_delete_image(vars->mlx, vars->image_collectible);
	mlx_delete_image(vars->mlx, vars->image_end);
}

void	ft_init_assets(t_game *vars)
{
	ft_init_ground(vars);
	ft_init_wall(vars);
	ft_init_collectible(vars);
	ft_init_player(vars);
	ft_init_end(vars);
}
