/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 00:15:13 by ede-alme          #+#    #+#             */
/*   Updated: 2022/04/24 21:34:39 by ede-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_vars {
	int			exi;
	int			col;
	int			pos;
	int			x;
	int			y;
	int			i;
	char		*map[200];
}			t_vars;

typedef struct s_object {
	void	*img;
	void	*anim[3];
	int		img_width;
	int		img_height;
}				t_object;

typedef struct s_world {
	void		*mlx_ptr;
	void		*win_ptr;
	t_vars		var;
}				t_world;

//Here is the main of the game...
int		ft_check_contains(t_vars *vr, char mapcase);
int		ft_check_line(char **map, int y);
void	ft_check_map(char **map, int y, char *path);
void	ft_readmap(int fd, char *argv);
int		main(int argc, char **argv);

//All Get_next_line functions and utils bellow...
void	ft_realoc2(char *line, char *buff, int i_line, int *buff_size);
void	*ft_realoc(char *line, char *buff, int line_size, int *buff_size);
int		get_size(char *buff);
int		get_size_linha(char *buff);
char	*get_next_line(int fd);

//All game processator below...
void	ft_init_game(int x, int y, char **map);

#endif