/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:05:12 by macrespo          #+#    #+#             */
/*   Updated: 2020/01/15 17:14:17 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate(int event, t_draw *d)
{
	double	old_dx;
	double	old_px;
	double	t;

	t = 0.0;
	if (event == RIGHT)
		t = TURN;
	else if (event == LEFT)
		t = -TURN;
	old_dx = d->cam.d_x;
	old_px = d->cam.p_x;
	d->cam.d_x = d->cam.d_x * cos(t) - d->cam.d_y * sin(t);
	d->cam.d_y = old_dx * sin(t) + d->cam.d_y * cos(t);
	d->cam.p_x = d->cam.p_x * cos(t) - d->cam.p_y * sin(t);
	d->cam.p_y = old_px * sin(t) + d->cam.p_y * cos(t);
	draw(d);
}
