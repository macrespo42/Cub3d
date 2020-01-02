/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_range.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 11:23:39 by macrespo          #+#    #+#             */
/*   Updated: 2020/01/02 12:35:07 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double				get_range(t_draw draw)
{
	t_hit	hit;

	hit = get_wall_dist(draw);
	return (hypot(draw.cam.x - hit.x, draw.cam.y - hit.y));
}
