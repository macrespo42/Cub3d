/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:09:00 by macrespo          #+#    #+#             */
/*   Updated: 2020/01/28 17:09:03 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void			ft_sdraw(t_all *s, int loc, double dist)
{
	unsigned int	col;
	double			size;
	int				index;
	int				i;
	int				j;

	i = 0;
	j = 0;
	size = s->win.y / dist / 2;
	loc = loc - size / 2;
	while (i < size)
	{
		while ((loc + i >= 0 && loc + i < s->win.x) &&
				(j < size && s->stk[loc + i].d > dist))
		{
			col = 64 * floor(64 * (double)j / size) + (double)i / size * 64;
			col = s->tex.i[col];
			index = loc + i + (s->win.y / 2 + j) * s->win.x;
			if (index < s->win.x * s->win.y)
				s->img.adr[index] = ft_spixel(s, index, col);
			j++;
		}
		i++;
		j = 0;
	}
}

void			ft_slocate(t_all *s, double dirx, double diry, double dist)
{
	double	angle;

	dirx = (dirx - s->pos.x) / dist;
	diry = (diry - s->pos.y) / dist;
	if (diry <= 0)
		angle = acos(dirx) * 180 / M_PI;
	else
		angle = 360 - acos(dirx) * 180 / M_PI;
	angle = s->dir.a - angle + 33;
	if (angle >= 180)
		angle -= 360;
	else if (angle <= -180)
		angle += 360;
	ft_sdraw(s, angle * s->win.x / 66, dist);
}

void			ft_sorder(t_all *s)
{
	t_spr	tmp;
	int		i;
	int		j;

	i = 0;
	while (i < s->map.spr - 1)
	{
		j = i + 1;
		while (j < s->map.spr)
		{
			if (s->spr[i].d < s->spr[j].d)
			{
				tmp = s->spr[i];
				s->spr[i] = s->spr[j];
				s->spr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void			ft_sprite(t_all *s)
{
	int		i;
	double	dist;

	dist = hypot(s->dir.x, s->dir.y);
	if (s->dir.y <= 0)
		s->dir.a = acos(s->dir.x / dist) * 180 / M_PI;
	else
		s->dir.a = 360 - acos(s->dir.x / dist) * 180 / M_PI;
	i = 0;
	while (i < s->map.spr)
	{
		s->spr[i].d = hypot(s->spr[i].x - s->pos.x, s->spr[i].y - s->pos.y);
		i++;
	}
	ft_sorder(s);
	i = 0;
	while (i < s->map.spr)
	{
		ft_slocate(s, s->spr[i].x, s->spr[i].y, s->spr[i].d);
		i++;
	}
	free(s->stk);
}
