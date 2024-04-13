/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:13:28 by nseropia          #+#    #+#             */
/*   Updated: 2023/05/18 17:02:46 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*
	check for rogue newlines within the map and at the beginning/end
*/
int	ft_check_gap(t_game *vars)
{
	int	i;

	i = 0;
	if (vars->line[0] == '\n')
	{
		free(vars->line);
		free(vars);
		ft_error_message("Map has new lines in the beginning");
		exit(1);
	}
	while (vars->line[i] != '\0')
	{
		if (vars->line[i] == '\n' && vars->line[i + 1] == '\n')
		{
			free(vars->line);
			free(vars);
			ft_error_message("Map has gap of newlines");
			exit(1);
		}
		i++;
	}
	return (0);
}

/*
	converts the map into a 2D array
*/
int	ft_map_to_array(char **av, t_game *vars)
{
	vars->fd = open(av[1], O_RDONLY);
	if (vars->fd < 0)
	{
		free(vars);
		ft_putstr_fd("Error:\n", 2);
		ft_putendl_fd(strerror(errno), 2);
		exit(1);
	}
	vars->temp = get_next_line(vars->fd);
	if (vars->temp == NULL)
		return (ft_error_message("Map is empty"), 1);
	while (vars->temp)
	{
		vars->line = ft_gnl_strjoin(vars->line, vars->temp);
		free(vars->temp);
		vars->temp = get_next_line(vars->fd);
	}
	ft_check_gap(vars);
	vars->map = ft_split(vars->line, '\n');
	while (vars->map[vars->map_len] != NULL)
		vars->map_len++;
	return (0);
}

int	ft_check_map(t_game *vars)
{
	if (vars->map_len == 0)
		return (ft_error_message("Map is empty, nothing in it"), 1);
	if (vars->map_len < 2)
		return (ft_error_message("Map is too small"), 1);
	if (ft_check_if_rectangle(vars) == 1)
	{
		free(vars->line);
		ft_free_array(vars->map);
		free(vars);
		exit(1);
	}
	if (ft_check_wall(vars) == 1)
	{
		ft_error_message("Walls are not 1s");
		free(vars->line);
		ft_free_grid(vars->map, vars->map_len);
		free(vars);
		exit(1);
	}
	return (0);
}

/*
	check if map's edge is 1
*/
int	ft_check_wall(t_game *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (vars->line_len > i)
	{
		if (vars->map[j][i] == '1' && vars->map[vars->map_len - 1][i] == '1')
			i++;
		else
			return (1);
	}
	while (vars->map_len > j)
	{
		if (vars->map[j][0] == '1' && vars->map[j][vars->line_len - 1] == '1')
			j++;
		else
			return (1);
	}
	return (0);
}
