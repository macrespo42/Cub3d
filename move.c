/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:05:12 by macrespo          #+#    #+#             */
/*   Updated: 2020/02/06 16:03:44 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	vertical_move(int event, t_draw *infos)
{
	double	speed;

	speed = 0;
	if (event == W)
		speed = 0.15;
	else if (event == S)
		speed = -0.15;
	infos->cam.x += infos->cam.d_x * speed;
	if (g_data.map[(int)floor(infos->cam.y)][(int)floor(infos->cam.x)] == '1')
		infos->cam.x -= infos->cam.d_x * speed;
	infos->cam.y += infos->cam.d_y * speed;
	if (g_data.map[(int)floor(infos->cam.y)][(int)floor(infos->cam.x)] == '1')
		infos->cam.y -= infos->cam.d_y * speed;
	draw(infos, 0);
}

void	horizontal_move(int event, t_draw *infos)
{
	double	speed;

	speed = 0;
	if (event == D)
		speed = 0.15;
	else if (event == A)
		speed = -0.15;
	infos->cam.x -= infos->cam.d_y * speed;
	if (g_data.map[(int)floor(infos->cam.y)][(int)floor(infos->cam.x)] == '1')
		infos->cam.x += infos->cam.d_y * speed;
	infos->cam.y += infos->cam.d_x * speed;
	if (g_data.map[(int)floor(infos->cam.y)][(int)floor(infos->cam.x)] == '1')
		infos->cam.y -= infos->cam.d_x * speed;
	draw(infos, 0);
}

void	rotate(int event, t_draw *d)
{
	double	old_dx;
	double	old_px;
	double	speed;

	speed = 0.0;
	if (event == RIGHT)
		speed = TURN;
	else if (event == LEFT)
		speed = -TURN;
	old_dx = d->cam.d_x;
	old_px = d->cam.p_x;
	d->cam.d_x = d->cam.d_x * cos(speed) - d->cam.d_y * sin(speed);
	d->cam.d_y = old_dx * sin(speed) + d->cam.d_y * cos(speed);
	d->cam.p_x = d->cam.p_x * cos(speed) - d->cam.p_y * sin(speed);
	d->cam.p_y = old_px * sin(speed) + d->cam.p_y * cos(speed);
	draw(d, 0);
}
