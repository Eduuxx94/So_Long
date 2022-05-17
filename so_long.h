/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 00:15:13 by ede-alme          #+#    #+#             */
/*   Updated: 2022/05/17 23:04:15 by ede-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

//All variables from game inside t_vars:
typedef struct s_vars {
	int		fd;
	int		e;
	int		c;
	int		p;
	int		x;
	int		y;
	int		player_x;
	int		player_y;
	int		i;
	char	*line;
}			t_vars;

//All variables from the objects inside t_object
typedef struct s_object {
	void	*img[26];
	int		img_width;
	int		img_height;
}				t_object;

typedef struct s_world {
	void		*mlx_ptr;
	void		*win_ptr;
	t_vars		vr;
	t_object	obj;
	int			time;
	char		**map;
	int			wind_x;
	int			wind_y;
	int			collec;
	int			steps;
	int			max_steps;
	int			emov;
}				t_world;

//Here is the main of the game...
int		ft_check_line(t_world *world, int y, char mapcase, t_vars vr);
void	ft_check_map(t_world *world, int y);
int		ft_open_argv(int fd, const char *argv, t_world *world);
void	ft_alloc_map(int fd, t_world *world, int index);
int		main(int argc, char **argv);

//Utils for the gamedev
void	ft_count_p(t_world *world, t_vars vr);
char	*ft_itoa(int n);

//All Get_next_line functions and utils bellow...
void	ft_realoc2(char *line, char *buff, int i_line, int *buff_size);
void	*ft_realoc(char *line, char *buff, int line_size, int *buff_size);
int		get_size_linha(char *buff);
char	*get_next_line(int fd);

//All game window processator and prints below...
void	ft_init_game(int x, int y, t_world *world);
void	ft_load_images_1(t_world *world);
void	ft_load_images_2(t_world *world);
void	ft_load_images_3(t_world *world);
void	ft_print_map(t_world *world, int x, int y);

//All animation func. and players moves func. bellow...
int		ft_next_frame(t_world *world);
void	ft_putplayer(t_world *world, int x, int y);
void	ft_put_enemy(t_world *world, int x, int y);
void	ft_put_collects(t_world *world, int x, int y);
void	ft_put_exits(t_world *world, int x, int y);

//Keyboard func...
int		ft_close(t_world *world);
int		keyboard_in(int keycode, t_world *world);

#endif
