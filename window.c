/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 21:20:03 by ede-alme          #+#    #+#             */
/*   Updated: 2022/04/24 21:43:46 by ede-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_game(int x, int y, char **map)
{
	t_world	world;

	printf("x = %i    y = %i\n", x, y);
	world.mlx_ptr = mlx_init();
	world.win_ptr = mlx_new_window(world.mlx_ptr, (x + 1) * 15, (y + 2) * 15,
			"Collect all them!");
	mlx_loop(world.mlx_ptr);
}
