/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:14:24 by macrespo          #+#    #+#             */
/*   Updated: 2020/01/15 15:16:53 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		close_window(void)
{
	mlx_destroy_window(g_mlx.ptr, g_mlx.win);
	exit(0);
	return (0);
}

int		key_hook(int key, void *arg)
{
	(void)arg;
	if (key == ESC)
		close_window();
	else if (key == W)
		printf("W\n");
	else if (key == S)
		printf("S\n");
	else if (key == A)
		printf("A\n");
	else if (key == D)
		printf("D\n");
	else if (key == LEFT)
		rotate(LEFT, arg);
	else if (key == RIGHT)
		rotate(RIGHT, arg);
	return (key);
}
