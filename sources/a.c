#include "../includes/so_long.h"
#include <stdio.h>
#include <math.h>


int	key_press(int keycode, t_vars *vars)
{
	vars->player.mem = 0;
	if (keycode == 53)
	{
		printf("%d was pressed!\n", keycode);
		exit (0);
	}
	if (keycode == 1)
	{
		vars->player.mem = down;
		mlx_put_image_to_window(vars->mlx, vars->win, vars-player.ptr, vars->player.x, vars->player.y)
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
	// void	*window;
	// void	*mlx;
	// int		height;
	// int		width;
	int		frame;
    // void    *player;
    // void    *zameen;
    t_vars  *vars;

	frame = 1;

	vars->height = 800;
	vars->width = 600;
	vars->mlx = mlx_init();

    vars->x = 100;
    vars->y = 100;
	vars->win = mlx_new_window(vars->mlx, 800, 600, "Test");

    vars->player = mlx_xpm_file_to_image(vars->mlx, IDLEFRAME1, &vars->height, &vars->width);
    // zameen = mlx_xpm_file_to_image(mlx, FLOOR, &height, &width);

    // zameen = mlx_new_image(mlx, 400, 300);
    // mlx_put_image_to_window(mlx, window, zameen, 200, 200);
    mlx_put_image_to_window(vars->mlx, vars->win, vars->player->ptr, vars->x, vars->y);
	// width = SPRITE_SIZE;
	// height = SPRITE_SIZE;
    mlx_string_put(vars->mlx, vars->win, 400, 300, 0xFF0000, "Hello!");

    // mlx_destroy_image(mlx, zameen);

    // mlx_loop_hook(vars.win, move, &vars);

	mlx_hook(vars->win, 2, 1L << 0, key_press, &vars);
	mlx_hook(vars->win, 6, 1L << 6, mouse_position, NULL);
	mlx_mouse_hook(vars->win, mouse_click, NULL);
	mlx_hook(vars->win, 17, 1L << 2, closegame, NULL);

	mlx_loop(vars->mlx);
	return (0);

	// 37 51 most frames
	// 37 50 fourth frame
	// 37 52 eighth frame
}


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

