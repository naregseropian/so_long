/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:07:19 by nseropia          #+#    #+#             */
/*   Updated: 2023/05/18 16:59:09 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// t_game map;
// ft_read_map(&map);
// map.map = malloc(...);

// t_game *map;
// map = malloc(sizeof(t_game));
// map->map = malloc(...);

/*
	checks attributes of the file
*/
int	ft_check_file(int ac, char **av, t_game *vars)
{
	if (ac != 2)
		ft_error_message("Please input one file!");
	vars->arg_len = ft_strlen(av[1]);
	if (!vars->arg_len)
	{
		ft_error_message("Please input a file");
		return (1);
	}
	if (ft_strncmp(av[1] + vars->arg_len - 4, ".ber", 4) != 0)
	{
		ft_error_message("Please input a .ber file");
		return (1);
	}
	return (0);
}

/*
	check if map is rectangle
*/
int	ft_check_if_rectangle(t_game *vars)
{
	vars->line_len = 0;
	vars->map_len = 0;
	while (vars->map[vars->map_len] != NULL)
	{
		if (vars->line_len == 0)
		{
			vars->line_len = ft_gnl_strlen(vars->map[vars->map_len]);
			vars->map_len++;
		}
		else if ((ft_gnl_strlen(vars->map[vars->map_len]) == vars->line_len))
			vars->map_len++;
		else if ((ft_gnl_strlen(vars->map[vars->map_len]) != vars->line_len) && \
		(vars->map_len == (vars->map_len - 1)))
			vars->map_len++;
		else
		{
			ft_error_message("Map is not rectangular");
			return (1);
		}
	}
	return (0);
}

int	ft_count_elem_utils(t_game *vars, int i, int j)
{
	if (vars->map[j][i] == 'P')
	{
		vars->num_p++;
		vars->p_x = i;
		vars->p_y = j;
		i++;
		return (0);
	}
	else if (vars->map[j][i] == 'C')
	{
		vars->num_c++;
		i++;
		return (0);
	}
	else if (vars->map[j][i] == 'E')
	{
		vars->num_e++;
		i++;
		return (0);
	}
	else if (vars->map[j][i] == '0' || vars->map[j][i] == '1')
		return (i++, 0);
	else
		return (1);
}

/*
	count the P, E, C and find the coordinates of P x and y
*/
int	ft_count_elem(t_game *vars)
{
	int	j;
	int	i;

	j = 0;
	while (vars->map_len > j)
	{
		i = 0;
		while (vars->line_len > i)
		{
			if (ft_count_elem_utils(vars, i, j) == 1)
			{
				return (ft_error_message("Map contains invalid elements"), 1);
			}
			i++;
		}
		j++;
	}
	return (0);
}

int	ft_check_count_elem(t_game *vars)
{
	if (vars->num_p == 0 || vars->num_e == 0 || vars->num_c == 0)
	{
		ft_error_message("Invalid map. E, P or C missing");
		return (1);
	}
	if (vars->num_e > 1)
	{
		ft_error_message("Number of E is more than one");
		return (1);
	}
	if (vars->num_p > 1)
	{
		ft_error_message("Number of P is more than one");
		return (1);
	}
	return (0);
}
