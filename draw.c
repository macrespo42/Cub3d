/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 12:29:00 by macrespo          #+#    #+#             */
/*   Updated: 2020/01/08 14:16:58 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int					wall_hit(t_hit hit)
{
	int		ret;
	char	*err;
	static int fx = 0;

	if ((int)floor(hit.y) >= g_data.y_len && (int)floor(hit.x) >= g_data.x_len)
	{
		// printf("OUT OF MAP [x:%f] - [y:%f]\n", hit.x, hit.y);
		err = "OUT OF MAP\n";
		ret  = 0;
	}
	else if ((int)floor(hit.y) < 0 && (int)floor(hit.x) < 0)
	{
		// printf("NEG OUT OF MAP [x:%f] - [y:%f]\n", hit.x, hit.y);
		err = "NEG OUT OF MAP\n";
		ret = 0;
	}
	else if (g_data.map[(int)floor(hit.y)][(int)floor(hit.x)] == '1')
	{
		// printf("WALL HIT [x:%f] - [y:%f]\n", hit.x, hit.y);
		err = "WALL HIT\n";
		ret = 0;
	}
	else
	{
		err = "WALL NOT FOUND\n";
		ret = 1;
	}
	fx++;
	printf("CALL NB : %d, result : %s", fx, err);
	printf("WALL HIT : [x:%f] - [y:%f]\n", hit.x, hit.y);
	printf("MAP HIT : [x:%d] - [y:%d]\n", (int)floor(hit.x), (int)floor(hit.y));
	return (ret);
}

double				get_range(t_draw draw)
{
	t_hit	hit;

	hit = get_wall_dist(draw);
	return (hypot(draw.cam.x - hit.x, draw.cam.y - hit.y));
}

int		get_column(t_img *img, int column, int size_wall)
{
	int		px;

	px = 0;
	if (size_wall % 2 != 0)
		size_wall += 1;
	while (column < g_data.x * (g_data.y - size_wall) / 2)
	{
		img->grid[column] = mlx_get_color_value(g_mlx.ptr, g_data.f);
		column += g_data.x;
	}
	while (px < size_wall && column < (g_data.x * g_data.y))
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
		range = g_data.y / get_range(*d_infos);
		d_infos->ray.i = get_column(&d_infos->img, d_infos->ray.i, range);
		d_infos->ray.i = (d_infos->ray.i - (g_data.x * g_data.y)) + 1;
	}
	mlx_put_image_to_window(g_mlx.ptr, g_mlx.win, d_infos->img.ptr, 0, 0);
}
