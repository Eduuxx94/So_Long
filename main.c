/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 20:49:43 by ede-alme          #+#    #+#             */
/*   Updated: 2022/05/07 18:50:05 by ede-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_contains(t_vars *vr, char mapcase, char *argv, int index)
{
	index = 0;
	if (argv)
	{
		while (argv[index] != '\0')
			index++;
		if (index > 4 && argv[index - 4] == '.' && argv[index - 3] == 'b'
			&& argv[index - 2] == 'e' && argv[index - 1] == 'r')
			return (1);
	}
	else
	{
		if (mapcase == 'E')
			vr->exi++;
		if (mapcase == 'C')
			vr->col++;
		if (mapcase == 'P')
			vr->pos++;
		return (1);
	}
	return (0);
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

void	ft_check_map(char **map, int y)
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
		while (((map[vr.y][0] == '1' && map[vr.y][vr.i - 1] == '1') && map[vr.y]
		[vr.x] == '0') || map[vr.y][vr.x] == '1' || map[vr.y][vr.x] == 'C' ||
		map[vr.y][vr.x] == 'E' || map[vr.y][vr.x] == 'P' || map[vr.y][vr.x]
		== '2')
			vr.x += ft_check_contains(&vr, map[vr.y][vr.x], NULL, 0);
		if (vr.x != vr.i && map[vr.y][vr.x - 1] != 10 && map[vr.y][vr.x] != 0)
			vr.y = 0;
		else
			vr.y++;
	}
	vr.i = ft_check_line(map, y);
	if (vr.i == vr.x && y == vr.y && vr.exi && vr.col && vr.pos == 1)
		ft_init_game(vr.x + 1, vr.y + 1, map);
	else
		printf("Error found in map body. Insert a valid map.\n");
}

/*ft_readmap is the fuction responsable for read map, put in memory, check all
rules and init the graphical minilibx, after all graphical code free all map.*/
void	ft_readmap(int fd, char *map, int lines)
{
	t_vars	var;

	var.y = 0;
	var.map = malloc(sizeof(char *) * (lines + 1));
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
				if (var.y <= 2)
					printf("Your map %s not have the requested height.\n", map);
				else
					ft_check_map(var.map, var.y - 1);
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
	t_vars		var;

	var.y = 0;
	if (argc == 2)
	{
		if (ft_check_contains(&var, 0, argv[1], 0))
		{
			var.fd = open(argv[1], O_RDONLY);
			var.line = get_next_line(var.fd);
			while ((var.y == 0 || var.line != NULL) && ++var.y)
			{
				free(var.line);
				var.line = get_next_line(var.fd);
			}
			close (var.fd);
			var.fd = open(argv[1], O_RDONLY);
			ft_readmap(var.fd, argv[1], var.y);
			close (var.fd);
		}
		else
			printf("Your map.ber does not match the requested name\n");
	}
	else
		printf("Insert 'map_name.ber' as argument\n");
	return (0);
}
