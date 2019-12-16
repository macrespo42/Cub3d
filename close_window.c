/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:57:06 by macrespo          #+#    #+#             */
/*   Updated: 2019/12/16 17:50:04 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		close_window(void)
{
	mlx_destroy_window(g_mlx.ptr, g_mlx.win);
	exit(0);
	return (0);
}
