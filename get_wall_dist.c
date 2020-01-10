/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall_dist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 15:13:08 by macrespo          #+#    #+#             */
/*   Updated: 2020/01/10 17:01:20 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_hit				hit_init(t_draw draw, int map_x, int map_y)
{
	t_hit	hit;

	hit.delta_dx = ft_abs(1 / draw.ray.x);
	hit.delta_dy = ft_abs(1 / draw.ray.y);
	if (draw.ray.x < 0)
	{
		hit.step_x = -1;
		hit.side_dx = (draw.cam.x - map_x) * hit.delta_dx;
	}
	else
	{
		hit.step_x = 1;
		hit.side_dx = (map_x + 1.0 - draw.cam.x) * hit.delta_dx;
	}
	if (draw.ray.y < 0)
	{
		hit.step_y = -1;
		hit.side_dy = (draw.cam.y - map_y) * hit.delta_dy;
	}
	else
	{
		hit.step_y = -1;
		hit.side_dy = (draw.cam.y - map_y) * hit.delta_dy;
	}
	return (hit);
}

int							get_wall_dist(t_draw *draw, int map_x, int map_y)
{
	draw->hit = hit_init(*draw, map_x, map_y);
	draw->hit.wall = 0;
	while (draw->hit.wall == 0)
	{
		if (draw->hit.side_dx < draw->hit.side_dy)
		{
			draw->hit.side_dx += draw->hit.delta_dx;
			map_x += draw->hit.step_x;
			draw->hit.side = 0;
		}
		else
		{
			draw->hit.side_dy += draw->hit.delta_dy;
			map_y += draw->hit.step_y;
			draw->hit.side = 1;
		}
		if (g_data.map[map_x][map_y] > 0)
			draw->hit.wall = 1;
	}
	return (draw->hit.side);
}
