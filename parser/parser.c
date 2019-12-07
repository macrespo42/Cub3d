/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 18:07:56 by macrespo          #+#    #+#             */
/*   Updated: 2019/12/07 18:54:44 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_data	g_data;

static void		which_data(const char *line)
{
	int		i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == 'R')
	{
		g_data.x = get_resolution(line, &i);
		g_data.y = get_resolution(line, &i);
	}
	else if (line[i] == 'N' && line[i + 1] == 'O')
		g_data.no = get_path(line, i);
	else if (line[i] == 'S' && line[i + 1] == 'O')
		g_data.so = get_path(line, i);
	else if (line[i] == 'W' && line[i + 1] == 'E')
		g_data.we = get_path(line, i);
	else if (line[i] == 'E' && line[i + 1] == 'A')
		g_data.ea = get_path(line, i);
	else if (line[i] == 'S')
		g_data.s = get_path(line, i);
}

int				parser(const char *file)
{
	int		ret;
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		which_data(line);
		printf("%s\n", line);
		free(line);
	}
	return (0);
}
