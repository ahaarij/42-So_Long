#include "../includes/so_long.h"
#include <stdio.h>
#include <math.h>


int	key_press(int keycode, t_game *game)
{
	game->player.mem = 0;
	if (keycode == 53)
	{
		printf("%d was pressed!\n", keycode);
		exit (0);
	}
	if (keycode == 1)
	{
		game->player.mem = down;
		mlx_put_image_to_window(game->mlx, game->win, game->player.ptr, game->player.x, game->player.y + 10);
	}
	else
		printf("%d was pressed!\n", keycode);
	return (keycode);
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

int	main()
{
	t_game game;
	init_game(&game);
	return (0);
}
void	init_game(t_game *game)
{
	init_window(game);
	init_images(game);
	mlx_hook(game->mlx, 2, 1L >> 0, key_press, &game);
	mlx_loop(game->mlx);
}



// int	main()
//{
	// void	*window;
	// void	*mlx;
	// int		height;
	// int		width;
    // void    *player;
    // void    *zameen;
//     t_game  *game = NULL;

// 	game->plot.height = 800;
// 	game->plot.width = 600;
// 	game->mlx = mlx_init();

//     game->player.x = 100;
//     game->player.y = 100;
// 	game->win = mlx_new_window(game->mlx, 800, 600, "Test");

//     game->player.ptr = mlx_xpm_file_to_image(game->mlx, SLIME, &game->plot.height, &game->plot.width);
//     // zameen = mlx_xpm_file_to_image(mlx, FLOOR, &height, &width);

//     // zameen = mlx_new_image(mlx, 400, 300);
//     // mlx_put_image_to_window(mlx, window, zameen, 200, 200);
//     mlx_put_image_to_window(game->mlx, game->win, game->player.ptr, game->player.x, game->player.y);
// 	// width = SPRITE_SIZE;
// 	// height = SPRITE_SIZE;
//     mlx_string_put(game->mlx, game->win, 400, 300, 0xFF0000, "Hello!");

//     // mlx_destroy_image(mlx, zameen);

//     // mlx_loop_hook(vars.win, move, &vars);

// 	mlx_hook(game->win, 2, 1L << 0, key_press, &game);
// 	mlx_hook(game->win, 6, 1L << 6, mouse_position, NULL);
// 	mlx_mouse_hook(game->win, mouse_click, NULL);
// 	mlx_hook(game->win, 17, 1L << 2, closegame, NULL);

// 	mlx_loop(game->mlx);
// 	return (0);

// 	// 37 51 most frames
// 	// 37 50 fourth frame
// 	// 37 52 eighth frame
// }


// int	main()
// {
// 	void	*window;
// 	void	*mlx;
// 	int		height;
// 	int		width;
// 	int		frame;
//     void    *player;
//     void    *player2;
//     void    *player3;
//     void    *player4;
//     void    *player5;
//     void    *player6;
//     void    *player7;
//     void    *player8;
//     // void    *zameen;

// 	frame = 1;

// 	height = 800;
// 	width = 800;
//     int i = 0;
// 	mlx = mlx_init();

// 	window = mlx_new_window(mlx, 1000, 1000, "Test");
//     while(i > 3)
//     {
//         player = mlx_xpm_file_to_image(mlx, IDLEFRAME1, &height, &width);
//         mlx_put_image_to_window(mlx, window, player, 100, 100);
//         mlx_destroy_image(mlx, player);
//         usleep(1000000);
//         player2 = mlx_xpm_file_to_image(mlx, IDLEFRAME2, &height, &width);
//         mlx_put_image_to_window(mlx, window, player2, 100, 100);
//         mlx_destroy_image(mlx, player);
//         usleep(1000000);
//         player3 = mlx_xpm_file_to_image(mlx, IDLEFRAME3, &height, &width);
//         mlx_put_image_to_window(mlx, window, player3, 100, 100);
//         mlx_destroy_image(mlx, player);
//         usleep(1000000);
//         player4 = mlx_xpm_file_to_image(mlx, IDLEFRAME4, &height, &width);
//         mlx_put_image_to_window(mlx, window, player4, 100, 100);
//         mlx_destroy_image(mlx, player);
//         usleep(1000000);
//         player5 = mlx_xpm_file_to_image(mlx, IDLEFRAME5, &height, &width);
//         mlx_put_image_to_window(mlx, window, player5, 100, 100);
//         mlx_destroy_image(mlx, player);
//         usleep(1000000);
//         player6 = mlx_xpm_file_to_image(mlx, IDLEFRAME6, &height, &width);
//         mlx_put_image_to_window(mlx, window, player6, 100, 100);
//         mlx_destroy_image(mlx, player);
//         usleep(1000000);
//         player7 = mlx_xpm_file_to_image(mlx, IDLEFRAME7, &height, &width);
//         mlx_put_image_to_window(mlx, window, player7, 100, 100);
//         mlx_destroy_image(mlx, player);
//         usleep(1000000);
//         player8 = mlx_xpm_file_to_image(mlx, IDLEFRAME8, &height, &width);
//         mlx_put_image_to_window(mlx, window, player8, 100, 100);
//         mlx_destroy_image(mlx, player);
//         usleep(1000000);
//         i += 1;
//     }

// 	mlx_hook(window, 2, 1L << 0, key_press, NULL);
// 	mlx_hook(window, 6, 1L << 6, mouse_position, NULL);
// 	mlx_mouse_hook(window, mouse_click, NULL);
// 	mlx_hook(window, 17, 1L << 2, closegame, NULL);

// 	mlx_loop(mlx);
// 	return (0);

// 	// 37 51 most frames
// 	// 37 50 fourth frame
// 	// 37 52 eighth frame
// }

