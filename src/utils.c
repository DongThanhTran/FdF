/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dtran <dtran@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 15:48:02 by dtran         #+#    #+#                 */
/*   Updated: 2022/08/25 17:35:58 by dtran         ########   odam.nl         */
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

void	free_map_int(t_data	*tab)
{
	int	idx;

	idx = 0;
	while (idx < tab->height)
	{
		free(tab->map[idx]);
		idx++;
	}
	free(tab->map);
}
