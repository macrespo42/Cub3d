/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:14:55 by macrespo          #+#    #+#             */
/*   Updated: 2019/12/30 15:30:50 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate(int event, t_draw *dir)
{
	double	dist;

	if (event == RIGHT)
	{
		dir->cam.d_x = dir->cam.d_x * cos(TURN) - dir->cam.d_y * sin(TURN);
		dir->cam.d_y = dir->cam.d_x * sin(TURN) + dir->cam.d_y * cos(TURN);
	}
	if (event == LEFT)
	{
		dir->cam.d_x = dir->cam.d_x * cos(-TURN) - dir->cam.d_y * sin(-TURN);
		dir->cam.d_y = dir->cam.d_x * sin(-TURN) + dir->cam.d_y * cos(-TURN);
	}
	dist = hypot(dir->cam.d_x, dir->cam.d_y);
	printf("dist : %f\n", hypot(dir->cam.d_x, dir->cam.d_y));
	dir->cam.d_x /= dist;
	dir->cam.d_y /= dist;
	printf("dist : %f\n", hypot(dir->cam.d_x, dir->cam.d_y));
	draw(dir);
}
