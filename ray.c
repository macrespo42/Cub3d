/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 16:08:56 by macrespo          #+#    #+#             */
/*   Updated: 2020/01/08 15:29:09 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray(t_draw *draw)
{
	double	camera_x;

	cameraX = 2 * draw->ray.i / (double)g_data.x - 1;
	draw->ray.x = draw->cam.d_x + cam.p_x * camera_x;
	draw->ray.y = draw->cam.d_y + cam.p_y * camera_x;
}
