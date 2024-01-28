/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 09:45:14 by ahaarij           #+#    #+#             */
/*   Updated: 2024/01/28 14:38:30 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// External Libraries

# include "../mlx-macos/mlx.h"
# include "../libft/includes/libft.h"
# include "sprites.h"

// Define Sizes

enum e_direction
{
	down,
	left,
	right,
	up,
};

typedef struct s_img {
	void	*ptr;
	int		mem;
	int		x;
    int		y;
}				t_img;

typedef struct s_draw {
	char	**map;
	int		height;
	int		width;
}				t_draw;


typedef struct	s_game {
	void	*mlx;
	void	*win;
	t_draw	plot;
    t_img   player;
	t_img	back;
}				t_game;

# define SPRITE_SIZE 512
# define OFFSET_S	1
# define NUM_FRAMES 8

void	init_window(t_game *game);
void	init_images(t_game *game);
t_img	xpmtemp(void *mlx, char *path);
void	init_game(t_game *game);

#endif