/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 18:07:56 by macrespo          #+#    #+#             */
/*   Updated: 2019/12/19 12:41:39 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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
		g_data.no = get_path(line, i + 2);
	else if (line[i] == 'S' && line[i + 1] == 'O')
		g_data.so = get_path(line, i + 2);
	else if (line[i] == 'W' && line[i + 1] == 'E')
		g_data.we = get_path(line, i + 2);
	else if (line[i] == 'E' && line[i + 1] == 'A')
		g_data.ea = get_path(line, i + 2);
	else if (line[i] == 'S')
		g_data.s = get_path(line, i + 1);
	else if (line[i] == 'F' || line[i] == 'C')
		get_color(line, i);
}

static int		check_cubext(const char *file)
{
	int		len;

	len = ft_strlen(file) - 1;
	if (file[len] == 'b' && file[len - 1] == 'u' && file[len - 2] == 'c')
	{
		if (file[len - 3] == '.')
			return (1);
	}
	write(1, "Bad file type\n", 14);
	return (-1);
}

void	print_map()
{
	int		i = 0;
	while (g_data.map[i])
	{
		printf("%s\n", g_data.map[i]);
		i++;
	}
}

int				parser(const char *file)
{
	int		ret;
	int		fd;
	char	*line;
	int		size_map;

	size_map = 0;
	fd = open(file, O_RDONLY);
	ret = check_cubext(file);
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		which_data(line);
		if (line[0] == '1')
		{
			g_data.map = parse_map(line, &size_map);
		}
		free(line);
	}
	print_map();
	return (ret);
}