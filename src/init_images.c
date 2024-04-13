/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:38:04 by nseropia          #+#    #+#             */
/*   Updated: 2023/05/18 19:25:59 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_init_player(t_game *vars)
{
	vars->xpm_player = mlx_load_xpm42("./sprite/xpm/front.xpm42");
	if (!vars->xpm_player)
	{
		ft_mlx_error();
		mlx_terminate(vars->mlx);
		exit (1);
	}
	vars->image_player = mlx_texture_to_image(vars->mlx, \
	&vars->xpm_player->texture);
	if (!vars->image_player)
	{
		mlx_delete_xpm42(vars->xpm_player);
		mlx_delete_image(vars->mlx, vars->image_player);
		ft_mlx_error();
	}
}

void	ft_init_ground(t_game *vars)
{
	vars->xpm_ground = mlx_load_xpm42("./sprite/xpm/ground.xpm42");
	if (!vars->xpm_ground)
	{
		ft_mlx_error();
		mlx_terminate(vars->mlx);
		exit (1);
	}
	vars->image_ground = mlx_texture_to_image(vars->mlx, \
	&vars->xpm_ground->texture);
	if (!vars->image_ground)
	{
		mlx_delete_xpm42(vars->xpm_ground);
		mlx_delete_image(vars->mlx, vars->image_ground);
		ft_mlx_error();
	}
}

void	ft_init_wall(t_game *vars)
{
	vars->xpm_wall = mlx_load_xpm42("./sprite/xpm/tree.xpm42");
	if (!vars->xpm_wall)
	{
		ft_mlx_error();
		mlx_terminate(vars->mlx);
		exit (1);
	}
	vars->image_wall = mlx_texture_to_image(vars->mlx, \
	&vars->xpm_wall->texture);
	if (!vars->image_wall)
	{
		mlx_delete_xpm42(vars->xpm_wall);
		mlx_delete_image(vars->mlx, vars->image_wall);
		ft_mlx_error();
	}
}

void	ft_init_collectible(t_game *vars)
{
	vars->xpm_collectible = mlx_load_xpm42("./sprite/xpm/wine.xpm42");
	if (!vars->xpm_collectible)
	{
		ft_mlx_error();
		mlx_terminate(vars->mlx);
		exit (1);
	}
	vars->image_collectible = mlx_texture_to_image(vars->mlx, \
	&vars->xpm_collectible->texture);
	if (!vars->image_collectible)
	{
		mlx_delete_xpm42(vars->xpm_collectible);
		mlx_delete_image(vars->mlx, vars->image_collectible);
		ft_mlx_error();
	}
}

void	ft_init_end(t_game *vars)
{
	vars->xpm_end = mlx_load_xpm42("./sprite/xpm/bed.xpm42");
	if (!vars->xpm_end)
	{
		ft_mlx_error();
		mlx_terminate(vars->mlx);
		exit (1);
	}
	vars->image_end = mlx_texture_to_image(vars->mlx, &vars->xpm_end->texture);
	if (!vars->image_end)
	{
		mlx_delete_xpm42(vars->xpm_end);
		mlx_delete_image(vars->mlx, vars->image_end);
		ft_mlx_error();
	}
}
