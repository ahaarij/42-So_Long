/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spriteanimate_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:39:53 by ahaarij           #+#    #+#             */
/*   Updated: 2024/02/17 18:14:57 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	check(t_game ***game, int x, int y)
{
	if ((**game)->map[y][x] == '0' && (**game)->map[y][x + 1] == '0'
		&& (**game)->map[y][x + 2] == '0')
	{
		(**game)->e_vars.sign = 0;
		(**game)->e_vars.x_e = x;
		(**game)->e_vars.y_e = y;
		return (1);
	}
	return (0);
}

int get_za_enemy_position(t_game **game)
{
    int y;
    int x;
    int height;

	y = 0;
	height = get_height((*game)->map);
	if ((*game)->e_vars.sign)
	{
		while (y != height)
		{
			x = 0;
			while ((*game)->map[y][x] != '\0')
			{
				if (check(&game, x, y))
					return (1);
				x++;
			}
			y++;
		}
		return (0);
	}
	return (1);
}

void	open_exit(t_game **game)
{
	int			y;
	int			x;
	int			height;
	int			img_w;
	int			img_h;

	y = 0;
	height = get_height((*game)->map);
	while (y != height)
	{
		x = 0;
		while ((*game)->map[y][x] != '\0')
		{
			if ((*game)->map[y][x] == 'E')
			{
				(*game)->img = mlx_xpm_file_to_image(
						(*game)->mlx, "./assets/o_exit.xpm", &img_w, &img_h);
				mlx_put_image_to_window(
					(*game)->mlx, (*game)->win, (*game)->img, x * 32, y * 32);
			}
			x++;
		}
		y++;
	}
}
