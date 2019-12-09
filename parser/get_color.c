/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 12:57:35 by macrespo          #+#    #+#             */
/*   Updated: 2019/12/09 13:14:14 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int		p_atoi(const char *str, int *pos)
{
	int		res;

	res = 0;
	while (str[*pos] == '\t' || str[*pos] == '\n' || str[*pos] == '\r' || str[*pos] == '\v'
	|| str[*pos] == '\f' || str[*pos] == ' ')
		(*pos)++;
	while (str[*pos] >= 48 && str[*pos] <= 57)
	{
		res = res * 10 + str[*pos] - '0';
		(*pos)++;
	}
	(*pos)--;
	return (res);
}
void				get_color(const char *s, char f_c)
{
	int		rgb[3];
	int		i;

	i = 1;
	rgb[0] = p_atoi(s, &i);
	i += 1;
	rgb[1] = p_atoi(s, &i);
	i +=1;
	rgb[2] = p_atoi(s, &i);
	if (f_c == 'F')
		g_data.f = (int)pow(256, 2) * rgb[0] + 256 * rgb[1] + rgb[2];
	if (f_c == 'C')
		g_data.c = (int)pow(256, 2) * rgb[0] + 256 * rgb[1] + rgb[2];
}
