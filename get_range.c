/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_range.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 11:23:39 by macrespo          #+#    #+#             */
/*   Updated: 2019/12/20 18:35:31 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

double				get_range(t_cam cam)
{
	t_hit	hit;

	hit = get_wall_dist(cam);
	return (hypot(cam.x - hit.x, cam.y - hit.y));
}
