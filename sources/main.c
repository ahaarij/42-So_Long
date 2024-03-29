/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 09:06:19 by ahaarij           #+#    #+#             */
/*   Updated: 2024/02/18 11:30:17 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	render_map(t_game *game)
{
	int	y1;
	int	y_map;
	int	backup_w;
	int	x1;
	int	x_map;

	y1 = 0;
	y_map = 0;
	backup_w = game->win_w;
	while (game->win_h > 0)
	{
		x1 = 0;
		x_map = 0;
		while (game->win_w > 0)
		{
			put_image_to_map(game->map[y_map][x_map], x1, y1, &game);
			x_map++;
			x1 += 32;
			game->win_w--;
		}
		game->win_w = backup_w;
		y_map++;
		y1 += 32;
		game->win_h--;
	}
}

int	key_press(int keycode, t_game *game)
{
	int	x;

	if (keycode == 2 || keycode == 124)
		to_right(&game);
	else if (keycode == 0 || keycode == 123)
		to_left(&game);
	else if (keycode == 13 || keycode == 126)
		to_up(&game);
	else if (keycode == 1 || keycode == 125)
		to_down(&game);
	if (keycode == 53)
	{
		x = 0;
		while (game->map[x])
		{
			free(game->map[x]);
			x++;
		}
		free(game->map);
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	return (0);
}

int	closegame(t_game *game)
{
	int	x;

	x = 0;
	while (game->map[x])
	{
		free(game->map[x]);
		x++;
	}
	free(game->map);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}

static void	init_vars(t_game *game)
{
	game->collect = 0;
	game->movement = 0;
	game->win_w = ft_strlen(game->map[0]);
	game->win_h = get_height(game->map);
	game->e_vars.x = 0;
	game->e_vars.sleep = 5;
	game->e_vars.sleep_for_move = 60;
	game->e_vars.path_to_move = 0;
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_map	map;

	if (argc <= 1)
	{
		perror("\033[1;31m🛑ERROR \033[0m");
		exit(0);
	}
	map.filename = argv[1];
	check_file_is_valid(argv[1]);
	get_map(&map, &game);
	if (game.map != NULL)
	{
		checkmapvalid(&game, &map);
		init_vars(&game);
		game.mlx = mlx_init();
		game.win = mlx_new_window(game.mlx, game.win_w * 32,
				game.win_h * 32, "So-Long");
		render_map(&game);
		mlx_hook(game.win, 2, 1L << 0, key_press, &game);
		mlx_hook(game.win, 17, 1L << 2, closegame, &game);
		mlx_loop_hook(game.mlx, spriteanimate, &game);
		mlx_loop(game.mlx);
	}
}
