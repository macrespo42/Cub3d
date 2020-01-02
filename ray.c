/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 16:08:56 by macrespo          #+#    #+#             */
/*   Updated: 2020/01/02 12:33:16 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray(t_draw *draw)
{
	double	range;
	double	move;

	range = g_data.x / 2;
	move = (draw->ray.i - range) / range * FOV * (M_PI / 180);
	draw->ray.x = draw->cam.d_x * cos(move) - draw->cam.d_y * sin(move);
	draw->ray.y = draw->cam.d_x * sin(move) + draw->cam.d_y * cos(move);
}
