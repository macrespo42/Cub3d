/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 11:57:02 by macrespo          #+#    #+#             */
/*   Updated: 2020/01/29 19:48:51 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		spr_pos(t_draw *d)
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
				d->spr[s_i].x = (double)x + 0.5;
				d->spr[s_i].y = (double)y + 0.5;
				s_i++;
			}
			x++;
		}
		y++;
	}
}

int				sprite_init(t_draw *d)
{

	if (!(d->spr = malloc(sizeof(t_spr) * d->cam.s_nb)))
		return (0);
	spr_pos(d);
	return (1);
}

static void		bubble_sort(t_draw *d, int length)
{
	int		i;
	int		sorted;
	t_spr	tmp;

	i = 0;
	sorted = 0;
	while (sorted == 0)
	{
		sorted = 1;
		while (i < length - 1)
		{
			if (d->spr[i].d < d->spr[i + 1].d)
			{
				tmp = d->spr[i];
				d->spr[i] = d->spr[i + 1];
				d->spr[i + 1] = tmp;
				sorted = 0;
			}
			i++;
		}
		length--;
	}
}

int				sprite_position(t_draw *d, double dx, double dy, double ds)
{
	double	angle;

	dx = (dx - d->cam.x) / ds;
	dy = (dy - d->cam.y) / ds;
	if (dy <= 0)
		angle = acos(dx) * 180 / M_PI;
	else
		angle = 360 - acos(dx) * 180 / M_PI;
	angle = d->cam.a - angle + 33;
	if (angle >= 180)
		angle -= 360;
	else if (angle <= -180)
		angle += 360;
	return (angle * g_data.x / 66);
}

void			sort_sprites(t_draw *d)
{
	int		i;
	double	dist;
	int		pos;

	dist = hypot(d->cam.d_x, d->cam.d_y);
	if (d->cam.d_y <= 0)
		d->cam.a = acos(d->cam.d_x / dist) * 180 / M_PI;
	else
		d->cam.a = 360 - acos(d->cam.d_x) * 180 / M_PI;
	i = 0;
	while (i < d->cam.s_nb)
	{
		d->spr[i].d = hypot(d->spr[i].x - d->cam.x, d->spr[i].y - d->cam.y);
		i++;
	}
	bubble_sort(d, d->cam.s_nb);
	i = 0;
	while (i < d->cam.s_nb)
	{
		pos = sprite_position(d, d->spr[i].x, d->spr[i].y, d->spr[i].d);
		//sprite_draw(d, pos, dist);
		i++;
	}
}
