/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 12:57:35 by macrespo          #+#    #+#             */
/*   Updated: 2019/12/10 15:59:35 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int		p_atoi(const char *str, int *pos)
{
	int		res;

	res = 0;
	while (ft_isspace(str[*pos]) && str[*pos])
		(*pos)++;
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
void				get_color(const char *s, int pos)
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
		printf("RGB : %d\n", rgb[i]);
		i++;
	}
	if (c == 'F')
		g_data.f = (int)pow(256, 2) * rgb[0] + 256 * rgb[1] + rgb[2];
	if (c == 'C')
		g_data.c = (int)pow(256, 2) * rgb[0] + 256 * rgb[1] + rgb[2];
}
