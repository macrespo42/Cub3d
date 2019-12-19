/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_range.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 11:23:39 by macrespo          #+#    #+#             */
/*   Updated: 2019/12/19 12:53:27 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int			is_pos(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
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
			if (is_pos(g_data.map[i][j]))
			{
				cam.x = j;
				cam.y = i;
				cam.orientation = g_data.map[i][j];
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

	cam = cam_infos();
	printf("POS CAM : x : %d | y : %d\n", cam.x, cam.y);
	return (pow(cam.x - cam.y, 2) + pow(5 - 3, 2));
}
