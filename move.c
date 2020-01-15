/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:05:12 by macrespo          #+#    #+#             */
/*   Updated: 2020/01/15 17:16:08 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	draw(d);
}
