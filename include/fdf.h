/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dtran <dtran@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/14 16:43:48 by dtran         #+#    #+#                 */
/*   Updated: 2022/07/14 17:06:53 by dtran         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 1920
# define HEIGHT 1080

#include <stdbool.h>
#include <errno.h>
#include <math.h>
#include <libft.h>
#include <get_next_line.h>
#include "../include/MLX42/include/MLX42/MLX42.h"
typedef struct s_init
{
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_init;

#endif