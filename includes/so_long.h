x/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 09:45:14 by ahaarij           #+#    #+#             */
/*   Updated: 2024/02/03 12:43:41 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// External Libraries

# include "../mlx-macos/mlx.h"
# include "../libft/includes/libft.h"
# include "sprites.h"

typedef	struct	s_enemy {
	int		x_e;
	int		y_e;
	int		sign;
	int		x;
	int		path_to_move;
	int		sleep;
	int		sleep_for_move;
	char	*imgs[5];
}				t_enemy;

typedef struct	s_game {
	void	*mlx;
	void	*win;
	void	*img;
	char	**map;
	int		p_x;
	int		p_y;
	int		win_h;
	int		win_w;
	int		collect;
	int		movement;
	t_enemy	e_vars;
}				t_game;

typedef struct	s_map {
	int		c;
	int		e;
	int		p;
	int		x;
	int		y;
}				t_map;

# define SPRITE_SIZE 512
# define OFFSET_S	1
# define NUM_FRAMES 8

void		init_game(t_game *game);
void		move_down(t_game **game);
int			needle(char *str, char *to_find);
void		check_file_is_valid(char *file_line);
void		ft_msgerror(void);
int			get_height(char **map);
char		**get_map(char *fmap);
void		checkmapvalid(t_game *game);
void		check_walls(t_game **game);
int			check_line(char *line);
void		check_is_rectangle(t_game **game);
void		ft_error(t_game ***game, char *error);

#endif