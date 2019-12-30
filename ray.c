/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 16:08:56 by macrespo          #+#    #+#             */
/*   Updated: 2019/12/30 17:13:52 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray(t_draw *draw)
{
	double	range;
	double	move;

	range = g_data.x / 2;
	move = (draw->ray.i - range) / range * FOV * (M_PI / 180);
	draw->ray.x = draw->ray.x * cos(move) - draw->ray.y * sin(move);
	draw->ray.y = draw->ray.x * sin(move) + draw->ray.y * cos(move);
}
