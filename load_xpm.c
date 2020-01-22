/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:54:20 by macrespo          #+#    #+#             */
/*   Updated: 2020/01/21 18:09:24 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	*load_xpm(char *path)
{
	t_img			img;

	img.ptr = mlx_xpm_file_to_image(g_mlx.ptr, path, &img.w, &img.h);
	img.grid =
	(unsigned int*)mlx_get_data_addr(img.ptr, &img.bpp, &img.sl, &img.ed);
	free(img.ptr);
	return (img.grid);
}
