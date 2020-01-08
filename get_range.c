/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_range.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 11:23:39 by macrespo          #+#    #+#             */
/*   Updated: 2020/01/07 17:45:49 by macrespo         ###   ########.fr       */
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
