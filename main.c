/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 09:46:12 by macrespo          #+#    #+#             */
/*   Updated: 2020/01/17 14:55:27 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_mlx		g_mlx;
t_data		g_data;

int				main(int ac, char **av)
{
	t_draw	d_infos;

	if ((g_mlx.ptr = mlx_init()) == NULL || parser(av[1]) == -1 || ac < 2)
		return (EXIT_FAILURE);
	if (!(g_mlx.win = mlx_new_window(g_mlx.ptr, g_data.x, g_data.y, NAME)))
		return (EXIT_FAILURE);
	d_infos.cam = cam_infos();
	draw(&d_infos);
	mlx_hook(g_mlx.win, 2, 0, key_hook, &d_infos);
	mlx_hook(g_mlx.win, 17, 0, close_window, NULL);
	mlx_loop(g_mlx.ptr);
	return (EXIT_SUCCESS);
}
