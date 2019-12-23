/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 16:21:49 by macrespo          #+#    #+#             */
/*   Updated: 2019/12/23 15:10:44 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	vertical_move(int event, t_draw *d_infos)
{
	if (event == W)
	{
		d_infos->cam.x += d_infos->cam.d_x;
		d_infos->cam.y += d_infos->cam.d_y;
	}
	else if (event == S)
	{
		d_infos->cam.x -= d_infos->cam.d_x;
		d_infos->cam.y -= d_infos->cam.d_y;
	}
	if (g_data.map[(int)floor(d_infos->cam.y)][(int)floor(d_infos->cam.x)] == '1')
	{
		if (event == W)
		{
			d_infos->cam.x -= d_infos->cam.d_x;
			d_infos->cam.y -= d_infos->cam.d_y;
		}
		else
		{
			d_infos->cam.x += d_infos->cam.d_x;
			d_infos->cam.y += d_infos->cam.d_y;
		}
	}
	draw(d_infos);
}

void	horizontal_move(int event, t_draw *d_infos)
{
	if (event == D)
	{
		d_infos->cam.x -= d_infos->cam.d_y;
		d_infos->cam.y += d_infos->cam.d_x;
	}
	else if (event == A)
	{
		d_infos->cam.x += d_infos->cam.d_y;
		d_infos->cam.y -= d_infos->cam.d_x;
	}
	if (g_data.map[(int)floor(d_infos->cam.y)][(int)floor(d_infos->cam.x)] == '1')
	{
		if (event == D)
		{
			d_infos->cam.x += d_infos->cam.d_y;
			d_infos->cam.y -= d_infos->cam.d_x;
		}
		else if (event == A)
		{
			d_infos->cam.x -= d_infos->cam.d_y;
			d_infos->cam.y += d_infos->cam.d_x;
		}
	}
	draw(d_infos);
}
