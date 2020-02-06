/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:00:45 by macrespo          #+#    #+#             */
/*   Updated: 2020/02/06 22:00:37 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	write_img(int fd, t_draw *d)
{
	unsigned char	buffer[COLOR_BUFFER];
	int				i;
	int				j;

	i = g_data.x * (g_data.y - 1);
	while (i >= 0)
	{
		j = 0;
		while (j < g_data.x)
		{
			buffer[0] = (unsigned char)(d->img.grid[i] % 256);
			buffer[1] = (unsigned char)(d->img.grid[i] / 256 % 256);
			buffer[2] = (unsigned char)(d->img.grid[i] / 256 / 256 % 256);
			buffer[3] = (unsigned char)0;
			write(fd, buffer, COLOR_BUFFER);
			j++;
			i++;
		}
		i -= 2 * g_data.x;
	}
}

void	write_infos_header(int fd)
{
	unsigned char	buffer[HEADER_INFO_SIZE];
	int				nb;

	nb = 0;
	while (nb < HEADER_INFO_SIZE)
		buffer[nb++] = (unsigned char)0;
	buffer[0] = (unsigned char)40;
	buffer[4] = (unsigned char)(g_data.x % 256);
	buffer[5] = (unsigned char)(g_data.x / 256 % 256);
	buffer[6] = (unsigned char)(g_data.x / 256 / 256 % 256);
	buffer[7] = (unsigned char)(g_data.x / 256 / 256 / 256 % 256);
	buffer[8] = (unsigned char)(g_data.y % 256);
	buffer[9] = (unsigned char)(g_data.y / 256 % 256);
	buffer[10] = (unsigned char)(g_data.y / 256 / 256 % 256);
	buffer[11] = (unsigned char)(g_data.y / 256 / 256 / 256 % 256);
	buffer[12] = (unsigned char)1;
	buffer[14] = (unsigned char)32;
	write(fd, buffer, HEADER_INFO_SIZE);
}

void	write_header(int fd)
{
	unsigned char	buffer[HEADER_SIZE];
	int				f_size;
	int				nb;

	nb = 0;
	while (nb < HEADER_SIZE)
		buffer[nb++] = (unsigned char)0;
	buffer[0] = (unsigned char)66;
	buffer[1] = (unsigned char)77;
	f_size = ((g_data.x * g_data.y) * 4) + 54;
	buffer[2] = (unsigned char)(f_size % 256);
	buffer[3] = (unsigned char)(f_size / 256 % 256);
	buffer[4] = (unsigned char)(f_size / 256 / 256 % 256);
	buffer[5] = (unsigned char)(f_size / 256 / 256 / 256 % 256);
	buffer[10] = (unsigned char)(54);
	write(fd, buffer, HEADER_SIZE);
}

void	create_bmp(t_draw *d)
{
	int		fd;

	fd = open("save.bmp", O_CREAT | O_WRONLY, S_IRUSR);
	if (fd == -1)
		perror("Error, while opening file");
	write_header(fd);
	write_infos_header(fd);
	write_img(fd, d);
	ft_memdel(d->img.ptr);
	ft_memdel(d->img.grid);
	if (close(fd) == -1)
		perror("Error, while closing file");
	close_window(0);
}
