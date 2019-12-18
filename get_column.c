/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_column.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:56:44 by macrespo          #+#    #+#             */
/*   Updated: 2019/12/18 15:39:08 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		get_column(t_img *img, int column, int size_wall)
{
	int		px;

	px = 0;
	while (column < g_data.x * (g_data.y - size_wall) / 2)
	{
		img->grid[column] = mlx_get_color_value(g_mlx.ptr, g_data.f);
		column += g_data.x;
	}
	while (px < size_wall)
	{
		img->grid[column] = mlx_get_color_value(g_mlx.ptr, WALL);
		column += g_data.x;
		px++;
	}
	while (column < (g_data.x * g_data.y))
	{
		img->grid[column] = mlx_get_color_value(g_mlx.ptr, g_data.c);
		column += g_data.x;
	}
	return (column);
}
