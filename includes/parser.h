/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 13:23:44 by macrespo          #+#    #+#             */
/*   Updated: 2020/01/31 17:02:18 by macrespo         ###   ########.fr       */
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

typedef struct				s_data
{
	int						x;
	int						y;
	unsigned int			**no;
	unsigned int			**so;
	unsigned int			**we;
	unsigned int			**ea;
	unsigned int			**s;
	int						f;
	int						c;
	int						x_len;
	int						y_len;
	char					**map;
}							t_data;

char						**parse_map(const char *line, int *size);
int							parse_resolution(const char *s, int *pos);
int							ft_isspace(char c);
int							parser(const char *file);
unsigned int				**load_xpm(char *path);
unsigned int				**parse_path(const char *s, int pos, unsigned int **tex);
void						parse_color(const char *s, int pos);
extern t_data				g_data;
#endif
