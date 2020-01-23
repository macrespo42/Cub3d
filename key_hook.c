/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:14:24 by macrespo          #+#    #+#             */
/*   Updated: 2020/01/23 13:16:37 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		close_window(void)
{
	int		y;

	mlx_destroy_window(g_mlx.ptr, g_mlx.win);
	y = 0;
	while (y < 64)
	{
		free(g_data.no[y]);
		free(g_data.so[y]);
		free(g_data.we[y]);
		free(g_data.ea[y]);
		free(g_data.s[y]);
		y++;
	}
	free((void*)g_data.no);
	free((void*)g_data.so);
	free((void*)g_data.we);
	free((void*)g_data.ea);
	free((void*)g_data.s);
	free(g_mlx.ptr);
	exit(0);
	return (0);
}

int		key_hook(int key, void *arg)
{
	(void)arg;
	if (key == ESC)
		close_window();
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
