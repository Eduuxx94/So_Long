/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 20:02:07 by ede-alme          #+#    #+#             */
/*   Updated: 2022/05/18 21:20:30 by ede-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_exits(t_world *world, int x, int y)
{
	mlx_put_image_to_window(world->mlx_ptr, world->win_ptr, world
		->obj.img[25], x * 32, (y + 1) * 32);
	if (world->time >= 0 && world->time < 10)
		mlx_put_image_to_window(world->mlx_ptr, world->win_ptr, world
			->obj.img[12], x * 32, (y + 1) * 32);
	if (world->time >= 10 && world->time < 20)
		mlx_put_image_to_window(world->mlx_ptr, world->win_ptr, world
			->obj.img[13], x * 32, (y + 1) * 32);
	if (world->time >= 20 && world->time < 30)
		mlx_put_image_to_window(world->mlx_ptr, world->win_ptr, world
			->obj.img[14], x * 32, (y + 1) * 32);
	if (world->time >= 30 && world->time < 40)
		mlx_put_image_to_window(world->mlx_ptr, world->win_ptr, world
			->obj.img[15], x * 32, (y + 1) * 32);
	if (world->time >= 40 && world->time < 50)
		mlx_put_image_to_window(world->mlx_ptr, world->win_ptr, world
			->obj.img[16], x * 32, (y + 1) * 32);
	if (world->time >= 50 && world->time <= 60)
		mlx_put_image_to_window(world->mlx_ptr, world->win_ptr, world
			->obj.img[17], x * 32, (y + 1) * 32);
}

void	ft_put_collects(t_world *world, int x, int y)
{
	mlx_put_image_to_window(world->mlx_ptr, world->win_ptr, world
		->obj.img[25], x * 32, (y + 1) * 32);
	if (world->time >= 0 && world->time < 10)
		mlx_put_image_to_window(world->mlx_ptr, world->win_ptr, world
			->obj.img[6], x * 32, (y + 1) * 32);
	if (world->time >= 10 && world->time < 20)
		mlx_put_image_to_window(world->mlx_ptr, world->win_ptr, world
			->obj.img[7], x * 32, (y + 1) * 32);
	if (world->time >= 20 && world->time < 30)
		mlx_put_image_to_window(world->mlx_ptr, world->win_ptr, world
			->obj.img[8], x * 32, (y + 1) * 32);
	if (world->time >= 30 && world->time < 40)
		mlx_put_image_to_window(world->mlx_ptr, world->win_ptr, world
			->obj.img[9], x * 32, (y + 1) * 32);
	if (world->time >= 40 && world->time < 50)
		mlx_put_image_to_window(world->mlx_ptr, world->win_ptr, world
			->obj.img[10], x * 32, (y + 1) * 32);
	if (world->time >= 50 && world->time <= 60)
		mlx_put_image_to_window(world->mlx_ptr, world->win_ptr, world
			->obj.img[11], x * 32, (y + 1) * 32);
}

void	ft_put_enemy(t_world *world, int x, int y)
{
	mlx_put_image_to_window(world->mlx_ptr, world->win_ptr, world
		->obj.img[25], x * 32, (y + 1) * 32);
	if (world->time >= 0 && world->time < 10)
		mlx_put_image_to_window(world->mlx_ptr, world->win_ptr, world
			->obj.img[0], x * 32, (y + 1) * 32);
	if (world->time >= 10 && world->time < 20)
		mlx_put_image_to_window(world->mlx_ptr, world->win_ptr, world
			->obj.img[1], x * 32, (y + 1) * 32);
	if (world->time >= 20 && world->time < 30)
		mlx_put_image_to_window(world->mlx_ptr, world->win_ptr, world
			->obj.img[2], x * 32, (y + 1) * 32);
	if (world->time >= 30 && world->time < 40)
		mlx_put_image_to_window(world->mlx_ptr, world->win_ptr, world
			->obj.img[3], x * 32, (y + 1) * 32);
	if (world->time >= 40 && world->time < 50)
		mlx_put_image_to_window(world->mlx_ptr, world->win_ptr, world
			->obj.img[4], x * 32, (y + 1) * 32);
	if (world->time >= 50 && world->time <= 60)
		mlx_put_image_to_window(world->mlx_ptr, world->win_ptr, world
			->obj.img[5], x * 32, (y + 1) * 32);
}

void	ft_putplayer(t_world *world, int x, int y)
{
	if (world->time >= 0 && world->time < 10)
		mlx_put_image_to_window(world->mlx_ptr, world->win_ptr, world
			->obj.img[18], x * 32, (y + 1) * 32);
	if (world->time >= 10 && world->time < 20)
		mlx_put_image_to_window(world->mlx_ptr, world->win_ptr, world
			->obj.img[19], x * 32, (y + 1) * 32);
	if (world->time >= 20 && world->time < 30)
		mlx_put_image_to_window(world->mlx_ptr, world->win_ptr, world
			->obj.img[20], x * 32, (y + 1) * 32);
	if (world->time >= 30 && world->time < 40)
		mlx_put_image_to_window(world->mlx_ptr, world->win_ptr, world
			->obj.img[21], x * 32, (y + 1) * 32);
	if (world->time >= 40 && world->time < 50)
		mlx_put_image_to_window(world->mlx_ptr, world->win_ptr, world
			->obj.img[22], x * 32, (y + 1) * 32);
	if (world->time >= 50 && world->time <= 60)
		mlx_put_image_to_window(world->mlx_ptr, world->win_ptr, world
			->obj.img[23], x * 32, (y + 1) * 32);
		world->vr.player_x = x;
		world->vr.player_y = y;
}

int	ft_next_frame(t_world *world)
{
	char	*collects;
	char	*steps;
	int		color;

	color = 0x00FF00;
	if (world->time++ && world->max_steps < world->vr.temp / 5)
		color = 0xFFFF00;
	if (world->max_steps < world->vr.temp / 8 && world->time < 35)
		color = 0xFF0000;
	else if (world->max_steps < world->vr.temp / 8)
		color = 0;
	world->vr.fd = 1;
	collects = ft_itoa(world->collec);
	steps = ft_itoa(world->steps);
	mlx_clear_window(world->mlx_ptr, world->win_ptr);
	ft_print_map(world, world->wind_x, world->wind_y);
	mlx_string_put(world->mlx_ptr, world->win_ptr, 9, 10, 0xFFFF00, "Collect:");
	mlx_string_put(world->mlx_ptr, world->win_ptr, 90, 10, 0xFFFF00, collects);
	mlx_string_put(world->mlx_ptr, world->win_ptr, 150, 10, color, "Steps:");
	mlx_string_put(world->mlx_ptr, world->win_ptr, 210, 10, color, steps);
	free(collects);
	free(steps);
	if (world->time >= 60)
		world->time = 0;
	return (1);
}
