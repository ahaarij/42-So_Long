/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 09:43:59 by ahaarij           #+#    #+#             */
/*   Updated: 2024/01/28 15:47:23 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_window(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 1280, 720, "Test");
}

void	init_images(t_game *game)
{
	game->back = xpmtemp(game->mlx, BACKGROUND);
	game->player = xpmtemp(game->mlx, SLIME);

	mlx_put_image_to_window(game->mlx, game->win, game->back.ptr, 0, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->player.ptr, 32, 32);
}

t_img	xpmtemp(void *mlx, char *path)
{
	t_img img;
	img.ptr = mlx_xpm_file_to_image(mlx, path, &img.x, &img.y);
	return (img);
}