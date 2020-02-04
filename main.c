/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 09:46:12 by macrespo          #+#    #+#             */
/*   Updated: 2020/02/04 18:58:31 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_mlx		g_mlx;
t_data		g_data;

static int		check_map(void)
{
	int		x;
	int		y;

	y = 0;
	while (g_data.map[y])
	{
		if (y == g_data.y_len || y == 0)
		{
			x = 0;
			while (x < g_data.x_len)
			{
				if (g_data.map[y][x] != '1')
					return (0);
				x++;
			}
		}
		if (!(g_data.map[y][0] == '1' && g_data.map[y][g_data.x_len] == '1'))
			return (0);
		y++;
	}
	return (1);
}

int				main(int ac, char **av)
{
	t_draw	d_infos;

	if (ac < 2 || ac > 3)
		return (EXIT_FAILURE);
	if ((g_mlx.ptr = mlx_init()) == NULL || parser(av[1]) == -1)
		return (EXIT_FAILURE);
	if (!(g_mlx.win = mlx_new_window(g_mlx.ptr, g_data.x, g_data.y, NAME)))
		return (EXIT_FAILURE);
	d_infos.cam = cam_infos();
	if (check_map() == 0)
	{
		perror("Map error");
		close_window(1);
	}
	sprite_init(&d_infos);
	draw(&d_infos);
	mlx_hook(g_mlx.win, 2, 0, key_hook, &d_infos);
	mlx_hook(g_mlx.win, 17, 0, close_window, NULL);
	mlx_loop(g_mlx.ptr);
	return (EXIT_SUCCESS);
}
