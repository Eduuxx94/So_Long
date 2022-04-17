/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:03:15 by ede-alme          #+#    #+#             */
/*   Updated: 2022/04/16 17:55:30 by ede-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "so_long.h"
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	ft_realoc2(char *line, char *buff, int i_line, int *buff_size)
{
	int	i_buff;
	int	i_sobra;

	i_sobra = -1;
	i_buff = 0;
	while (line && buff[i_buff])
	{
		if (i_sobra == -1)
		{
			line[i_line++] = buff[i_buff];
			if (buff[i_buff] == '\n')
				i_sobra++;
		}
		else
			buff[i_sobra++] = buff[i_buff];
		buff[i_buff++] = 0;
	}
	if (i_sobra != -1)
		*buff_size = 0;
}

void	*ft_realoc(char *line, char *buff, int line_size, int *buff_size)
{
	char	*temp;
	int		i_line;

	i_line = 0;
	temp = line;
	line = malloc(sizeof(char) * line_size + 1);
	if (line == 0)
		return (0);
	line[line_size] = 0;
	while (temp && temp[i_line])
	{
		line[i_line] = temp[i_line];
		i_line++;
	}
	if (temp)
		free(temp);
	ft_realoc2(line, buff, i_line, buff_size);
	return (line);
}

int	get_size_linha(char *buff)
{
	int	i;

	i = 0;
	while (buff && buff[i] != '\0')
	{			
		if (buff[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

char	*get_next_line(int fd)
{
	static char	buff[1 + 1];
	int		buff_size;
	char	*line;
	int		line_size;

	line_size = 0;
	line = NULL;
	buff_size = 0;
	while (1)
	{
		if (!buff[0])
			buff_size = read(fd, buff, 1);
		else
			buff_size = 1;
		line_size += get_size_linha(buff);
		if (buff_size > 0)
			line = ft_realoc(line, buff, line_size, &buff_size);
		if (buff_size <= 0)
			return (line);
	}
	return (line);
}
/*
int	main(void)
{
	int		fd1;
	char	*texto;

	fd1 = open("./Maps/map5.ber", O_RDONLY);
	texto = get_next_line(fd1);
	printf("%s", texto);
	free (texto);
	texto = get_next_line(fd1);
	printf("%s", texto);
	free (texto);
	close(fd1);
	return (0);
}
*/