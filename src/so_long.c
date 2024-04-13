/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:34:21 by nseropia          #+#    #+#             */
/*   Updated: 2023/05/18 17:39:33 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_map_1(int ac, char **av, t_game *vars)
{
	ft_init_struct(vars);
	if (ft_check_file(ac, av, vars))
	{
		free(vars);
		exit(1);
	}
	if (ft_map_to_array(av, vars) == 1)
	{
		free(vars);
		exit(1);
	}
	if (ft_check_map(vars) == 1)
	{
		ft_free_grid(vars->map, vars->map_len);
		free(vars);
		exit(1);
	}
}

void	ft_map_2(t_game *vars)
{
	if (ft_count_elem(vars) == 1)
	{
		free(vars->line);
		ft_free_grid(vars->map, vars->map_len);
		free(vars);
		exit(1);
	}
	if (ft_check_count_elem(vars))
	{
		free(vars->line);
		ft_free_grid(vars->map, vars->map_len);
		free(vars);
		exit(1);
	}
	if (ft_flood_fill(vars))
	{
		free(vars->line);
		ft_free_grid(vars->map, vars->map_len);
		free(vars);
		exit(1);
	}
}

int32_t	main(int ac, char **av)
{
	void		*v_vars;
	t_game		*vars;

	vars = malloc(sizeof(t_game));
	if (!vars)
	{
		perror("malloc failed");
		exit(1);
	}
	v_vars = (void *)vars;
	ft_map_1(ac, av, vars);
	ft_map_2(vars);
	ft_parse(vars);
	mlx_terminate(vars->mlx);
	free(vars->line);
	free(vars->temp);
	ft_free_array(vars->map);
	close(vars->fd);
	free(vars);
}
