/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:14:55 by macrespo          #+#    #+#             */
/*   Updated: 2019/12/26 16:32:21 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate(int event, t_draw *dir)
{
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
	draw(dir);
}
