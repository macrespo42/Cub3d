/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 19:27:50 by macrespo          #+#    #+#             */
/*   Updated: 2019/12/18 11:42:45 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int		is_map(char c)
{
	if (c == '0' || c == '1' || c == '2')
		return (1);
	else if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

static int		size_trim(char *line)
{
	int		i;
	int		size;


	size = 0;
	i = 0;
	while (line[i])
	{
		if (is_map(line[i]))
			size++;
		i++;
	}
	return (size);
}

static char		*trim_map(char *line)
{
	int		i;
	int		j;
	int		size;
	char	*new_map;

	size = size_trim(line);
	if (!(new_map = malloc(sizeof(char) * size + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (i < size)
	{
		if (is_map(line[i]) == 1)
			new_map[j++] = line[i];
		i++;
	}
	new_map[j] = '\0';
	return (new_map);
}

char			**parse_map(const char *line, int *size)
{
	char	**map_tmp;
	int		i;

	i = 0;
	if (!(map_tmp = malloc(sizeof(char*) * ((*size) + 2))))
		return (NULL);
	while (i < *size)
	{
		map_tmp[i] = g_data.map[i];
		i++;
	}
	map_tmp[*size] = trim_map((char*)line);
	map_tmp[*size + 1] = NULL;
	(*size)++;
	return(map_tmp);
}
