/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 16:21:49 by macrespo          #+#    #+#             */
/*   Updated: 2019/12/20 16:29:30 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	vertical_move(int event, t_cam cam)
{
	if (event == W)
	{
		cam.x += cam.d_x;
		cam.y += cam.d_y;
	}
	else if (event == S)
	{
		cam.x -= cam.d_x;
		cam.y -= cam.d_y;
	}
}
