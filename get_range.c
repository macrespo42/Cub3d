/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_range.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:53:06 by macrespo          #+#    #+#             */
/*   Updated: 2020/01/15 14:18:27 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	hit_init(t_draw *d)
{
	d->hit.map_x = (int)d->ray.x;
	d->hit.map_y = (int)d->ray.y;
	d->hit.delta_dx = sqrt(1 + (d->ray.d_y * d->ray.d_y) / (d->ray.d_x * d->ray.d_x));
	d->hit.delta_dy = sqrt(1 + (d->ray.d_x * d->ray.d_x) / (d->ray.d_y * d->ray.d_y));
	if (d->ray.d_x < 0)
	{
		d->hit.step_x = -1;
		d->hit.side_dx = (d->ray.x - d->hit.map_x) * d->hit.delta_dx;
	}
	else
	{
		d->hit.step_x = 1;
		d->hit.side_dx = (d->hit.map_x + 1.00 - d->ray.x) * d->hit.delta_dx;
	}
	if (d->ray.d_y < 0)
	{
		d->hit.step_y = -1;
		d->hit.side_dy = (d->ray.y - d->hit.map_y) * d->hit.delta_dy;
	}
	else
	{
		d->hit.step_y = 1;
		d->hit.side_dy = (d->hit.map_y + 1.00 - d->ray.y) * d->hit.delta_dy;
	}
}

static void	find_hit(t_draw *d)
{
	d->hit.wall = 0;
	while (d->hit.wall == 0)
	{
		if (d->hit.side_dx < d->hit.side_dy)
		{
			d->hit.side_dx += d->hit.delta_dx;
			d->hit.map_x += d->hit.step_x;
			d->hit.side = 0;
		}
		else
		{
			d->hit.side_dy += d->hit.delta_dy;
			d->hit.map_y += d->hit.step_y;
			d->hit.side = 1;
		}
		if (g_data.map[d->hit.map_y][d->hit.map_x] == '1')
			d->hit.wall = 1;
	}
	if (d->hit.side == 0)
		d->hit.wall_dist = ft_abs(
			(d->hit.map_x - d->ray.x + (1 - d->hit.step_x) / 2) / d->ray.d_x);
	else
		d->hit.wall_dist = ft_abs(
			(d->hit.map_y - d->ray.y + (1 - d->hit.step_y) / 2) / d->ray.d_y);
}

double		get_range(t_draw *d)
{
	int		line_height;
	hit_init(d);
	find_hit(d);
	line_height = ft_abs(g_data.y / d->hit.wall_dist);
	return (line_height);
}
