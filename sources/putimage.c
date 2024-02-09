/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putimage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:07:48 by ahaarij           #+#    #+#             */
/*   Updated: 2024/02/09 13:06:11 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    put_image(t_game ***game, int x, int y, char *path)
{
    int img_w;
    int img_h;

    (**game)->img = mlx_xpm_file_to_image((**game)->mlx, path, &img_w, &img_h);
    mlx_put_image_to_window((**game)->mlx, (**game)->win, (**game)->img, x, y);
}

void	put_image_to_map(char p, int x1, int y1, t_game **game)
{
	if (p == '1')
		put_image(&game, x1, y1, "./assets/cobble.xpm");
	else if (p == 'C')
	{
		put_image(&game, x1, y1, "./assets/floor.xpm");
		put_image(&game, x1, y1, "./assets/coin.xpm");
		(*game)->collect++;
	}
	else if (p == 'E')
	{
		put_image(&game, x1, y1, "./assets/floor.xpm");
		put_image(&game, x1, y1, "./assets/exit.xpm");
	}
	else if (p == 'P')
	{
		(*game)->p_y = y1;
		(*game)->p_x = x1;
		put_image(&game, x1, y1, "./assets/floor.xpm");
		put_image(&game, x1, y1, "./assets/slimedown.xpm");
	}
	else
		put_image(&game, x1, y1, "./assets/floor.xpm");
}
