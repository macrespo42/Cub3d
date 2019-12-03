/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:18:42 by macrespo          #+#    #+#             */
/*   Updated: 2019/12/03 15:55:29 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
t_mlx		g_mlx;

int close_window(void)
{
	mlx_destroy_window(g_mlx.mlx_ptr, g_mlx.mlx_win);
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
		mlx_string_put(g_mlx.mlx_ptr, g_mlx.mlx_win, 360, 240, CUBE, NAME);
	return (key);
}

int		main(void)
{
	t_img	img;
	t_data	data;
	int		i;

	data.x = 720;
	data.y = 480;
	if ((g_mlx.mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if (!(g_mlx.mlx_win = mlx_new_window(g_mlx.mlx_ptr, 720, 480, NAME)))
		return (EXIT_FAILURE);
	img.ptr = mlx_new_image(g_mlx.mlx_ptr, 720, 480);
	img.grid = (unsigned int*)mlx_get_data_addr(img.ptr, &img.bpp, &img.sl, &img.ed);
	i = 0;
	while (i < data.x)
	{
		while (i < (data.x * data.y) / 2)
		{
			img.grid[i] = mlx_get_color_value(g_mlx.mlx_ptr, SKY);
			i += data.x;
		}
		while (i < (data.x * data.y))
		{
			img.grid[i] = mlx_get_color_value(g_mlx.mlx_ptr, FLOOR);
			i += data.x;
		}
		i = (i - (data.x * data.y)) + 1;
	}
	mlx_put_image_to_window(g_mlx.mlx_ptr, g_mlx.mlx_win, img.ptr, 0, 0);
	mlx_key_hook(g_mlx.mlx_win, key_hook, NULL);
	mlx_hook(g_mlx.mlx_win, 17, 0, close_window, NULL);
	mlx_loop(g_mlx.mlx_ptr);
	return (EXIT_SUCCESS);
}
