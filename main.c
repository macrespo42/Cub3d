/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:18:42 by macrespo          #+#    #+#             */
/*   Updated: 2019/12/04 15:14:16 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
t_mlx		g_mlx;

int		main(void)
{
	t_img	img;
	t_data	data;
	int		i;

	data.x = 720;
	data.y = 480;
	if ((g_mlx.ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if (!(g_mlx.win = mlx_new_window(g_mlx.ptr, 720, 480, NAME)))
		return (EXIT_FAILURE);
	img.ptr = mlx_new_image(g_mlx.ptr, 720, 480);
	img.grid = (unsigned int*)mlx_get_data_addr(img.ptr, &img.bpp, &img.sl, &img.ed);
	i = 0;
	while (i < data.x)
	{
		i = get_column(&img, data, i);
		i = (i - (data.x * data.y)) + 1;
	}
	mlx_put_image_to_window(g_mlx.ptr, g_mlx.win, img.ptr, 0, 0);
	mlx_key_hook(g_mlx.win, key_hook, NULL);
	mlx_hook(g_mlx.win, 17, 0, close_window, NULL);
	mlx_loop(g_mlx.ptr);
	return (EXIT_SUCCESS);
}
