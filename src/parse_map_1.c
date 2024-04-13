/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 19:37:10 by nseropia          #+#    #+#             */
/*   Updated: 2023/05/18 17:59:03 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_hide_collectible(t_game *vars)
{
	int	i;
	int	x;
	int	y;

	y = vars->image_player->instances[0].y / 50;
	x = vars->image_player->instances[0].x / 50;
	if (vars->map[y][x] == 'C')
	{
		i = 0;
		while (i < vars->image_collectible->count)
		{
			if (vars->image_collectible->instances[i].y / 50 == y \
			&& vars->image_collectible->instances[i].x / 50 == x)
			{
				vars->num_c -= 1;
				vars->image_collectible->instances[i].z = 0;
				vars->map[vars->image_collectible->\
				instances[i].y / 50] \
				[vars->image_collectible->instances[i].x / 50] = '0';
			}
			i++;
		}
	}
	if (vars->num_c == 0)
		ft_open_exit(vars);
}

void	ft_key_func_utils(mlx_key_data_t keydata, t_game *v_vars)
{
	if ((keydata.key) == 256)
		mlx_close_window(v_vars->mlx);
	if ((keydata.key) == MLX_KEY_W && ((keydata.action) == 1 || \
		(keydata.action) == 2) && v_vars->map[(v_vars->p_y - 50) / 50] \
	[v_vars->p_x / 50] != '1')
	{
		v_vars->image_player->instances[0].y -= 50;
		v_vars->moves++;
		ft_printf("Moves: %i\n", v_vars->moves);
	}
	if ((keydata.key) == MLX_KEY_S && ((keydata.action) == 1 || \
	(keydata.action) == 2) && v_vars->map[(v_vars->p_y + 50) / 50] \
	[v_vars->p_x / 50] != '1')
	{
		v_vars->image_player->instances[0].y += 50;
		v_vars->moves++;
		ft_printf("Moves: %i\n", v_vars->moves);
	}
}

void	ft_key_func(mlx_key_data_t keydata, void *vars)
{
	t_game	*v_vars;

	v_vars = (t_game *) vars;
	ft_key_func_utils(keydata, v_vars);
	if ((keydata.key) == MLX_KEY_A && ((keydata.action) == 1 || \
	(keydata.action) == 2) && v_vars->map[v_vars->p_y / 50] \
	[(v_vars->p_x - 50) / 50] != '1')
	{
		v_vars->image_player->instances[0].x -= 50;
		v_vars->moves++;
		ft_printf("Moves: %i\n", v_vars->moves);
	}
	if ((keydata.key) == MLX_KEY_D && ((keydata.action) == 1 || \
	(keydata.action) == 2) && v_vars->map[v_vars->p_y / 50] \
	[(v_vars->p_x + 50) / 50] != '1')
	{
		v_vars->image_player->instances[0].x += 50;
		v_vars->moves++;
		ft_printf("Moves: %i\n", v_vars->moves);
	}
	ft_hide_collectible(v_vars);
}

void	ft_hook(void *vars)
{
	t_game	*v_vars;

	v_vars = (t_game *) vars;
	v_vars->p_x = v_vars->image_player->instances[0].x;
	v_vars->p_y = v_vars->image_player->instances[0].y;
	mlx_key_hook(v_vars->mlx, ft_key_func, vars);
}

int	ft_parse(t_game *vars)
{
	void		*v_vars;

	v_vars = (void *)vars;
	vars->mlx = mlx_init(vars->line_len * 50, vars->map_len * 50, \
	"Drunk Cat", true);
	if (!vars->mlx)
		return (EXIT_FAILURE);
	ft_init_assets(vars);
	ft_put_all_images(vars);
	mlx_loop_hook(vars->mlx, ft_hook, v_vars);
	mlx_loop(vars->mlx);
	ft_del_all_images(vars);
	return (0);
}
