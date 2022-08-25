/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_map.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dtran <dtran@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 17:29:47 by dtran         #+#    #+#                 */
/*   Updated: 2022/08/24 15:13:29 by dtran         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_bg(t_data *data)
{
	int	temp_height;
	int	temp_width;

	temp_width = WIDTH;
	while (temp_width > 0)
	{
		temp_width--;
		temp_height = HEIGHT;
		while (temp_height > 0)
		{
			temp_height--;
			mlx_put_pixel(data->img, temp_width, temp_height, 0xfcba03FF);
		}
	}
}

void	get_coords(t_data *data, int x, int y, t_coords *coord)
{
	coord->x = (x - y) * cos(0.523599) * data->scale;
	coord->y = (-data->map[y][x] * data->z_scale) + (x + y) \
				* sin(0.523599) * data->scale;
	coord->x += data->offset[0];
	coord->y += data->offset[1];
}

static void	draw_x(t_data *data, int y)
{
	int			idx;
	t_coords	p1;
	t_coords	p2;

	idx = 0;
	while (idx < data->width - 1)
	{
		get_coords(data, idx, y, &p1);
		get_coords(data, idx + 1, y, &p2);
		draw_line(data, &p1, &p2);
		idx++;
	}
}

static void	draw_y(t_data *data, int x)
{
	int			idx;
	t_coords	p1;
	t_coords	p2;

	idx = 0;
	while (idx < data->height - 1)
	{
		get_coords(data, x, idx, &p1);
		get_coords(data, x, idx + 1, &p2);
		draw_line(data, &p1, &p2);
		idx++;
	}
}

void	render_map(t_data *data)
{
	int	idx;

	idx = 0;
	while (idx < data->height)
	{
		draw_x(data, idx);
		idx++;
	}
	idx = 0;
	while (idx < data->width)
	{
		draw_y(data, idx);
		idx++;
	}
}
