/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 13:23:44 by macrespo          #+#    #+#             */
/*   Updated: 2019/12/09 13:15:43 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include "get_next_line.h"

typedef struct		s_data
{
	int				x;
	int				y;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
	int				f;
	int				c;
	char			**map;
}					t_data;

char				*get_path(const char *s, int pos);
int					get_resolution(const char *s, int *pos);
int					parser(const char *file);
void				get_color(const char *s, char f_c);
extern t_data		g_data;
#endif
