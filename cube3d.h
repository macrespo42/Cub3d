/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 14:57:38 by macrespo          #+#    #+#             */
/*   Updated: 2019/12/16 17:18:18 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <mlx.h>
# include "parser.h"
# define NAME "Cub3D"
# define SKY 0x87ceeb
# define FLOOR 0xcd8500
# define CUBE 0xc5002b
# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2

typedef struct		s_img
{
	void			*ptr;
	unsigned int	*grid;
	int				bpp;
	int				sl;
	int				ed;
}					t_img;

typedef struct		s_mlx
{
	void			*ptr;
	void			*win;
	t_img			img;
}					t_mlx;

int					close_window(void);
int					get_column(t_img *img, int column);
int					key_hook(int key, void *arg);
extern t_mlx		g_mlx;
#endif
