/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall_dist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 15:13:08 by macrespo          #+#    #+#             */
/*   Updated: 2020/01/07 17:47:26 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_hit		get_wall_dist_se(t_draw d)
{
	t_hit	v;
	t_hit	h;
	double	h_hit;

	v.x = d.cam.x + (d.cam.y - ceil(d.cam.y)) * (d.ray.x / d.ray.y);
	v.y = ceil(d.cam.y);
	while (wall_hit(v) == 1)
	{
		v.y += 1;
		v.x += d.ray.x / d.ray.y;
		printf("V LOOPHIT : [x:%f] - [y:%f]\n", v.x, v.y);
	}
	h.y = d.cam.y + (d.cam.x - ceil(d.cam.x)) * (d.ray.y / d.ray.x);
	h.x = ceil(d.cam.x);
	while (wall_hit(h) == 1)
	{
		h.x += 1;
		h.y += d.ray.y / d.ray.x;
		printf("H LOOPHIT : [x:%f] - [y:%f]\n", v.x, v.y);
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
	printf("VERTICAL [X:%f] -- [Y:%f]\n", v.x, v.y);
	while (wall_hit(v) == 1)
	{
		v.y += 1;
		v.x += d.ray.x / d.ray.y;
	}
	h.y = d.cam.y + (d.cam.x - floor(d.cam.x)) * (d.ray.y / d.ray.x);
	h.x = floor(d.cam.x);
	printf("HORIZONTAL [X:%f] -- [Y:%f]\n", h.x, h.y);
	while (wall_hit(h) == 1)
	{
		h.x -= 1;
		h.y -= d.ray.y / d.ray.x;
	}
	h_hit = hypot(d.cam.x - h.x, d.cam.y - h.y);
	printf("DIST SO OK\n");
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
	while (wall_hit(v) == 1)
	{
		v.y -= 1;
		v.x -= d.ray.x / d.ray.y;
	}
	h.y = d.cam.y + (d.cam.x - ceil(d.cam.x)) * (d.ray.y / d.ray.x);
	h.x = ceil(d.cam.x);
	while (wall_hit(h) == 1)
	{
		h.x += 1;
		h.y += d.ray.y / d.ray.x;
	}
	h_hit = hypot(d.cam.x - h.x, d.cam.y - h.y);
	if (h_hit < hypot(d.cam.x - v.x, d.cam.y - v.y))
		return (h);
	return (v);
}

static t_hit		get_wall_dist_no(t_draw d)
{
	t_hit	v;
	t_hit	h;
	double	h_hit;

	v.x = d.cam.x + (d.cam.y - floor(d.cam.y)) * (d.ray.x / d.ray.y);
	v.y = floor(d.cam.y);
	while (wall_hit(v) == 1)
	{
		v.y -= 1;
		v.x -= d.ray.x / d.ray.y;
	}
	h.y = d.cam.y + (d.cam.x - floor(d.cam.x)) * (d.ray.y / d.ray.x);
	h.x = floor(d.cam.x);
	while (wall_hit(h) == 1)
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

	if (draw.ray.x > 0 && draw.ray.y > 0)
	{
		hit = get_wall_dist_se(draw);
		printf("HIT : [x:%f] -- [y:%f]\n", hit.x, hit.y);
	}
	if (draw.ray.x < 0 && draw.ray.y > 0)
		hit = get_wall_dist_so(draw);
	if (draw.ray.x > 0 && draw.ray.y < 0)
		hit = get_wall_dist_ne(draw);
	if (draw.ray.x < 0 && draw.ray.y < 0)
		hit = get_wall_dist_no(draw);
	return (hit);
}
