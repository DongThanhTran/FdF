/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dtran <dtran@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/14 16:43:48 by dtran         #+#    #+#                 */
/*   Updated: 2022/09/29 11:59:36 by dtran         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 1512
# define HEIGHT 982

# define COLOR_LINE 0x00FFFFFF

# include <math.h>
# include <libft.h>
# include <get_next_line.h>
# include "../include/MLX42/include/MLX42/MLX42.h"

typedef struct s_coords
{
	int	x;
	int	y;
}	t_coords;

typedef struct s_data
{
	int			width;
	int			height;
	int			**map;
	int			scale;
	int			z_scale;
	int			offset[2];

	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_data;

void	read_file(char *file_name, t_data *data);
void	free_map_char(char **map);
void	free_map_int(t_data	*data);
void	get_coords(t_data *data, int x, int y, t_coords *coord);
void	fill_bg(t_data *data);
void	render_map(t_data *data);
void	draw_line(t_data *data, t_coords *a, t_coords *b);
int		center_map(t_data *data);
void	key_hook(mlx_key_data_t key_data, void *data);
void	free_exit(t_data *data, char *err_message);

#endif