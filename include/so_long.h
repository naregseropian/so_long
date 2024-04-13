/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:41:09 by nseropia          #+#    #+#             */
/*   Updated: 2023/05/18 19:27:10 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include <errno.h>
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"

typedef struct s_game{
	int				fd;
	int				arg_len;
	char			*temp;
	char			*line;
	char			**map;
	int				map_len;
	int				line_len;
	int				num_c;
	int				num_p;
	int				num_e;
	int				p_x;
	int				p_y;
	int				moves;
	mlx_t			*mlx;
	mlx_t			*win;
	mlx_image_t		*image_player;
	mlx_image_t		*image_ground;
	mlx_image_t		*image_wall;
	mlx_image_t		*image_collectible;
	mlx_image_t		*image_end;
	mlx_texture_t	*texture_player;
	mlx_texture_t	*texture_ground;
	mlx_texture_t	*texture_wall;
	mlx_texture_t	*texture_collectible;
	mlx_texture_t	*texture_end;
	xpm_t			*xpm_player;
	xpm_t			*xpm_ground;
	xpm_t			*xpm_wall;
	xpm_t			*xpm_collectible;
	xpm_t			*xpm_end;
}	t_game;

/*
	CHECK_MAP_1
*/
int		ft_check_file(int ac, char **av, t_game *vars);
int		ft_check_if_rectangle(t_game *vars);
int		ft_count_elem(t_game *vars);
int		ft_check_count_elem(t_game *vars);
int		ft_count_elem_utils(t_game *vars, int i, int j);
/*
	CHECK_MAP_2
*/
int		ft_check_gap(t_game *vars);
int		ft_map_to_array(char **av, t_game *vars);
int		ft_check_map(t_game *vars);
int		ft_check_wall(t_game *vars);
/*
	CHECK_PATH
*/
int		ft_check_path(t_game *temp, int p_y, int p_x);
int		ft_flood_fill(t_game *vars);
/*
	INIT_STRUCT
*/
void	ft_init_struct(t_game *v);
/*
	PARSE_MAP
*/
void	ft_hide_collectible(t_game *vars);
void	ft_key_func(mlx_key_data_t keydata, void *vars);
void	ft_hook(void *vars);
int		ft_parse(t_game *vars);
/*
	PARSE_MAP
*/
int		ft_put_all_images(t_game *vars);
int		ft_check_wall_image(int i, t_game *vars);
int		ft_check_collectible_image(t_game *vars);
void	ft_open_exit(t_game *vars);
/*
	PUT_IMAGE
*/
int		ft_put_image_ground(t_game *vars);
int		ft_put_image_wall(t_game *vars);
int		ft_put_image_collectible(t_game *vars);
int		ft_put_image_end(t_game *vars);
int		ft_put_image_player(t_game *vars);
/*
	INIT_IMAGES
*/
void	ft_init_player(t_game *vars);
void	ft_init_ground(t_game *vars);
void	ft_init_wall(t_game *vars);
void	ft_init_collectible(t_game *vars);
void	ft_init_end(t_game *vars);
/*
	SO_LONG
*/
void	ft_map_1(int ac, char **av, t_game *vars);
void	ft_map_2(t_game *vars);
/*
	SO_LONG_UTILS
*/
void	ft_free_array(char **arr);
void	ft_free_grid(char **grid, int height);
void	ft_mlx_error(void);
int		ft_error_message(char *msg);
/*
	SO_LONG_UTILS_2
*/
void	ft_del_all_images(t_game *vars);
void	ft_init_assets(t_game *vars);
int		ft_put_all_images(t_game *vars);

#endif
