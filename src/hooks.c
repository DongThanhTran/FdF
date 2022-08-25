/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dtran <dtran@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/24 15:38:03 by dtran         #+#    #+#                 */
/*   Updated: 2022/08/25 19:00:52 by dtran         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	cleanup(t_data *data)
{
	free_map_int(data);
	exit (0);
}

static void	zoom(t_data *data, mlx_key_data_t key_data)
{
	if (key_data.key == MLX_KEY_Q)
		data->scale += 1;
	else if (key_data.key == MLX_KEY_E)
	{
		data->scale -= 1;
		if (data->scale < 1)
			data->scale += 1;
	}
	if (key_data.key == MLX_KEY_O)
		data->z_scale += 1;
	else if (key_data.key == MLX_KEY_P)
		data->z_scale -= 1;
}

static void	key(mlx_key_data_t key_data, t_data *data)
{
	if (key_data.action == MLX_RELEASE)
		return ;
	if (key_data.key == MLX_KEY_D)
		data->offset[0] += 10;
	if (key_data.key == MLX_KEY_A)
		data->offset[0] -= 10;
	if (key_data.key == MLX_KEY_W)
		data->offset[1] -= 10;
	if (key_data.key == MLX_KEY_S)
		data->offset[1] += 10;
	if (key_data.key == MLX_KEY_ESCAPE)
		cleanup(data);
	zoom(data, key_data);
}

void	key_hook(mlx_key_data_t key_data, void *data)
{
	t_data	*cast_data;

	cast_data = (t_data *)data;
	key(key_data, data);
	fill_bg(data);
	render_map(data);
	mlx_image_to_window(cast_data->mlx, cast_data->img, 0, 0);
}
