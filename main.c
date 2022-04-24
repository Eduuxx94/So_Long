/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 20:49:43 by ede-alme          #+#    #+#             */
/*   Updated: 2022/04/24 21:29:37 by ede-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_contains(t_vars *vr, char mapcase)
{
	if (mapcase == 'E')
		vr->exi++;
	if (mapcase == 'C')
		vr->col++;
	if (mapcase == 'P')
		vr->pos++;
	return (1);
}

int	ft_check_line(char **map, int y)
{
	int	i;

	i = 0;
	if (y == 0)
	{
		while (map[y][i] == '1')
			i++;
		if (map[y][i] == '\n' && map[y][i + 1] == '\0')
			return (i);
	}
	else
	{
		while (map[y][i] == '1')
			i++;
		if (map[y][i] == '\0')
			return (i);
	}
	return (0);
}

void	ft_check_map(char **map, int y, char *path)
{
	t_vars	vr;

	vr.y = 1;
	vr.i = ft_check_line(map, 0);
	vr.exi = 0;
	vr.col = 0;
	vr.pos = 0;
	while (vr.y < y && vr.y != 0)
	{
		vr.x = 0;
		while (map[vr.y][0] == '1' && map[vr.y][vr.i - 1] == '1' && map[vr.y]
		[vr.x] == '0' || map[vr.y][vr.x] == '1' || map[vr.y][vr.x] == 'C' ||
		map[vr.y][vr.x] == 'E' || map[vr.y][vr.x] == 'P' || map[vr.y][vr.x]
		== '2')
			vr.x += ft_check_contains(&vr, map[vr.y][vr.x]);
		if (vr.x != vr.i && map[vr.y][vr.x - 1] != 10 && map[vr.y][vr.x] != 0)
			vr.y = 0;
		else
			vr.y++;
	}
	vr.i = ft_check_line(map, y);
	if (vr.i == vr.x && y == vr.y && vr.exi && vr.col && vr.pos == 1)
		ft_init_game(vr.x, vr.y, map);
	else
		printf("Error found in map body. Insert a valid map.\n");
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
