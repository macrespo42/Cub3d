/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 09:46:12 by macrespo          #+#    #+#             */
/*   Updated: 2019/12/20 16:49:53 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cube3d.h"

t_mlx		g_mlx;
t_data		g_data;

int		main(int ac, char **av)
{
	t_img	img;
	int		i;

	if ((g_mlx.ptr = mlx_init()) == NULL || parser(av[1]) == -1 || ac < 2)
		return (EXIT_FAILURE);
	if (!(g_mlx.win = mlx_new_window(g_mlx.ptr, g_data.x, g_data.y, NAME)))
		return (EXIT_FAILURE);
	img.ptr = mlx_new_image(g_mlx.ptr, g_data.x, g_data.y);
	img.grid = (unsigned int*)mlx_get_data_addr(img.ptr, &img.bpp, &img.sl, &img.ed);
	i = 0;
	while (i < g_data.x)
	{
		i = get_column(&img, i, g_data.y / get_range());
		i = (i - (g_data.x * g_data.y)) + 1;
	}
	mlx_put_image_to_window(g_mlx.ptr, g_mlx.win, img.ptr, 0, 0);
	mlx_key_hook(g_mlx.win, key_hook, NULL);
	mlx_hook(g_mlx.win, 17, 0, close_window, NULL);
	mlx_loop(g_mlx.ptr);
	return (EXIT_SUCCESS);
}
