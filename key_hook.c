/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:14:24 by macrespo          #+#    #+#             */
/*   Updated: 2019/12/20 16:50:08 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		key_hook(int key, void *arg)
{
	(void)arg;
	printf("%d\n", key);
	if (key == ESC)
		close_window();
	// if (key == W)
	// 	vertical_move(W, cam);
	// if (key == S)
	// 	vertical_move(S), cam);
	// else if (key == 0)
		mlx_string_put(g_mlx.ptr, g_mlx.win, 360, 240, WALL, NAME);
	return (key);
}
