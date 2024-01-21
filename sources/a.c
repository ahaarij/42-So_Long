#include "../includes/so_long.h"

int	main()
{
	void	*window;
	void	*mlx;
	void	*img;
	
	mlx = mlx_init();

	window = mlx_new_window(mlx, 1200, 800, "Test");

	int	height;
	int	width;

	width = SPRITE_SIZE;
	height = SPRITE_SIZE;
	
	img = mlx_xpm_file_to_image(mlx, COOL, &width, &height);

	mlx_put_image_to_window(mlx, window, img, 16, 16);

	mlx_loop(mlx);

	return (0);
}