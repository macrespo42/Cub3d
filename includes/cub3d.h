/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 14:57:38 by macrespo          #+#    #+#             */
/*   Updated: 2020/01/10 16:12:31 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
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
# define LEFT 123
# define RIGHT 124
# define TURN 0.05
# define FOV 33

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
}					t_mlx;

typedef struct		s_cam
{
	double	x;
	double	y;
	double	p_x;
	double	p_y;
	double	d_y;
	double	d_x;
	char	dir;
}					t_cam;

typedef struct		s_hit
{
	double	x;
	double	y;
	double	side_dx;
	double	side_dy;
	double	delta_dx;
	double	delta_dy;
	int		step_x;
	int		step_y;
	int		wall;
	int		side;

}					t_hit;

typedef struct		s_ray
{
	double	x;
	double	y;
	int		i;
}					t_ray;

typedef struct		s_draw
{
	t_cam	cam;
	t_img	img;
	t_ray	ray;
	t_hit	hit;
}					t_draw;

double				get_range(t_draw *draw);
int					close_window(void);
int					get_column(t_img *img, int column, int size_wall);
int					key_hook(int key, void *arg);
int					wall_hit(t_hit hit);
t_cam				cam_infos(void);
int					get_wall_dist(t_draw *draw, int map_x, int map_y);
void				draw(t_draw *d_infos);
void				horizontal_move(int event, t_draw *infos);
void				ray(t_draw *draw);
void				rotate(int event, t_draw *dir);
void				vertical_move(int event, t_draw *infos);
extern t_mlx		g_mlx;
#endif
