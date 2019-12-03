/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 14:57:38 by macrespo          #+#    #+#             */
/*   Updated: 2019/12/02 18:30:09 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <mlx.h>

typedef struct		s_img
{
	void			*id;
	unsigned int	*data;
	int				bpp;
	int				sl;
	int				ed;
}					t_img;
/*
**
** bite
**
*/
typedef struct		s_data
{
	void			*mlx_ptr;
	void			*mlx_win;
	t_img			img;
}					t_data;
#endif
