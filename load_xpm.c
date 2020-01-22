/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:54:20 by macrespo          #+#    #+#             */
/*   Updated: 2020/01/22 17:39:17 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	**load_xpm(char *path)
{
	t_img			img;
	int				y;
	int				x;
	int				i;
	unsigned int	**color;

	img.ptr = mlx_xpm_file_to_image(g_mlx.ptr, path, &img.w, &img.h);
	img.grid =
	(unsigned int*)mlx_get_data_addr(img.ptr, &img.bpp, &img.sl, &img.ed);
	free(img.ptr);
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
			color[y][x] = img.grid[i];
			i++;
			x++;
		}
		y++;
	}
	return (color);
}
