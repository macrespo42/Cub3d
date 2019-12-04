/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 14:57:38 by macrespo          #+#    #+#             */
/*   Updated: 2019/12/04 15:15:48 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <mlx.h>
# define NAME "cube3d"
# define SKY 0x87ceeb
# define FLOOR 0xcd8500
# define CUBE 0xc5002b

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

typedef struct		s_data
{
	int				x;
	int				y;
}					t_data;

int					close_window(void);
int					get_column(t_img *img, t_data data, int column);
int					key_hook(int key, void *arg);
extern t_mlx		g_mlx;
#endif
