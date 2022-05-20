/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_prints.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 21:20:03 by ede-alme          #+#    #+#             */
/*   Updated: 2022/05/18 20:35:06 by ede-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Falta criar uma funcao de animacao consoante o time que passa.
//Falta criar uma funcao do player e que mova a imagem consoante o possivel.
//Falta criar funcao feche o jogo e que tambem mostre os passos dados e colects.

void	ft_print_map(t_world *world, int x, int y)
{
	y = 0;
	while (y < world->vr.y)
	{
		x = 0;
		while (x < world->vr.x)
		{
			if (world->map[y][x] == '1')
				mlx_put_image_to_window(world->mlx_ptr, world->win_ptr, world
					->obj.img[24], x * 32, (y + 1) * 32);
			if (world->map[y][x] == 'P')
				ft_putplayer(world, x, y);
			if (world->map[y][x] == '2')
				ft_put_enemy(world, x, y);
			if (world->map[y][x] == 'C')
				ft_put_collects(world, x, y);
			if (world->map[y][x] == 'E')
				ft_put_exits(world, x, y);
			x++;
		}
		y++;
	}
}

void	ft_load_images_3(t_world *world)
{
	world->obj.img[24] = mlx_xpm_file_to_image(world->mlx_ptr,
			"./Tiles/wall.xpm", &world->obj.img_width, &world->obj.img_height);
	world->obj.img[25] = mlx_xpm_file_to_image(world->mlx_ptr,
			"./Tiles/back.xpm", &world->obj.img_width, &world->obj.img_height);
}

void	ft_load_images_2(t_world *world)
{
	world->obj.img[12] = mlx_xpm_file_to_image(world->mlx_ptr,
			"./Tiles/Exit0.xpm", &world->obj.img_width, &world->obj.img_height);
	world->obj.img[13] = mlx_xpm_file_to_image(world->mlx_ptr,
			"./Tiles/Exit1.xpm", &world->obj.img_width, &world->obj.img_height);
	world->obj.img[14] = mlx_xpm_file_to_image(world->mlx_ptr,
			"./Tiles/Exit2.xpm", &world->obj.img_width, &world->obj.img_height);
	world->obj.img[15] = mlx_xpm_file_to_image(world->mlx_ptr,
			"./Tiles/Exit3.xpm", &world->obj.img_width, &world->obj.img_height);
	world->obj.img[16] = mlx_xpm_file_to_image(world->mlx_ptr,
			"./Tiles/Exit4.xpm", &world->obj.img_width, &world->obj.img_height);
	world->obj.img[17] = mlx_xpm_file_to_image(world->mlx_ptr,
			"./Tiles/Exit5.xpm", &world->obj.img_width, &world->obj.img_height);
	world->obj.img[18] = mlx_xpm_file_to_image(world->mlx_ptr,
			"./Tiles/Play0.xpm", &world->obj.img_width, &world->obj.img_height);
	world->obj.img[19] = mlx_xpm_file_to_image(world->mlx_ptr,
			"./Tiles/Play1.xpm", &world->obj.img_width, &world->obj.img_height);
	world->obj.img[20] = mlx_xpm_file_to_image(world->mlx_ptr,
			"./Tiles/Play2.xpm", &world->obj.img_width, &world->obj.img_height);
	world->obj.img[21] = mlx_xpm_file_to_image(world->mlx_ptr,
			"./Tiles/Play3.xpm", &world->obj.img_width, &world->obj.img_height);
	world->obj.img[22] = mlx_xpm_file_to_image(world->mlx_ptr,
			"./Tiles/Play4.xpm", &world->obj.img_width, &world->obj.img_height);
	world->obj.img[23] = mlx_xpm_file_to_image(world->mlx_ptr,
			"./Tiles/Play5.xpm", &world->obj.img_width, &world->obj.img_height);
	ft_load_images_3(world);
}

void	ft_load_images_1(t_world *world)
{
	world->obj.img[0] = mlx_xpm_file_to_image(world->mlx_ptr,
			"./Tiles/Bat0.xpm", &world->obj.img_width, &world->obj.img_height);
	world->obj.img[1] = mlx_xpm_file_to_image(world->mlx_ptr,
			"./Tiles/Bat1.xpm", &world->obj.img_width, &world->obj.img_height);
	world->obj.img[2] = mlx_xpm_file_to_image(world->mlx_ptr,
			"./Tiles/Bat2.xpm", &world->obj.img_width, &world->obj.img_height);
	world->obj.img[3] = mlx_xpm_file_to_image(world->mlx_ptr,
			"./Tiles/Bat3.xpm", &world->obj.img_width, &world->obj.img_height);
	world->obj.img[4] = mlx_xpm_file_to_image(world->mlx_ptr,
			"./Tiles/Bat4.xpm", &world->obj.img_width, &world->obj.img_height);
	world->obj.img[5] = mlx_xpm_file_to_image(world->mlx_ptr,
			"./Tiles/Bat5.xpm", &world->obj.img_width, &world->obj.img_height);
	world->obj.img[6] = mlx_xpm_file_to_image(world->mlx_ptr,
			"./Tiles/Coin0.xpm", &world->obj.img_width, &world->obj.img_height);
	world->obj.img[7] = mlx_xpm_file_to_image(world->mlx_ptr,
			"./Tiles/Coin1.xpm", &world->obj.img_width, &world->obj.img_height);
	world->obj.img[8] = mlx_xpm_file_to_image(world->mlx_ptr,
			"./Tiles/Coin2.xpm", &world->obj.img_width, &world->obj.img_height);
	world->obj.img[9] = mlx_xpm_file_to_image(world->mlx_ptr,
			"./Tiles/Coin3.xpm", &world->obj.img_width, &world->obj.img_height);
	world->obj.img[10] = mlx_xpm_file_to_image(world->mlx_ptr,
			"./Tiles/Coin4.xpm", &world->obj.img_width, &world->obj.img_height);
	world->obj.img[11] = mlx_xpm_file_to_image(world->mlx_ptr,
			"./Tiles/Coin5.xpm", &world->obj.img_width, &world->obj.img_height);
	ft_load_images_2(world);
}

void	ft_init_game(int x, int y, t_world *world)
{
	world->emov = 0;
	world->wind_y = y;
	world->wind_x = x;
	world->vr.y = y;
	world->vr.x = x;
	world->time = 0;
	world->steps = 0;
	world->collec = 0;
	world->max_steps = (y * x) / 3;
	world->vr.temp = y * x;
	world->mlx_ptr = mlx_init();
	world->win_ptr = mlx_new_window(world->mlx_ptr, (x - 1) * 32, (y + 1)
			* 32, "My Game!");
	ft_load_images_1(world);
	mlx_hook(world->win_ptr, 17, 0, ft_close, world);
	mlx_key_hook(world->win_ptr, keyboard_in, world);
	mlx_loop_hook(world->mlx_ptr, ft_next_frame, world);
	mlx_string_put(world->mlx_ptr, world->win_ptr, 9, 10, 0xFFFF00, "Collets:");
	mlx_loop(world->mlx_ptr);
}
