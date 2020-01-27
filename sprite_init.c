/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 11:57:02 by macrespo          #+#    #+#             */
/*   Updated: 2020/01/27 18:12:05 by macrespo         ###   ########.fr       */
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

static void		swap_order(t_draw *d, int pos)
{
	int		tmp;

	tmp = d->sprite.order[pos];
	d->sprite.order[pos] = d->sprite.order[pos + 1];
	d->sprite.order[pos + 1] = tmp;
}

static void		bubble_sort(t_draw *d, int length)
{
	int		i;
	int		sorted;
	double	tmp;

	i = 0;
	sorted = 0;
	while (sorted == 0)
	{
		sorted = 1;
		while (i < length - 1)
		{
			if (d->sprite.dist[i] < d->sprite.dist[i - 1])
			{
				tmp = d->sprite.dist[i];
				d->sprite.dist[i] = d->sprite.dist[i + 1];
				d->sprite.dist[i + 1] = tmp;
				swap_order(d, i);
				sorted = 0;
			}
			i++;
		}
		length--;
	}
}

void			sort_sprites(t_draw *d)
{
	int		i;

	i = 0;
	while (i < d->cam.s_nb)
	{
		d->sprite.order[i] = i;
		d->sprite.dist[i] =
			hypot(d->cam.x - d->spos[i].x, d->cam.y - d->spos[i].y);
		i++;
	}
	bubble_sort(d, d->cam.s_nb);
}
