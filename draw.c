/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 12:29:00 by macrespo          #+#    #+#             */
/*   Updated: 2020/01/15 14:56:55 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_column(t_img *img, int column, int wall_size)
{
	int		px;

	px = 0;
	while (column < g_data.x * (g_data.y - wall_size) / 2)
	{
		img->grid[column] = mlx_get_color_value(g_mlx.ptr, g_data.f);
		column += g_data.x;
	}
	while (px < wall_size && column < (g_data.x * g_data.y))
	{
		img->grid[column] = mlx_get_color_value(g_mlx.ptr, WALL);
		column += g_data.x;
		px++;
	}
	while (column < (g_data.x * g_data.y))
	{
		img->grid[column] = mlx_get_color_value(g_mlx.ptr, g_data.c);
		column += g_data.x;
	}
	return (column);
}

void	draw(t_draw *d_infos)
{
	double	range;

	d_infos->img.ptr = mlx_new_image(g_mlx.ptr, g_data.x, g_data.y);
	d_infos->img.grid =
	(unsigned int*)mlx_get_data_addr
(d_infos->img.ptr, &d_infos->img.bpp, &d_infos->img.sl, &d_infos->img.ed);
	d_infos->ray.i = 0;
	while (d_infos->ray.i < g_data.x)
	{
		ray(d_infos);
		range = get_range(d_infos);
		d_infos->ray.i = get_column(&d_infos->img, d_infos->ray.i, range);
		d_infos->ray.i = (d_infos->ray.i - (g_data.x * g_data.y)) + 1;
	}
	mlx_put_image_to_window(g_mlx.ptr, g_mlx.win, d_infos->img.ptr, 0, 0);
}
