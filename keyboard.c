/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:43:07 by ede-alme          #+#    #+#             */
/*   Updated: 2022/05/17 22:49:07 by ede-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_world *world)
{
	mlx_clear_window(world->mlx_ptr, world->win_ptr);
	mlx_destroy_window(world->mlx_ptr, world->win_ptr);
	while (world->vr.y >= 0)
		free (world->map[world->vr.y--]);
	free (world->map);
	world->vr.y = 25;
	while (world->vr.y >= 0)
		mlx_destroy_image(world->mlx_ptr, world->obj.img[world->vr.y--]);
	printf("Bye\n");
	exit (0);
}

void	ft_move_p(t_world *world, int x, int y)
{
	if ((world->map[y][x] == 'C' || world->map[y][x] == '0') && ++world->steps)
	{
		world->map[world->vr.player_y][world->vr.player_x] = '0';
		--world->max_steps;
		if (world->map[y][x] == 'C' && ++world->collec && --world->vr.c &&
			++world->max_steps)
			printf("Nice! You catch a collectable! --> + 1 Step :D\n");
		world->map[y][x] = 'P';
		printf("Steps:-> %i / %i remaining.\n", world->steps, world->max_steps);
	}
	if (world->map[y][x] == '2' || world->max_steps < 1)
	{
		if (world->map[y][x] == '2')
			printf("You toutch the enemy! You are a loser...\n");
		else
			printf("You did all steps... You lose... --> :(\n");
		ft_close(world);
	}
	if (world->map[y][x] == 'E' && world->vr.c > 0)
		printf("Catch all collects first. --> %i remaining! :(\n", world->vr.c);
	else if (world->map[y][x] == 'E' && world->vr.c == 0)
	{
		printf("You catch all Collects and find an escape, Nice.... --> :D\n");
		ft_close(world);
	}
}

int	keyboard_in(int keycode, t_world *world)
{
	if (keycode == 53)
		ft_close(world);
	if (keycode == 2)
		ft_move_p(world, world->vr.player_x + 1, world->vr.player_y);
	if (keycode == 0)
		ft_move_p(world, world->vr.player_x - 1, world->vr.player_y);
	if (keycode == 13)
		ft_move_p(world, world->vr.player_x, world->vr.player_y - 1);
	if (keycode == 1)
		ft_move_p(world, world->vr.player_x, world->vr.player_y + 1);
	return (0);
}
