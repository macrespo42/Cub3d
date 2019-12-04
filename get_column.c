/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_column.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:56:44 by macrespo          #+#    #+#             */
/*   Updated: 2019/12/04 15:13:45 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		get_column(t_img *img, t_data data, int column)
{
	while (column < (data.x * data.y))
	{
		img->grid[column] = mlx_get_color_value(g_mlx.ptr, SKY);
		column += data.x;
	}
	return (column);
}
