#ifndef CUB3D_H
# define CUB3D_H

# include "../mlxopengl/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

# define NONE 0xFF000000
# define WHITE 0x00FFFFFF
# define BLACK 0x00000000
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define MAGENTA 0x00FF00FF
# define YELLOW 0x00FFFF00
# define CYAN 0x0000FFFF

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

# define SPEED 15
# define TURN 0.05

typedef struct	s_mlx
{
	void			*ptr;
}				t_mlx;

typedef struct	s_win
{
	void			*ptr;
	int				x;
	int				y;
}				t_win;

typedef struct	s_img
{
	void			*ptr;
	unsigned int	*adr;
	int				fsh;
}				t_img;

typedef struct	s_err
{
	int				n;
	int				m;
	int				p;
}				t_err;

typedef struct	s_map
{
	char			**tab;
	int				x;
	int				y;
	int				spr;
}				t_map;

typedef struct	s_tex
{
	unsigned int	*n;
	unsigned int	*s;
	unsigned int	*e;
	unsigned int	*w;
	unsigned int	*i;
	unsigned int	c;
	unsigned int	f;
}				t_tex;

typedef struct	s_pos
{
	double			x;
	double			y;
}				t_pos;

typedef struct	s_dir
{
	double			x;
	double			y;
	double			a;
}				t_dir;

typedef struct	s_ray
{
	double			x;
	double			y;
	int				i;
	double			v;
	double			w;
}				t_ray;

typedef struct	s_hit
{
	double			x;
	double			y;
	double			d;
}				t_hit;

typedef struct	s_spr
{
	double			x;
	double			y;
	double			d;
}				t_spr;

typedef struct	s_stk
{
	double			x;
	double			y;
	double			d;
}				t_stk;

typedef struct	s_all
{
	t_mlx			mlx;
	t_win			win;
	t_img			img;
	t_err			err;
	t_map			map;
	t_tex			tex;
	t_pos			pos;
	t_dir			dir;
	t_ray			ray;
	t_hit			hit;
	t_spr			*spr;
	t_stk			*stk;
}				t_all;
