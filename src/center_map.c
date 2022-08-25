/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   center_map.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dtran <dtran@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/24 15:22:00 by dtran         #+#    #+#                 */
/*   Updated: 2022/08/25 17:34:43 by dtran         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	center_map(t_data *data)
{
	t_coords	a;
	t_coords	b;

	while (1)
	{
		get_coords(data, 0, 0, &a);
		get_coords(data, data->width - 1, data->height - 1, &b);
		data->offset[0] = (WIDTH / 2) - (abs(a.x - b.x) / 2);
		data->offset[1] = (HEIGHT / 2) - (abs(a.y - b.y) / 2);
		if (abs(a.x - b.x) > 1920 || abs(a.y - b.y) > 1080)
		{
			data->scale--;
			continue ;
		}
		break ;
	}
	return (0);
}
