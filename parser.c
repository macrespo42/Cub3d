/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 18:07:56 by macrespo          #+#    #+#             */
/*   Updated: 2020/02/07 12:28:47 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			error_box(char *str)
{
	perror(str);
	close_window(1);
}

static int		data_init(void)
{
	g_data.map = NULL;
	g_data.no = NULL;
	g_data.so = NULL;
	g_data.we = NULL;
	g_data.ea = NULL;
	g_data.s = NULL;
	g_data.f = -1;
	g_data.c = -1;
	g_data.x = -1;
	g_data.y = -1;
	return (0);
}

static void		which_data(const char *line)
{
	int		i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == 'R')
	{
		g_data.x = parse_resolution(line, &i, g_data.x);
		g_data.x = g_data.x > 2560 ? 2560 : g_data.x;
		g_data.y = parse_resolution(line, &i, g_data.y);
		g_data.y = g_data.y > 1400 ? 1400 : g_data.y;
	}
	else if (line[i] == 'N' && line[i + 1] == 'O')
		g_data.no = parse_path(line, i + 2, g_data.no);
	else if (line[i] == 'S' && line[i + 1] == 'O')
		g_data.so = parse_path(line, i + 2, g_data.so);
	else if (line[i] == 'W' && line[i + 1] == 'E')
		g_data.we = parse_path(line, i + 2, g_data.we);
	else if (line[i] == 'E' && line[i + 1] == 'A')
		g_data.ea = parse_path(line, i + 2, g_data.ea);
	else if (line[i] == 'S')
		g_data.s = parse_path(line, i + 1, g_data.s);
	else if (line[i] == 'F' || line[i] == 'C')
		parse_color(line, i);
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
	else
		error_box("Error bad extension");
	return (-1);
}

int				parser(const char *file)
{
	int		ret;
	int		fd;
	char	*line;
	int		size_map;

	size_map = data_init();
	fd = open(file, O_RDONLY);
	ret = check_cubext(file);
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		which_data(line);
		if (line[0] == '1' || line[0] == '0' || line[0] == '2')
		{
			if (g_data.map != NULL)
				ft_memdel(g_data.map);
			g_data.map = parse_map(line, &size_map);
		}
		ft_memdel(line);
	}
	if (g_data.map == NULL)
		error_box("No map");
	return (ret);
}
