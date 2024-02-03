#include "../includes/so_long.h"
#include <stdio.h>
#include <math.h>


int	key_press(int keycode, t_game *game)
{
	if (keycode == 53)
	{
		printf("%d was pressed!\n", keycode);
		exit (0);
	}
	else
		printf("%d was pressed!\n", keycode);
	return (0);
}

int	mouse_position(int x, int y, void *param)
{
	(void)param;
	printf("cursor is at position (%d, %d)!\n", x, y);
	return (0);
}

int	mouse_click(int keycode, void *param)
{
	(void)param;
	if (keycode == 1)
		printf("The button being clicked is LMB!\n");
	if (keycode == 2)
		printf("The button being clicked is RMB!\n");
	return (0);
}

int	closegame(void *param)
{
	(void)param;
	exit(0);
}

int	main(int argc, char **argv)
{
	t_game game;
	check_file_is_valid(argv[1]);
	game.map = get_map(argv[1]);
	if (game.map != NULL)
	{
		init_game(&game);
		return (0);
	}
}
void	init_game(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, key_press, &game);
	mlx_hook(game->win, 6, 1L << 6, mouse_position, NULL);
	mlx_mouse_hook(game->win, mouse_click, NULL);
	mlx_hook(game->win, 17, 1L << 2, closegame, NULL);
	mlx_loop(game->mlx);
}
