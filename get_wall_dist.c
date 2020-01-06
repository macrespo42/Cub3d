/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall_dist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 15:13:08 by macrespo          #+#    #+#             */
/*   Updated: 2020/01/06 17:13:59 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_hit		get_wall_dist_north(t_draw draw)
{
	t_hit	hit;

	hit.x = draw.cam.x + (draw.cam.y - draw.cam.y - 1) * (draw.ray.x / draw.ray.y);
	hit.y = draw.cam.y - 1;
	while (g_data.map[(int)floor(hit.y)][(int)floor(hit.x)] != '1')
	{
		hit.y += -1;
		hit.x += draw.ray.x / draw.ray.y;
	}
	return (hit);
}

static t_hit		get_wall_dist_south(t_draw draw)
{
	t_hit	v;
	t_hit	h;

	v.x = draw.cam.x + (draw.cam.y - ceil(draw.cam.y)) * (draw.ray.x / draw.ray.y);
	v.y = ceil(draw.cam.y);
	while (g_data.map[(int)floor(v.y)][(int)floor(v.x)] != '1')
	{
		v.y += 1;
		v.x += draw.ray.x / draw.ray.y;
	}
	h.y = draw.cam.y + (draw.cam.x - ceil(draw.cam.x)) * (draw.ray.y / draw.ray.x);
	h.x = ceil(draw.cam.x);
	while (g_data.map[(int)floor(h.y)][(int)floor(h.x)] != '1')
	{
		h.x += 1;
		h.y += draw.ray.y / draw.ray.x;
	}
	if (hypot(draw.cam.x - h.x, draw.cam.y - h.y) < hypot(draw.cam.x - v.x, draw.cam.y - v.y))
		return (h);
	else
		return (v);
}

static t_hit		get_wall_dist_east(t_draw draw)
{
	t_hit	hit;

	hit.y = draw.cam.y + (draw.cam.x - floor(draw.cam.x)) * (draw.ray.y / draw.ray.x);
	hit.x = floor(draw.cam.x);
	while (g_data.map[(int)floor(hit.y)][(int)floor(hit.x)] != '1')
	{
		hit.x += 1;
		hit.y += draw.ray.y / draw.ray.x;
	}
	return (hit);
}

static t_hit		get_wall_dist_west(t_draw draw)
{
	t_hit	hit;

	hit.y = draw.cam.y + (draw.cam.x - draw.cam.x - 1) * (draw.ray.y / draw.ray.x);
	hit.x = draw.cam.x - 1;
	while (g_data.map[(int)floor(hit.y)][(int)floor(hit.x)] != '1')
	{
		hit.x -= 1;
		hit.y += draw.ray.y / draw.ray.x;
	}
	return (hit);
}

t_hit				get_wall_dist(t_draw draw)
{
	t_hit	hit;

	if (draw.ray.y < 0 && draw.ray.x < cos(-M_PI/4) && draw.ray.x > cos(M_PI / 4))
		hit = get_wall_dist_north(draw);
	if (draw.ray.y > 0 && draw.ray.x < cos(-M_PI/4) && draw.ray.x > cos(M_PI / 4))
		hit = get_wall_dist_south(draw);
	if (draw.ray.x > 0 && draw.ray.y < cos(-M_PI/4) && draw.ray.x > cos(M_PI / 4))
		hit = get_wall_dist_east(draw);
	if (draw.ray.x < 0 && draw.ray.y < cos(-M_PI/4) && draw.ray.x > cos(M_PI / 4))
		hit = get_wall_dist_west(draw);
	return (hit);
}
