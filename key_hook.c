/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:14:24 by macrespo          #+#    #+#             */
/*   Updated: 2020/01/23 18:11:14 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		free_textures(void)
{
	if (g_data.no != NULL)
		free(g_data.no);
	if (g_data.so != NULL)
		free(g_data.so);
	if (g_data.we != NULL)
		free(g_data.we);
	if (g_data.ea != NULL)
		free(g_data.ea);
	if (g_data.s != NULL)
		free(g_data.s);
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
			free(g_data.no[y]);
		if (g_data.so != NULL)
			free(g_data.so[y]);
		if (g_data.we != NULL)
			free(g_data.we[y]);
		if (g_data.ea != NULL)
			free(g_data.ea[y]);
		if (g_data.s != NULL)
			free(g_data.s[y]);
		y++;
	}
	free_textures();
	if (g_data.no == NULL || error == 1)
		perror("Error bad xpm");
	free(g_mlx.ptr);
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
