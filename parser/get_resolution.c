/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_atoi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 22:35:41 by macrespo          #+#    #+#             */
/*   Updated: 2019/12/05 22:40:07 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		p_atoi(char const *s, int *pos)
{
	int		res;

	res = 0;
	while (s[*pos] == '\t' || s[*pos] == '\n' || s[*pos] == '\r' || s[*pos] == '\v'
	|| s[*pos] == '\f' || s[*pos] == ' ')
		*pos += 1;
	while (s[*pos] >= '0' && s[*pos] <= '9')
	{
		res = res * 10 + s[*pos] - '0';
		*pos++;
	}
	return (res);
}
