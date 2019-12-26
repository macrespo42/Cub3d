/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:28:52 by macrespo          #+#    #+#             */
/*   Updated: 2019/12/26 13:48:32 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*parse_path(const char *s, int pos)
{
	char	*path;
	int		i;
	int		size_alloc;

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
	{
		path[i] = s[pos];
		i++;
		pos++;
	}
	path[i] = '\0';
	return (path);
}
