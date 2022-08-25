/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_file.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dtran <dtran@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/22 16:55:36 by dtran         #+#    #+#                 */
/*   Updated: 2022/08/25 17:32:57 by dtran         ########   odam.nl         */
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
		width++;
	}
}

static void	fill_map(char *line, t_data *data, int fd)
{
	char	**parsed_map;
	int		height;

	height = 0;
	while (height < data->height)
	{
		data->map[height] = (int *)malloc(sizeof(int) * data->width);
		if (!data->map[height])
			ft_error_exit("malloc failed", 1);
		parsed_map = ft_split(line, ' ');
		if (!parsed_map)
			ft_error_exit("split failed", 1);
		parse_width(data, height, parsed_map);
		free(line);
		free(parsed_map);
		line = get_next_line(fd);
		height++;
	}
}

void	read_file(char *file_name, t_data *data)
{
	char	*line;
	int		fd;

	data->height = get_height(file_name);
	data->width = get_width(file_name);
	data->map = (int **)malloc(sizeof(int *) * data->height);
	if (!data->map)
		ft_error_exit("malloc failed", 1);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		ft_error_exit("open failed", 1);
	line = get_next_line(fd);
	if (!line)
		ft_error_exit("no new line", 1);
	fill_map(line, data, fd);
	close(fd);
}
