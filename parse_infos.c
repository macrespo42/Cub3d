/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 14:04:45 by macrespo          #+#    #+#             */
/*   Updated: 2020/02/05 17:22:39 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		p_atoi(const char *str, int *pos)
{
	int		res;

	res = 0;
	while (ft_isspace(str[*pos]) && str[*pos])
		(*pos)++;
	if (str[*pos] == '-')
		return (-1);
	while (str[*pos] >= 48 && str[*pos] <= 57)
	{
		res = res * 10 + str[*pos] - '0';
		(*pos)++;
	}
	while (ft_isspace(str[*pos]) && str[*pos])
		(*pos)++;
	if (str[*pos] != ',')
		(*pos)--;
	return (res);
}

void			parse_color(const char *s, int pos)
{
	int		rgb[3];
	int		i;
	char	c;

	c = s[pos];
	i = 0;
	while (i < 3)
	{
		pos++;
		rgb[i] = p_atoi(s, &pos);
		if (rgb[i] < 0 || rgb[i] > 255)
			error_box("Invalid color");
		i++;
	}
	if (c == 'F' && g_data.f == -1)
		g_data.f = (int)pow(256, 2) * rgb[0] + 256 * rgb[1] + rgb[2];
	else if (c == 'C' && g_data.c == -1)
		g_data.c = (int)pow(256, 2) * rgb[0] + 256 * rgb[1] + rgb[2];
	else
		error_box("Double color");
}

unsigned int	**parse_path(const char *s, int pos, unsigned int **tex)
{
	char	*path;
	int		i;
	int		size_alloc;

	if (tex != NULL)
		error_box("Error double texture");
	size_alloc = 0;
	while (ft_isspace(s[pos]) && s[pos])
		pos++;
	i = pos;
	while (s[i++])
		size_alloc++;
	if (!(path = malloc(sizeof(char) * (size_alloc + 1))))
		return (NULL);
	i = 0;
	while (s[pos])
		path[i++] = s[pos++];
	path[i] = '\0';
	return (load_xpm(path));
}

int				parse_resolution(const char *s, int *pos)
{
	int		res;

	res = 0;
	if (*pos == 0 || (s[*pos] >= '0' && s[*pos] <= '9'))
		(*pos)++;
	while (ft_isspace(s[*pos]) && s[*pos])
		(*pos)++;
	while (s[*pos] >= '0' && s[*pos] <= '9')
	{
		res = res * 10 + s[*pos] - '0';
		(*pos)++;
	}
	(*pos)--;
	if (res <= 0)
		error_box("Invalid resolution");
	return (res);
}
