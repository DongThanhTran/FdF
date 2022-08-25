/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dtran <dtran@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/24 12:36:35 by dtran         #+#    #+#                 */
/*   Updated: 2022/08/25 17:35:29 by dtran         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_select(int val, int a, int b)
{
	if (val)
		return (a);
	return (b);
}

static void	setup(t_coords *a, t_coords *b, int	*delta_input, int *incr)
{
	delta_input[0] = abs(a->x - b->x);
	delta_input[1] = abs(a->y - b->y);
	incr[0] = ft_select(b->x < a->x, 1, -1);
	incr[1] = ft_select(b->y < a->y, 1, -1);
}

void	draw_line(t_data *data, t_coords *a, t_coords *b)
{
	int	delta_input[2];
	int	incr[2];
	int	error[2];
	int	error_check;

	setup(a, b, delta_input, incr);
	error_check = 2 * (delta_input[1] - delta_input[0]);
	error[0] = b->x;
	error[1] = b->y;
	while (1)
	{
		mlx_put_pixel(data->img, error[0], error[1], COLOR_LINE);
		if (error[0] == a->x && error[1] <= a->y)
			break ;
		if (error_check >= 0)
		{
			error[1] += incr[1];
			error_check -= 2 * delta_input[0];
		}
		if (error_check < 0)
		{
			error[0] += incr[0];
			error_check += 2 * delta_input[1];
		}
	}
}
