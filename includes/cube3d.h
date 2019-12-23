/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 14:57:38 by macrespo          #+#    #+#             */
/*   Updated: 2019/12/23 11:09:48 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include "mlx.h"
# include "parser.h"
# define NAME "Cub3D"
# define WALL 0xc5002b
# define ESC 53
# define W 13
# define S 1
# define A 0
# define D 2

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

typedef struct		s_cam
{
	double	x;
	double	y;
	double	d_y;
	double	d_x;
	char	dir;
}					t_cam;

typedef struct		s_hit
{
	double	x;
	double	y;

}					t_hit;

double				get_range(t_cam cam);
int					close_window(void);
int					get_column(t_img *img, int column, int size_wall);
int					key_hook(int key, void *arg);
t_hit				get_wall_dist(t_cam cam);
void				vertical_move(int event, t_cam *cam);
extern t_mlx		g_mlx;
#endif
