/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 20:49:43 by ede-alme          #+#    #+#             */
/*   Updated: 2022/05/20 21:09:15 by ede-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_line(t_world *world, int y, char mapcase, t_vars vr)
{
	world->vr.i = 0;
	if (mapcase)
	{
		if (mapcase == 'E')
			world->vr.e++;
		if (mapcase == 'C')
			world->vr.c++;
		if (mapcase == 'P')
			ft_count_p(world, vr);
	}
	if (y == 0 && !mapcase)
	{
		while (world->map[y][world->vr.i] == '1')
			world->vr.i++;
		if (world->map[y][world->vr.i] == 10 && !world->map[y][world->vr.i + 1])
			return (world->vr.i);
	}
	if (y > 0)
	{
		while (world->map[y][world->vr.i] == '1')
			world->vr.i++;
		if (world->map[y][world->vr.i] == '\0')
			return (world->vr.i);
	}
	return (1);
}

void	ft_check_map(t_world *world, int y)
{
	t_vars	vr;

	vr.y = 1;
	vr.i = ft_check_line(world, 0, 0, vr);
	world->vr.e = 0;
	world->vr.c = 0;
	world->vr.p = 0;
	while (vr.y < y && vr.y != 0)
	{
		vr.x = 0;
		while (((world->map[vr.y][vr.i] == 10 && !world->map[vr.y][vr.i + 1]
			&& world->map[vr.y][0] == '1' && world->map[vr.y][vr.i - 1] == '1'
		) && world->map[vr.y][vr.x] == '0') || world->map[vr.y][vr.x] == '1'
		|| world->map[vr.y][vr.x] == 'C' || world->map[vr.y][vr.x] == 'E' ||
		world->map[vr.y][vr.x] == 'P' || world->map[vr.y][vr.x] == '2')
			vr.x += ft_check_line(world, 0, world->map[vr.y][vr.x], vr);
		if (vr.y++ && vr.x != vr.i && world->map[vr.y][vr.x - 1] != 10 && world
		->map[vr.y][vr.x] != 0)
			vr.y = 0;
	}
	vr.i = ft_check_line(world, y, 0, vr);
	if (vr.i == vr.x && y == vr.y && world->vr.e && world->vr.c && world->vr.p)
		ft_init_game(vr.x + 1, vr.y + 1, world);
	ft_printf("Error found in map body. Make sure all rules are respected.\n");
}

void	ft_alloc_map(int fd, t_world *world, int index)
{
	char	*line;

	line = get_next_line(fd);
	if (line && ++world->vr.y)
		ft_alloc_map(fd, world, (index + 1));
	else
		world->map = malloc((sizeof(char **) + 2) * index);
	world->map[index] = line;
}

int	ft_open_argv(int fd, const char *argv, t_world *world)
{
	world->vr.i = 0;
	world->vr.y = 1;
	while (argv[world->vr.i] != '\0')
			world->vr.i++;
	if (world->vr.i > 4 && argv[world->vr.i - 4] == '.' && argv[world->vr.i - 3]
		== 'b' && argv[world->vr.i - 2] == 'e' && argv[world->vr.i - 1] == 'r')
		ft_alloc_map(fd, world, 0);
	else
		return (0);
	return (world->vr.i);
}

int	main(int argc, char **argv)
{
	t_world		world;

	if (argc == 2)
	{
		world.vr.fd = open(argv[1], O_RDONLY);
		if (world.vr.fd < 0)
			ft_printf("File not found...\n");
		else
		{
			world.vr.i = ft_open_argv(world.vr.fd, argv[1], &world);
			close (world.vr.fd);
			if (world.vr.i == 0)
				ft_printf("File type does't match: -> '*.ber extension!' \n");
			else if (world.vr.y < 3)
				ft_printf("Your map does not have the requested height -> |\n");
			else
				ft_check_map(&world, world.vr.y - 2);
		}
		close(world.vr.fd);
	}
	else
		ft_printf("Insert a file path as argument!\n");
	return (0);
}
