/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 11:57:02 by macrespo          #+#    #+#             */
/*   Updated: 2020/01/27 12:38:28 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		sprite_init(t_draw *d)
{
	d->sprite.zbuff = 0;
	d->sprite.order = 0;
	d->sprite.dist = 0;
	if (!(d->sprite.zbuff = malloc(sizeof(double) * g_data.x)))
		return (0);
	if (!(d->sprite.order = malloc(sizeof(double) * d->cam.s_nb)))
		return (0);
	if (!(d->sprite.dist = malloc(sizeof(double) * d->cam.s_nb)))
		return (0);
	return (1);
}
