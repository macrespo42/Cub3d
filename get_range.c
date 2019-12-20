/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_range.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 11:23:39 by macrespo          #+#    #+#             */
/*   Updated: 2019/12/20 16:50:55 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int			is_pos(char c, t_cam *cam)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		if (c == 'N')
		{
			cam->d_x = 0;
			cam->d_y = -1;
		}
		else if (c == 'S')
		{
			cam->d_x = 0;
			cam->d_y = 1;
		}
		else if (c == 'W')
		{
			cam->d_x = -1;
			cam->d_y = 0;
		}
		else if (c == 'E')
		{
			cam->d_x = 1;
			cam->d_y = 0;
		}
		return (1);
	}
	return (0);
}

static t_cam		cam_infos()
{
	int		i;
	int		j;
	t_cam	cam;

	i = 0;
	while(g_data.map[i])
	{
		j = 0;
		while (g_data.map[i][j])
		{
			if (is_pos(g_data.map[i][j], &cam))
			{
				cam.x = (double)j + 0.5;
				cam.y = (double)i + 0.5;
				cam.dir = g_data.map[i][j];
				return (cam);
			}
			j++;
		}
		i++;
	}
	return (cam);
}

double				get_range()
{
	t_cam	cam;
	t_hit	hit;

	cam = cam_infos();
	hit = get_wall_dist(cam);
	return (hypot(cam.x - hit.x, cam.y - hit.y));
}
