/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:18:42 by macrespo          #+#    #+#             */
/*   Updated: 2019/12/03 12:16:23 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_data		g_data;

int		key_hook(int key, void *arg)
{
	(void)arg;
	printf("%d\n", key);
	if (key == 53)
	{
		mlx_destroy_window(g_data.mlx_ptr, g_data.mlx_win);
		exit(0);
	}
	else if (key == 0)
		mlx_string_put(g_data.mlx_ptr, g_data.mlx_win, 960, 540, 0xFF1493, "cube3d");
	return (key);
}

int		main(void)
{
	if ((g_data.mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if (!(g_data.mlx_win = mlx_new_window(g_data.mlx_ptr, 1920, 1080, "cube3d")))
		return (EXIT_FAILURE);
	mlx_key_hook(g_data.mlx_win, key_hook, NULL);
	mlx_loop(g_data.mlx_ptr);
	return (EXIT_SUCCESS);
}
