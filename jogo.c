/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jogo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 20:49:43 by ede-alme          #+#    #+#             */
/*   Updated: 2022/04/17 23:00:08 by ede-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_map(char **map, int y)
{
	t_vars	var;

	var.i = 0;
	//while (var.i < y)
		//printf("%s", map[var.i++]);
	//printf("\nAn error was found on the map.\n");
}

void	ft_readmap(int fd)
{
	t_vars	var;

	var.y = 0;
	printf("Inicio\n");
	if (!fd || fd < 0)
		exit (printf("The system cannot find the argued file.\n"));
	else
	{
		while (1)
		{
			var.map[var.y] = get_next_line(fd);
			if (!var.map[var.y] || var.map[var.y][0] == '(' &&
			var.map[var.y][1] == 'n' && var.map[var.y][2] == 'u' &&
			var.map[var.y][3] == 'l' && var.map[var.y][4] == 'l' &&
			var.map[var.y][5] == ')' && var.map[var.y][6] == '\0')
			{
				free (var.map[var.y]);
				ft_check_map(var.map, var.y);
				break ;
			}
			var.y++;
		}
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		fd;
	t_vars	var;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i] != '\0')
			i++;
		if (i > 4 && argv[1][i - 4] == '.' && argv[1][i - 3] == 'b' &&
		argv[1][i - 2] == 'e' && argv[1][i - 1] == 'r')
		{
			fd = open(argv[1], O_RDONLY);
			ft_readmap(fd);
			close (fd);
		}
		else
			printf("Your map.ber does not match the requested name\n");
	}
	else
		printf("Runtime ERROR.\nInsert 'map_name.ber' as argument\n");
	return (0);
}
