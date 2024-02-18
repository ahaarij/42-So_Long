/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 09:45:14 by ahaarij           #+#    #+#             */
/*   Updated: 2024/02/17 16:51:41 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// External Libraries

# include "../mlx-macos/mlx.h"
# include "../libft/includes/libft.h"
# include "sprites.h"
# include <stdbool.h>

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
	int		width;
	int		height;
	char	*line;
	char	*file;
	char	*filename;
	char	**copy;
	int		c;
	int		c_check;
	int		e;
	int		e_check;
	int		p;
	int		x;
	int		y;
	int		map_x;
	int		map_y;
}				t_map;

# define SPRITE_SIZE 512
# define OFFSET_S	1
# define NUM_FRAMES 8

void			init_game(t_game *game);
void			move_down(t_game **game);
void			check_file_is_valid(char *file_line);
void			ft_msgerror(void);
int				get_height(char **map);
void			get_map(t_map *map, t_game *game);
void			checkmapvalid(t_game *game, t_map *map);
void			ft_error(t_game ***game, char *error);
void    		put_image(t_game ***game, int x, int y, char *path);
void			put_image_to_map(char p, int x1, int y1, t_game **game);
void			checkelement(t_game **game, t_map *map);
void			check_walls(t_game **game);
void    		to_right(t_game **game);
void    		to_left(t_game **game);
void			to_up(t_game **v);
void			to_down(t_game **v);
void			put_text(t_game ***game);
void    		ft_exit(t_game ***game);
void			move_on_paths(int x, int y, t_map *map);
void			check_valid_path(t_game *game, t_map map);
char			*ft_strjoinfree(char *s1, char *s2);
void			scanplayer(t_map *map, t_game game);
void			ft_exit_free(t_map *map, t_game *game);
int				spriteanimate(t_game *game);
int				get_za_enemy_position(t_game **game);
void			open_exit(t_game **game);

#endif