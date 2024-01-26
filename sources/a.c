#include "../includes/so_long.h"
#include <stdio.h>

int	key_press(int keycode, void *param)
{
	(void)param;
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

int	esckey(int keycode, void *param)
{
	(void)param;
	if (keycode == 53)
		exit(0);
	return (0);
}


int	main()
{
	void	*window;
	void	*mlx;
	void	*img;
	int		height;
	int		width;
	// int		pixel;

	height = 800;
	width = 800;
	mlx = mlx_init();

	window = mlx_new_window(mlx, 1200, 800, "Test");

	// img = mlx_new_image(mlx, width, height);

	width = SPRITE_SIZE;
	height = SPRITE_SIZE;
	
	img = mlx_xpm_file_to_image(mlx, COOL, &width, &height);

	mlx_put_image_to_window(mlx, window, img, 16, 16);

	mlx_hook(window, 2, 1L << 0, key_press, NULL);
	mlx_hook(window, 6, 1L << 6, mouse_position, NULL);
	mlx_mouse_hook(window, mouse_click, NULL);
	mlx_hook(window, 17, 1L << 2, closegame, NULL);
	mlx_hook(window, 3, 1L << 0, esckey, NULL);


	mlx_loop(mlx);
	return (0);
}