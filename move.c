/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 16:21:49 by macrespo          #+#    #+#             */
/*   Updated: 2019/12/26 13:51:49 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	vertical_move(int event, t_draw *infos)
{
	if (event == W)
	{
		infos->cam.x += infos->cam.d_x;
		infos->cam.y += infos->cam.d_y;
	}
	else if (event == S)
	{
		infos->cam.x -= infos->cam.d_x;
		infos->cam.y -= infos->cam.d_y;
	}
	if (g_data.map[(int)floor(infos->cam.y)][(int)floor(infos->cam.x)] == '1')
	{
		if (event == W)
		{
			infos->cam.x -= infos->cam.d_x;
			infos->cam.y -= infos->cam.d_y;
		}
		else
		{
			infos->cam.x += infos->cam.d_x;
			infos->cam.y += infos->cam.d_y;
		}
	}
	draw(infos);
}

void	horizontal_move(int event, t_draw *infos)
{
	if (event == D)
	{
		infos->cam.x -= infos->cam.d_y;
		infos->cam.y += infos->cam.d_x;
	}
	else if (event == A)
	{
		infos->cam.x += infos->cam.d_y;
		infos->cam.y -= infos->cam.d_x;
	}
	if (g_data.map[(int)floor(infos->cam.y)][(int)floor(infos->cam.x)] == '1')
	{
		if (event == D)
		{
			infos->cam.x += infos->cam.d_y;
			infos->cam.y -= infos->cam.d_x;
		}
		else if (event == A)
		{
			infos->cam.x -= infos->cam.d_y;
			infos->cam.y += infos->cam.d_x;
		}
	}
	draw(infos);
}
