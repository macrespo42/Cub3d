/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:54:20 by macrespo          #+#    #+#             */
/*   Updated: 2020/02/05 18:57:09 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_img	file_to_array(char *path)
{
	t_img	img;

	img.ptr = mlx_xpm_file_to_image(g_mlx.ptr, path, &img.w, &img.h);
	if (img.ptr == NULL || img.w != 64 || img.h != 64)
		error_box("Bad xpm");
	img.grid =
	(unsigned int*)mlx_get_data_addr(img.ptr, &img.bpp, &img.sl, &img.ed);
	ft_memdel(img.ptr);
	return (img);
}

unsigned int	**load_xpm(char *path)
{
	t_img			img;
	int				y;
	int				x;
	int				i;
	unsigned int	**color;

	img = file_to_array(path);
	y = 0;
	if (!(color = malloc(sizeof(unsigned int*) * (img.h + 1))))
		return (NULL);
	i = 0;
	while (y < img.h)
	{
		if (!(color[y] = malloc(sizeof(unsigned int) * (img.w + 1))))
			return (NULL);
		x = 0;
		while (x < img.w)
		{
			color[y][x++] = img.grid[i++];
		}
		y++;
	}
	return (color);
}
