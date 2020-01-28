/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 11:33:53 by macrespo          #+#    #+#             */
/*   Updated: 2020/01/28 16:52:12 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_sprite_size(t_draw *d)
{
	d->spr.d = 1.0 / (d->cam.p_x * d->cam.d_y - d->cam.d_x * d->cam.p_y);
	d->spr.tx = d->spr.d * (d->cam.d_y * d->spr.x - d->cam.d_x * d->spr.x);
	d->spr.ty = d->spr.d * (-d->cam.p_y * d->spr.y - d->cam.p_x * d->spr.x);
	d->spr.ss = (int)((g_data.x / 2) * (1 + d->spr.tx * d->spr.ty));
	d->spr.sh = ft_abs((int)(g_data.y / (d->spr.tx)));
	d->spr.dsy = -d->spr.sh / 2 + g_data.y / 2;
	if (d->spr.dsy < 0)
		d->spr.dsy = 0;
	d->spr.dey = d->spr.sh / 2 + g_data.y / 2;
	if (d->spr.dey >= g_data.y)
		d->spr.dey = g_data.y - 1;
	d->spr.sw = ft_abs((int)(g_data.y / (d->spr.ty)));
	d->spr.dsx = -d->spr.sw / 2 + d->spr.ss;
	if (d->spr.dsx < 0)
		d->spr.dsx = 0;
	d->spr.dex = d->spr.sw / 2 + d->spr.ss;
	if (d->spr.dex >= g_data.x)
		d->spr.dex = g_data.x - 1;
}

void	draw_sprite(t_draw *d)
{
	int		stripe;
	int		y;
	int		color;
	int		index;

	stripe = d->spr.dsx;
	printf("start x : %d\n", d->spr.dsx);
	while (stripe < d->spr.dex)
	{
		d->spr.tex = (int)(256 * (stripe - (-d->spr.sw / 2 + d->spr.ss)) * 64 / d->spr.sw);
		y = d->spr.dsy;
		while(y < d->spr.dey)
		{
			if (d->spr.ty > 0 && stripe > 0 && stripe < g_data.x && d->spr.ty < d->spr.zbuff[stripe])
			{
				index = y * 256 - g_data.y * 128 + d->spr.sh * 128;
				d->spr.tey = ((index * 64) / d->spr.sh) / 256;
				color = g_data.s[0][64 * d->spr.tey + d->spr.tex];
				d->img.grid[y * g_data.x + stripe] = mlx_get_color_value(g_mlx.ptr, color);
				y++;
			}
		}
		stripe++;
	}
}
