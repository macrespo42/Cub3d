/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall_dist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 15:13:08 by macrespo          #+#    #+#             */
/*   Updated: 2019/12/26 18:08:07 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_hit		get_wall_dist_north(t_cam cam)
{
	t_hit	hit;

	hit.x = cam.x + (cam.y - cam.y - 1) * (cam.d_x / cam.d_y);
	hit.y = cam.y - 1;
	while (g_data.map[(int)floor(hit.y)][(int)floor(hit.x)] != '1')
	{
		hit.y += -1;
		hit.x += cam.d_x / cam.d_y;
	}
	return (hit);
}

static t_hit		get_wall_dist_south(t_cam cam)
{
	t_hit	hit;

	hit.x = cam.x + (cam.y - ceil(cam.y)) * (cam.d_x / cam.d_y);
	hit.y = ceil(cam.y);
	while (g_data.map[(int)floor(hit.y)][(int)floor(hit.x)] != '1')
	{
		hit.y += 1;
		hit.x += cam.d_x / cam.d_y;
	}
	return (hit);
}

static t_hit		get_wall_dist_east(t_cam cam)
{
	t_hit	hit;

	hit.y = cam.y + (cam.x - floor(cam.x)) * (cam.d_y / cam.d_x);
	hit.x = floor(cam.x);
	while (g_data.map[(int)floor(hit.y)][(int)floor(hit.x)] != '1')
	{
		hit.x += 1;
		hit.y += cam.d_y / cam.d_x;
	}
	return (hit);
}

static t_hit		get_wall_dist_west(t_cam cam)
{
	t_hit	hit;

	hit.y = cam.y + (cam.x - cam.x - 1) * (cam.d_y / cam.d_x);
	hit.x = cam.x - 1;
	while (g_data.map[(int)floor(hit.y)][(int)floor(hit.x)] != '1')
	{
		hit.x -= 1;
		hit.y += cam.d_y / cam.d_x;
	}
	return (hit);
}

t_hit				get_wall_dist(t_cam cam)
{
	t_hit	hit;

	if (cam.d_y < 0 && cam.d_x < cos(-M_PI/4) && cam.d_x > cos(M_PI/4))
		hit = get_wall_dist_north(cam);
	if (cam.d_y > 0 && cam.d_x < cos(-M_PI/4) && cam.d_x > cos(M_PI/4))
		hit = get_wall_dist_south(cam);
	if (cam.d_x > 0 && cam.d_y < cos(-M_PI/4) && cam.d_x > cos(M_PI/4))
		hit = get_wall_dist_east(cam);
	if (cam.d_x < 0 && cam.d_y < cos(-M_PI/4) && cam.d_x > cos(M_PI/4))
		hit = get_wall_dist_west(cam);
	// if (cam.d_y < 0 && (cam.d_x < cos(-M_PI/4) && cam.d_x > cos(M_PI/4)))
	// 	hit = get_wall_dist_north(cam);
	// if (cam.d_y > 0 && (cam.d_x < cos(-M_PI/4) && cam.d_x > cos(M_PI/4)))
	// 	hit = get_wall_dist_south(cam);
	// if (cam.d_x > 0 && (cam.d_y < cos(-M_PI/4) && cam.d_x > cos(M_PI/4)))
	// 	hit = get_wall_dist_east(cam);
	// if (cam.d_x < 0 && (cam.d_y < cos(-M_PI/4) && cam.d_x > cos(M_PI/4)))
	// 	hit = get_wall_dist_west(cam);
	return (hit);
}
