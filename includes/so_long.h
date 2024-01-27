/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 09:45:14 by ahaarij           #+#    #+#             */
/*   Updated: 2024/01/27 16:25:47 by ahaarij          ###   ########.fr       */
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
}				t_img;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
    int     height;
    int     width;
    t_img   player;
    int     x;
    int     y;
}				t_vars;

# define SPRITE_SIZE 512
# define OFFSET_S	1
# define NUM_FRAMES 8

#endif