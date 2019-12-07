/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:28:52 by macrespo          #+#    #+#             */
/*   Updated: 2019/12/07 18:20:36 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*get_path(const char *s, int pos)
{
	char	*path;
	int		i;
	int		size_alloc;

	size_alloc = 0;
	while (s[pos] == '\t' || s[pos] == '\n' || s[pos] == '\r' || s[pos] == '\v'
	|| s[pos] == '\f' || s[pos] == ' ')
	{
		pos++;
		size_alloc++;
	}
	if (!(path = malloc(sizeof(char) * (ft_strlen(s) - size_alloc) + 1)))
		return (NULL);
	i = 0;
	while (s[pos])
	{
		path[i] = s[pos];
		pos++;
	}
	return (path);
}
