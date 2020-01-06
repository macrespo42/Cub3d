/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall_dist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 15:13:08 by macrespo          #+#    #+#             */
/*   Updated: 2020/01/06 19:51:27 by macrespo         ###   ########.fr       */
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

static t_hit		get_wall_dist_se(t_draw d)
{
	t_hit	v;
	t_hit	h;
	double	h_hit;

	v.x = d.cam.x + (d.cam.y - ceil(d.cam.y)) * (d.ray.x / d.ray.y);
	v.y = ceil(d.cam.y);
	while (wall_hit_v(v) == 1)
	{
		v.y += 1;
		v.x += d.ray.x / d.ray.y;
	}
	h.y = d.cam.y + (d.cam.x - ceil(d.cam.x)) * (d.ray.y / d.ray.x);
	h.x = ceil(d.cam.x);
	while (wall_hit_h(h) == 1)
	{
		h.x += 1;
		h.y += d.ray.y / d.ray.x;
	}
	h_hit = hypot(d.cam.x - h.x, d.cam.y - h.y);
	if (h_hit < hypot(d.cam.x - v.x, d.cam.y - v.y))
		return (h);
	return (v);
}

static t_hit		get_wall_dist_ne(t_draw d)
{
	t_hit	v;
	t_hit	h;
	double	h_hit;

	v.x = d.cam.x + (d.cam.y - floor(d.cam.y)) * (d.ray.x / d.ray.y);
	v.y = floor(d.cam.y);
	while (wall_hit_v(v) == 1)
	{
		v.y -= 1;
		v.x -= d.ray.x / d.ray.y;
	}
	h.y = d.cam.y + (d.cam.x - ceil(d.cam.x)) * (d.ray.y / d.ray.x);
	h.x = ceil(d.cam.x);
	while (wall_hit_h(h) == 1)
	{
		h.x += 1;
		h.y += d.ray.y / d.ray.x;
	}
	h_hit = hypot(d.cam.x - h.x, d.cam.y - h.y);
	if (h_hit < hypot(d.cam.x - v.x, d.cam.y - v.y))
		return (h);
	return (v);
}

static t_hit		get_wall_dist_so(t_draw d)
{
	t_hit	v;
	t_hit	h;
	double	h_hit;

	v.x = d.cam.x + (d.cam.y - ceil(d.cam.y)) * (d.ray.x / d.ray.y);
	v.y = ceil(d.cam.y);
	while (wall_hit_v(v) == 1)
	{
		v.y += 1;
		v.x += d.ray.x / d.ray.y;
	}
	h.y = d.cam.y + (d.cam.x - floor(d.cam.x)) * (d.ray.y / d.ray.x);
	h.x = floor(d.cam.x);
	while (wall_hit_h(h) == 1)
	{
		h.x -= 1;
		h.y -= d.ray.y / d.ray.x;
	}
	h_hit = hypot(d.cam.x - h.x, d.cam.y - h.y);
	if (h_hit < hypot(d.cam.x - v.x, d.cam.y - v.y))
		return (h);
	return (v);
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
