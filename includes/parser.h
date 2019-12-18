/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 13:23:44 by macrespo          #+#    #+#             */
/*   Updated: 2019/12/18 11:41:57 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

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
char				**parse_map(const char *line, int *size);
int					get_resolution(const char *s, int *pos);
int					ft_isspace(char c);
int					parser(const char *file);
void				get_color(const char *s, int pos);
extern t_data		g_data;
#endif
