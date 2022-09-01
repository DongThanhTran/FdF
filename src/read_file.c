/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_file.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dtran <dtran@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/22 16:55:36 by dtran         #+#    #+#                 */
/*   Updated: 2022/09/01 15:43:22 by dtran         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_height(char *file_name)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		ft_error_exit("open failed", 1);
	height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		height++;
	}
	close (fd);
	return (height);
}

static int	get_width(char *file_name)
{
	int		fd;
	char	**map;
	char	*line;
	int		width;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		ft_error_exit("open failed", 1);
	line = get_next_line(fd);
	if (!line)
		ft_error_exit("GNL failed", 1);
	map = ft_split(line, ' ');
	if (!map)
		ft_error_exit("no map available", 1);
	width = 0;
	while (map[width])
		width++;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	free_map_char(map);
	close(fd);
	return (width);
}

static void	parse_width(t_data *data, int height, char **parsed_map)
{
	int	width;

	width = 0;
	while (width < data->width)
	{
		data->map[height][width] = ft_atoi(parsed_map[width]);
		free(parsed_map[width]);
		parsed_map[width] = NULL;
		width++;
	}
}

static void	fill_map(t_data *data, int fd)
{
	char	**parsed_map;
	char	*line;
	int		height;

	height = 0;
	while (height < data->height)
	{
		line = get_next_line(fd);
		if (!line)
			free_exit(data, "GNL failed");
		data->map[height] = (int *)ft_calloc(sizeof(int), data->width);
		if (!data->map[height])
			free_exit(data, "calloc failed");
		parsed_map = ft_split(line, ' ');
		free(line);
		if (!parsed_map)
			free_exit(data, "split failed");
		parse_width(data, height, parsed_map);
		free_map_char(parsed_map);
		height++;
	}
}

void	read_file(char *file_name, t_data *data)
{
	int		fd;

	data->height = get_height(file_name);
	data->width = get_width(file_name);
	data->map = (int **)ft_calloc(sizeof(int *), data->height);
	if (!data->map)
		free_exit(data, "calloc failed");
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		ft_error_exit("open failed", 1);
	fill_map(data, fd);
	close(fd);
}
