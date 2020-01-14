/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 17:01:32 by macrespo          #+#    #+#             */
/*   Updated: 2020/01/14 13:34:23 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray(t_draw *d)
{
	double	camera_x;

	camera_x = (2.00 * (double)d->ray.i / (double)g_data.x) - 1.00;
	d->ray.x = d->cam.x;
	d->ray.y = d->cam.y;
	d->ray.d_x = d->cam.d_x + d->cam.p_x * camera_x;
	d->ray.d_y = d->cam.d_y + d->cam.p_y * camera_x;
}
