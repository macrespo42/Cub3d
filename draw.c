/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 12:29:00 by macrespo          #+#    #+#             */
/*   Updated: 2019/12/26 16:41:45 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw(t_draw *d_infos)
{
	int		i;

	d_infos->img.ptr = mlx_new_image(g_mlx.ptr, g_data.x, g_data.y);
	d_infos->img.grid =
	(unsigned int*)mlx_get_data_addr
(d_infos->img.ptr, &d_infos->img.bpp, &d_infos->img.sl, &d_infos->img.ed);
	i = 0;
	while (i < g_data.x)
	{
		i = get_column(&d_infos->img, i, g_data.y / get_range(d_infos->cam));
		i = (i - (g_data.x * g_data.y)) + 1;
	}
	mlx_put_image_to_window(g_mlx.ptr, g_mlx.win, d_infos->img.ptr, 0, 0);
}
