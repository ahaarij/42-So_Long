#include "../includes/so_long.h"
#include <stdio.h>
#include <math.h>

int	key_press(int keycode, void *param)
{
	(void)param;
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

// int	esckey(int keycode, void *param)
// {
// 	(void)param;
// 	if (keycode == 53)
// 		exit(0);
// 	return (0);
// }


// int	main()
// {
// 	void	*window;
// 	void	*mlx;
// 	int		height;
// 	int		width;
// 	int		frame;
// 	char	filename[20];
// 	void	*img;

// 	frame = 1;

// 	height = 800;
// 	width = 800;
// 	mlx = mlx_init();

// 	window = mlx_new_window(mlx, 1200, 800, "Test");

// 	width = SPRITE_SIZE;
// 	height = SPRITE_SIZE;
// 	while(1)
// 	{
// 		sprintf(filename, "idleframe%d.xpm", frame);

// 		img = mlx_xpm_file_to_image(mlx, filename, &width, &height);
// 		mlx_put_image_to_window(mlx, window, filename, 800, 100);

// 		frame = (frame % NUM_FRAMES) + 1;

// 		usleep(100000);
// 	}
// 	// mlx_hook(window, 2, 1L << 0, key_press, NULL);
// 	// mlx_hook(window, 6, 1L << 6, mouse_position, NULL);
// 	// mlx_mouse_hook(window, mouse_click, NULL);
// 	// mlx_hook(window, 17, 1L << 2, closegame, NULL);

// 	mlx_loop(mlx);
// 	return (0);

// 	// 37 51 most frames
// 	// 37 50 fourth frame
// 	// 37 52 eighth frame
// }

int main(void)
{
    void *mlx; // The magical mlx pointer
    void *win; // The window pointer
    void *img; // The sprite image pointer
    int width; // Width of the sprite
    int height; // Height of the sprite
    int frame = 1; // Current frame of the sprite animation

	width = 100;
	height = 100;
    // Initialize mlx
    mlx = mlx_init();

    // Create a window
    win = mlx_new_window(mlx, 800, 600, "Sprite Animation Ritual");

    // The animation loop
    while (1) {
        // Load the current frame of your sprite animation
        char frame_filename[20]; // Assuming frame filenames are like "frame1.xpm", "frame2.xpm", etc.
        sprintf(frame_filename, "frame%d.xpm", frame);
        img = mlx_xpm_file_to_image(mlx, frame_filename, &width, &height);

        // Display the sprite on the window
        mlx_put_image_to_window(mlx, win, img, 200, 100);

        // Update the frame for the next iteration
        frame = (frame % NUM_FRAMES) + 1; // Change frame from 1 to NUM_FRAMES and loop back

        // Adjust the frame rate for your desired animation speed
        usleep(100000); // Sleep for 0.1 seconds (adjust as needed)
    }

    return 0;
}