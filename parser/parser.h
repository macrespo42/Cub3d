/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 13:23:44 by macrespo          #+#    #+#             */
/*   Updated: 2019/12/05 17:29:13 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# define BUFFER_SIZE 4096
# include <stdlib.h>

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
extern t_data		g_data;
#endif
