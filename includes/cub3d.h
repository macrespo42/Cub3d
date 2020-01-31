/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 14:57:38 by macrespo          #+#    #+#             */
/*   Updated: 2020/01/29 20:00:53 by macrespo         ###   ########.fr       */
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
	int				w;
	int				h;
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
	double	a;
	double	d_x;
	char	dir;
	int		s_nb;
}					t_cam;

typedef struct		s_hit
{
	double	x;
	double	y;
	double	side_dx;
	double	side_dy;
	double	delta_dx;
	double	delta_dy;
	double	wall_dist;
	int		step_x;
	int		step_y;
	int		map_x;
	int		map_y;
	int		wall;
	int		side;

}					t_hit;

typedef struct		s_ray
{
	double	x;
	double	y;
	double	d_x;
	double	d_y;
	int		i;
}					t_ray;

typedef struct		s_spr
{
	double	x;
	double	y;
	double	d;
}					t_spr;

typedef struct		s_draw
{
	t_cam	cam;
	t_img	img;
	t_ray	ray;
	t_hit	hit;
	t_spr	*spr;
	double	wall_x;
	double	tex_x;
	double	tex_y;
	int		start;
	int		end;
}					t_draw;

double				get_range(t_draw *d);
int					close_window(int error);
int					get_column(t_draw *d, int column, int size_wall);
int					key_hook(int key, void *arg);
int					sprite_init(t_draw *d);
int					sprite_position(t_draw *d, double dx, double dy, double ds);
t_cam				cam_infos(void);
unsigned int		wall_orient(t_draw *d);
void				draw(t_draw *d_infos);
void				horizontal_move(int event, t_draw *infos);
void				ray(t_draw *d);
void				rotate(int event, t_draw *d);
void				sort_sprites(t_draw *d);
void				vertical_move(int event, t_draw *infos);
extern t_mlx		g_mlx;
#endif
