/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dtran <dtran@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 15:48:02 by dtran         #+#    #+#                 */
/*   Updated: 2022/09/01 13:44:39 by dtran         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_map_char(char **map)
{
	int	idx;

	idx = 0;
	while (map[idx])
	{
		free(map[idx]);
		idx++;
	}
	free(map);
}

void	free_map_int(t_data	*data)
{
	int	idx;

	idx = 0;
	while (idx < data->height)
	{
		free(data->map[idx]);
		idx++;
	}
	free(data->map);
}

void	free_exit(t_data *data, char *err_message)
{
	free_map_int(data);
	ft_error_exit(err_message, 1);
}
