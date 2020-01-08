/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 11:23:44 by macrespo          #+#    #+#             */
/*   Updated: 2020/01/08 14:19:45 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

t_cam				cam_infos(void)
{
	int		i;
	int		j;
	t_cam	cam;

	cam.p_x = 0;
	cam.p_y = 0.66;
	i = 0;
	while (g_data.map[i])
	{
		j = 0;
		while (g_data.map[i][j])
		{
			if (is_pos(g_data.map[i][j], &cam))
			{
				cam.x = (double)j;
				cam.y = (double)i;
				cam.dir = g_data.map[i][j];
			}
			j++;
		}
		i++;
	}
	g_data.y_len = i - 1;
	g_data.x_len = j - 1;
	return (cam);
}
