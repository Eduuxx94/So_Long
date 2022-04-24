/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jogo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 20:49:43 by ede-alme          #+#    #+#             */
/*   Updated: 2022/04/19 22:13:30 by ede-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_1thlrules(char **map)
{
	int	i;

	i = 0;
	while (map[0][i] == '1')
		i++;
	if (map[0][i] == '\n' && map[0][i + 1] == '\0')
		return (i);
	return (0);
}

void	ft_check_map(char **map, int y, char *path)
{
	t_vars	var;

	var.y = 1;
	var.x = 0;
	var.i = ft_check_1thlrules(map);
	if (var.i <= 3)
		printf("Your map %s not have the requested width.\n", path);
	while (var.y < y && var.y > 0 && var.i > 0)
	{
		while (map[var.y][var.x] == '0' || map[var.y][var.x] == '1' || map
		[var.y][var.x] == 'C' || map[var.y][var.x] == 'E' || map[var.y][var.x]
		== 'P' || map[var.y][var.x] == '2')
			var.x++;
		if (var.x != var.i && map[var.y][var.x] != 10 && map[var.y][var.x] != 0)
			var.y = 0;
		else
			var.y++;
		var.x = 0;
		printf("Linha com exito\n");
	}
	if (var.y <= 0)
		printf("A error was found in your map body.\n");
	if (var.y == y)
		printf("Ultima linha do mapa.\n");
}

/*ft_readmap is the fuction responsable for read map, put in memory, check all
rules and init the graphical minilibx, after all graphical code free all map.*/
void	ft_readmap(int fd, char *map)
{
	t_vars	var;

	var.y = 0;
	printf("Starting to read the map...\n");
	if (!fd || fd < 0)
		exit (printf("The system cannot find the argued file.\n"));
	else
	{
		while (1)
		{
			var.map[var.y] = get_next_line(fd);
			if (var.map[var.y] == NULL)
			{
				if (var.y <= 3)
					printf("Your map %s not have the requested height.\n", map);
				else
					ft_check_map(var.map, var.y - 1, map);
				break ;
			}
			var.y++;
		}
		while (var.y >= 0)
			free (var.map[var.y--]);
	}
}

int	main(int argc, char **argv)
{
	int			fd;
	t_vars		var;

	var.i = 0;
	if (argc == 2)
	{
		while (argv[1][var.i] != '\0')
			var.i++;
		if (var.i > 4 && argv[1][var.i - 4] == '.' && argv[1][var.i - 3] == 'b'
		&& argv[1][var.i - 2] == 'e' && argv[1][var.i - 1] == 'r')
		{
			fd = open(argv[1], O_RDONLY);
			ft_readmap(fd, argv[1]);
			close (fd);
		}
		else
			printf("Your map.ber does not match the requested name\n");
	}
	else
		printf("Insert 'map_name.ber' as argument\n");
	return (0);
}
