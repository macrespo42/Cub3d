/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_range.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 11:23:39 by macrespo          #+#    #+#             */
/*   Updated: 2020/01/06 18:37:01 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int					wall_hit_v(t_hit hit)
{
	if (g_data.map[(int)floor(hit.y)][(int)floor(hit.x)] != '1')
	{
		if (g_data.map[(int)floor(hit.y)])
			return (1);
	}
	return (0);
}

int					wall_hit_h(t_hit hit)
{
	if (g_data.map[(int)floor(hit.y)][(int)floor(hit.x)] != '1')
	{
		if (g_data.map[(int)floor(hit.y)][(int)floor(hit.x)])
			return (1);
	}
	return (0);
}

double				get_range(t_draw draw)
{
	t_hit	hit;

	hit = get_wall_dist(draw);
	return (hypot(draw.cam.x - hit.x, draw.cam.y - hit.y));
}
