/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dtran <dtran@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/14 16:47:28 by dtran         #+#    #+#                 */
/*   Updated: 2022/07/14 17:41:29 by dtran         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(void)
{
	t_init	fdf;
	int	i = 0;

	fdf.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!fdf.mlx)
		ft_error_exit("failed to initialize mlx", 1);
	fdf.img = mlx_new_image(fdf.mlx, WIDTH, HEIGHT);
	while (i < 10)
	{
		mlx_put_pixel(fdf.img, (WIDTH / 2) + i , (HEIGHT / 2) + i, 0xFFFFFFFF);
		i++;
	}
	mlx_image_to_window(fdf.mlx, fdf.img, 0, 0);
	mlx_loop(fdf.mlx);
	mlx_terminate(fdf.mlx);
}