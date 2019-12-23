/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 16:21:49 by macrespo          #+#    #+#             */
/*   Updated: 2019/12/23 11:46:28 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	vertical_move(int event, t_cam *cam)
{
	if (event == W)
	{
		cam->x += cam->d_x;
		cam->y += cam->d_y;
	}
	else if (event == S)
	{
		cam->x -= cam->d_x;
		cam->y -= cam->d_y;
	}
	draw(cam);
}
