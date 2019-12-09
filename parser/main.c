/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 09:46:12 by macrespo          #+#    #+#             */
/*   Updated: 2019/12/09 10:12:24 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_data		g_data;

void	print_data()
{
	printf("RESOLUTION : %d x %d \n", g_data.x, g_data.y);
}

int		main(int ac, char **av)
{
	if (ac == 2 || ac == 3)
	{
		parser(av[1]);
		print_data();
	}
	else
		write(1, "Error\n", 6);
}
