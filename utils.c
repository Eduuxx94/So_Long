/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:27:07 by ede-alme          #+#    #+#             */
/*   Updated: 2022/05/17 23:04:07 by ede-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_itoa(int n)
{
	long	number;
	char	*str;
	int		i;

	i = 0;
	number = n;
	str = (char *)malloc(sizeof(char) * (1 + 1));
	str[0] = '0';
	str[1] = '\0';
	if (n == 0 || !n)
		return (str);
	free (str);
	while ((n) && ++i)
		n = n / 10;
	if (number < 0 && ++i)
		number = number * -1;
	str = (char *)malloc(sizeof(char) * (i + 1));
	str[0] = '-';
	str[i--] = '\0';
	while (number > 0)
	{
		str[i--] = 48 + (number % 10);
		number = number / 10;
	}
	return (str);
}

void	ft_count_p(t_world *world, t_vars vr)
{
	if (world->vr.p > 0)
		world->map[world->vr.player_y][world->vr.player_x] = '0';
	world->vr.p++;
	world->vr.player_x = vr.x;
	world->vr.player_y = vr.y;
}
