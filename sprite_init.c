/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 11:57:02 by macrespo          #+#    #+#             */
/*   Updated: 2020/01/27 15:50:26 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		sprite_pos(t_draw *d)
{
	int		x;
	int		y;
	int		s_i;

	s_i = 0;
	y = 0;
	while (g_data.map[y])
	{
		x = 0;
		while (g_data.map[y][x])
		{
			if (g_data.map[y][x] == '2')
			{
				d->spos[s_i].x = (double)x + 0.5;
				d->spos[s_i].y = (double)y + 0.5;
				s_i++;
			}
			x++;
		}
		y++;
	}
}

int				sprite_init(t_draw *d)
{
	if (!(d->sprite.zbuff = malloc(sizeof(double) * g_data.x)))
		return (0);
	if (!(d->sprite.order = malloc(sizeof(double) * d->cam.s_nb)))
		return (0);
	if (!(d->sprite.dist = malloc(sizeof(double) * d->cam.s_nb)))
		return (0);
	if (!(d->spos = malloc(sizeof(t_sp) * d->cam.s_nb)))
		return (0);
	sprite_pos(d);
	return (1);
}
