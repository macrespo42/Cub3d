/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 13:23:44 by macrespo          #+#    #+#             */
/*   Updated: 2019/12/06 15:02:27 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# define BUFFER_SIZE 4096
# include <sys/stat.h>
# include <fcntl.h>
# include "get_next_line/get_next_line.h"

typedef struct		s_data
{
	int				x;
	int				y;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
	int				f[3];
	int				c[3];
	char			**map;
}					t_data;

int					get_resolution(char const *s, int *pos)
extern t_data		g_data;
#endif
