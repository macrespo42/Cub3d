/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 09:46:12 by macrespo          #+#    #+#             */
/*   Updated: 2019/12/23 11:10:08 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cube3d.h"

t_mlx		g_mlx;
t_data		g_data;

static int			is_pos(char c, t_cam *cam)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		if (c == 'N')
		{
			cam->d_x = 0;
			cam->d_y = -1;
		}
		else if (c == 'S')
		{
			cam->d_x = 0;
			cam->d_y = 1;
		}
		else if (c == 'W')
		{
			cam->d_x = -1;
			cam->d_y = 0;
		}
		else if (c == 'E')
		{
			cam->d_x = 1;
			cam->d_y = 0;
		}
		return (1);
	}
	return (0);
}

static t_cam		cam_infos()
{
	int		i;
	int		j;
	t_cam	cam;

	i = 0;
	while(g_data.map[i])
	{
		j = 0;
		while (g_data.map[i][j])
		{
			if (is_pos(g_data.map[i][j], &cam))
			{
				cam.x = (double)j + 0.5;
				cam.y = (double)i + 0.5;
				cam.dir = g_data.map[i][j];
				return (cam);
			}
			j++;
		}
		i++;
	}
	return (cam);
}

static void		draw(t_img *img, t_cam *cam)
{
	int		i;
	img->ptr = mlx_new_image(g_mlx.ptr, g_data.x, g_data.y);
	img->grid = (unsigned int*)mlx_get_data_addr(img->ptr, &img->bpp, &img->sl, &img->ed);
	*cam = cam_infos();
	i = 0;
	while (i < g_data.x)
	{
		i = get_column(img, i, g_data.y / get_range(*cam));
		i = (i - (g_data.x * g_data.y)) + 1;
	}
	mlx_put_image_to_window(g_mlx.ptr, g_mlx.win, img->ptr, 0, 0);
}

int		main(int ac, char **av)
{
	t_img	img;
	t_cam	cam;

	if ((g_mlx.ptr = mlx_init()) == NULL || parser(av[1]) == -1 || ac < 2)
		return (EXIT_FAILURE);
	if (!(g_mlx.win = mlx_new_window(g_mlx.ptr, g_data.x, g_data.y, NAME)))
		return (EXIT_FAILURE);
	draw(&img, &cam);
	mlx_hook(g_mlx.win, 2, 0, key_hook, &cam);
	mlx_hook(g_mlx.win, 17, 0, close_window, NULL);
	mlx_loop(g_mlx.ptr);
	return (EXIT_SUCCESS);
}
