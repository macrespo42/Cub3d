/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 12:29:00 by macrespo          #+#    #+#             */
/*   Updated: 2020/01/28 19:58:26 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void			x_texture(t_draw *d, int wall_size)
{
	d->start = (int)(-wall_size / 2 + g_data.y / 2);
	d->end = (int)(wall_size / 2 + g_data.y / 2);
	if (d->start < 0)
		d->start = 0;
	if (d->end >= g_data.y)
		d->end = g_data.y - 1;
	if (d->hit.side == 1)
		d->wall_x = d->ray.x + ((d->hit.map_y - d->ray.y + (1 - d->hit.step_y)
		/ 2) / d->ray.d_y) * d->ray.d_x;
	else
		d->wall_x = d->ray.y + ((d->hit.map_x - d->ray.x + (1 - d->hit.step_x)
		/ 2) / d->ray.d_x) * d->ray.d_y;
	d->wall_x -= floor(d->wall_x);
	d->tex_x = (int)(d->wall_x * 64);
	if (d->hit.side == 0 && d->ray.d_x > 0)
		d->tex_x = 64 - d->tex_x - 1;
	if (d->hit.side == 1 && d->ray.d_y < 0)
		d->tex_x = 64 - d->tex_x - 1;
}

unsigned int		wall_orient(t_draw *d)
{
	unsigned int	color;

	if (d->hit.side == 0 && d->ray.d_x > 0)
		color = g_data.so[(int)d->tex_y][(int)d->tex_x];
	if (d->hit.side == 0 && d->ray.d_x < 0)
		color = g_data.no[(int)d->tex_y][(int)d->tex_x];
	if (d->hit.side == 1 && d->ray.d_y < 0)
		color = g_data.we[(int)d->tex_y][(int)d->tex_x];
	if (d->hit.side == 1 && d->ray.d_y > 0)
		color = g_data.ea[(int)d->tex_y][(int)d->tex_x];
	return (color);
}

int					get_column(t_draw *d, int column, int wall_size)
{
	int				px;
	unsigned int	color;

	x_texture(d, wall_size);
	px = d->start;
	while (column < g_data.x * (g_data.y - wall_size) / 2)
	{
		d->img.grid[column] = mlx_get_color_value(g_mlx.ptr, g_data.f);
		column += g_data.x;
	}
	while (px < d->end && column < (g_data.x * g_data.y))
	{
		d->tex_y = (px * 2 - g_data.y + wall_size) * (64 / 2) / wall_size;
		color = wall_orient(d);
		d->img.grid[column] = mlx_get_color_value(g_mlx.ptr, color);
		column += g_data.x;
		px++;
	}
	while (column < (g_data.x * g_data.y))
	{
		d->img.grid[column] = mlx_get_color_value(g_mlx.ptr, g_data.c);
		column += g_data.x;
	}
	return (column);
}

void				draw(t_draw *d_infos)
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
		sort_sprites(d_infos);
		d_infos->ray.i = get_column(d_infos, d_infos->ray.i, range);
		d_infos->ray.i = (d_infos->ray.i - (g_data.x * g_data.y)) + 1;
	}
	mlx_put_image_to_window(g_mlx.ptr, g_mlx.win, d_infos->img.ptr, 0, 0);
	ft_memdel(d_infos->img.ptr);
	ft_memdel(d_infos->img.grid);
}
