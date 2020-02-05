/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:14:24 by macrespo          #+#    #+#             */
/*   Updated: 2020/02/05 20:07:30 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		free_datas(void)
{
	int		y;

	y = 0;
	if (g_data.map)
	{
		while (g_data.map[y])
		{
			ft_memdel(g_data.map[y]);
			y++;
		}
	}
	ft_memdel(g_data.map);
	ft_memdel(g_data.no);
	ft_memdel(g_data.so);
	ft_memdel(g_data.we);
	ft_memdel(g_data.ea);
	ft_memdel(g_data.s);
}

int				close_window(int error)
{
	int		y;

	if (error == 0)
		mlx_destroy_window(g_mlx.ptr, g_mlx.win);
	y = 0;
	while (y < 64)
	{
		if (g_data.no != NULL)
			ft_memdel(g_data.no[y]);
		if (g_data.so != NULL)
			ft_memdel(g_data.so[y]);
		if (g_data.we != NULL)
			ft_memdel(g_data.we[y]);
		if (g_data.ea != NULL)
			ft_memdel(g_data.ea[y]);
		if (g_data.s != NULL)
			ft_memdel(g_data.s[y]);
		y++;
	}
	free_datas();
	ft_memdel(g_mlx.ptr);
	exit(error);
	return (0);
}

int				key_hook(int key, void *arg)
{
	(void)arg;
	if (key == ESC)
		close_window(0);
	else if (key == W)
		vertical_move(W, arg);
	else if (key == S)
		vertical_move(S, arg);
	else if (key == A)
		horizontal_move(A, arg);
	else if (key == D)
		horizontal_move(D, arg);
	else if (key == LEFT)
		rotate(LEFT, arg);
	else if (key == RIGHT)
		rotate(RIGHT, arg);
	return (key);
}
