/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 19:49:10 by nseropia          #+#    #+#             */
/*   Updated: 2023/05/18 16:41:11 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_put_image_ground(t_game *vars)
{
	int	i;
	int	j;

	j = 0;
	while (vars->map_len > j)
	{
		i = 0;
		while (vars->line_len > i)
		{
			if (mlx_image_to_window(vars->mlx, \
			vars->image_ground, i * 50, j * 50) == -1)
			{
				mlx_delete_xpm42(vars->xpm_ground);
				mlx_delete_image(vars->mlx, vars->image_ground);
				mlx_close_window(vars->mlx);
				return (EXIT_FAILURE);
			}
			i++;
		}
		j++;
	}
	return (0);
}

int	ft_put_image_wall(t_game *vars)
{
	int	i;
	int	j;

	j = 0;
	while (vars->map_len > j)
	{
		i = 0;
		while (vars->line_len > i)
		{
			if (vars->map[j][i] == '1')
			{
				if (mlx_image_to_window(vars->mlx, \
				vars->image_wall, i * 50, j * 50) == -1)
				{
					mlx_delete_xpm42(vars->xpm_wall);
					mlx_delete_image(vars->mlx, vars->image_wall);
					mlx_close_window(vars->mlx);
					return (EXIT_FAILURE);
				}
			}
			i++;
		}
		j++;
	}
	return (0);
}

int	ft_put_image_collectible(t_game *vars)
{
	int	i;
	int	j;

	j = 0;
	while (vars->map_len > j)
	{
		i = 0;
		while (vars->line_len > i)
		{
			if (vars->map[j][i] == 'C')
			{
				if (mlx_image_to_window(vars->mlx, \
				vars->image_collectible, i * 50, j * 50) == -1)
				{
					mlx_delete_xpm42(vars->xpm_collectible);
					mlx_delete_image(vars->mlx, vars->image_collectible);
					mlx_close_window(vars->mlx);
					return (EXIT_FAILURE);
				}
			}
			i++;
		}
		j++;
	}
	return (0);
}

int	ft_put_image_end(t_game *vars)
{
	int	i;
	int	j;

	j = 0;
	while (vars->map_len > j)
	{
		i = 0;
		while (vars->line_len > i)
		{
			if (vars->map[j][i] == 'E')
			{
				if (mlx_image_to_window(vars->mlx, \
				vars->image_end, i * 50, j * 50) == -1)
				{
					mlx_delete_xpm42(vars->xpm_end);
					mlx_delete_image(vars->mlx, vars->image_end);
					mlx_close_window(vars->mlx);
					return (EXIT_FAILURE);
				}
			}
			i++;
		}
		j++;
	}
	return (0);
}

int	ft_put_image_player(t_game *vars)
{
	int	i;
	int	j;

	j = 0;
	while (vars->map_len > j)
	{
		i = 0;
		while (vars->line_len > i)
		{
			if (vars->map[j][i] == 'P')
			{
				if (mlx_image_to_window(vars->mlx, \
				vars->image_player, i * 50, j * 50) == -1)
				{
					mlx_delete_xpm42(vars->xpm_player);
					mlx_delete_image(vars->mlx, vars->image_player);
					mlx_close_window(vars->mlx);
					return (EXIT_FAILURE);
				}
			}
			i++;
		}
		j++;
	}
	return (0);
}
