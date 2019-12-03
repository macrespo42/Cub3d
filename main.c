/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:18:42 by macrespo          #+#    #+#             */
/*   Updated: 2019/12/03 14:28:50 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
t_data		g_data;

int close_window(void)
{
	mlx_destroy_window(g_data.mlx_ptr, g_data.mlx_win);
	exit(0);
	return (0);
}

int		key_hook(int key, void *arg)
{
	(void)arg;
	printf("%d\n", key);
	if (key == 53)
		close_window();
	else if (key == 0)
		mlx_string_put(g_data.mlx_ptr, g_data.mlx_win, 360, 240, SKY, NAME);
	return (key);
}

int		main(void)
{
	if ((g_data.mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if (!(g_data.mlx_win = mlx_new_window(g_data.mlx_ptr, 720, 480, NAME)))
		return (EXIT_FAILURE);
	mlx_key_hook(g_data.mlx_win, key_hook, NULL);
	mlx_hook(g_data.mlx_win, 17, 0, close_window, NULL);
	mlx_loop(g_data.mlx_ptr);
	return (EXIT_SUCCESS);
}
