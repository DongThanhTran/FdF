/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dtran <dtran@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/22 16:43:24 by dtran         #+#    #+#                 */
/*   Updated: 2022/08/25 17:35:45 by dtran         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	ft_checkmalloc(data);
	if (argc < 2)
		ft_error_exit("too few args", 1);
	read_file(argv[1], data);
	data->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!data->mlx)
		ft_error_exit("failed to initialize mlx", 1);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->scale = 26;
	data->z_scale = 2;
	mlx_image_to_window(data->mlx, data->img, 0, 0);
	fill_bg(data);
	center_map(data);
	render_map(data);
	mlx_key_hook(data->mlx, &key_hook, data);
	mlx_loop(data->mlx);
	mlx_delete_image(data->mlx, data->img);
	mlx_terminate(data->mlx);
	return (0);
}
