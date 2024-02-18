/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spriteanimate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:37:54 by ahaarij           #+#    #+#             */
/*   Updated: 2024/02/17 18:54:00 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    render_img(t_game **game)
{
    int img_w;
    int img_h;
    
    (*game)->e_vars.imgs[0] = "./assets/1.xpm";
    (*game)->e_vars.imgs[1] = "./assets/3.xpm";
	(*game)->e_vars.imgs[2] = "./assets/4.xpm";
	(*game)->e_vars.imgs[3] = "./assets/3.xpm";
	(*game)->e_vars.imgs[4] = "./assets/1.xpm";
    (*game)->img = mlx_xpm_file_to_image(
			(*game)->mlx, "./assets/floor.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*game)->mlx, (*game)->win, (*game)->img,
		(*game)->e_vars.x_e * 32, (*game)->e_vars.y_e * 32);
	(*game)->img = mlx_xpm_file_to_image(
			(*game)->mlx, (*game)->e_vars.imgs[(*game)->e_vars.x],
			&img_w, &img_h);
	mlx_put_image_to_window(
		(*game)->mlx, (*game)->win, (*game)->img,
		(*game)->e_vars.x_e * 32, (*game)->e_vars.y_e * 32);
}

void    move_enemy(t_game **game)
{
    int img_w;
    int img_h;

    (*game)->img = mlx_xpm_file_to_image(
		(*game)->mlx, "./assets/floor.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*game)->mlx, (*game)->win, (*game)->img,
		(*game)->e_vars.x_e * 32, (*game)->e_vars.y_e * 32);
    if ((*game)->map[(*game)->e_vars.y_e][(*game)->e_vars.x_e + 1] != '1' &&
		(*game)->map[(*game)->e_vars.y_e][(*game)->e_vars.x_e + 1] != 'C' &&
		(*game)->map[(*game)->e_vars.y_e][(*game)->e_vars.x_e + 1] != 'E' &&
		(*game)->e_vars.path_to_move == 0)
		(*game)->e_vars.x_e++;
	else
		(*game)->e_vars.path_to_move = 1;
	if ((*game)->map[(*game)->e_vars.y_e][(*game)->e_vars.x_e - 1] != '1' &&
		(*game)->map[(*game)->e_vars.y_e][(*game)->e_vars.x_e - 1] != 'C' &&
		(*game)->map[(*game)->e_vars.y_e][(*game)->e_vars.x_e - 1] != 'E' &&
		(*game)->e_vars.path_to_move == 1)
		(*game)->e_vars.x_e--;
	else
		(*game)->e_vars.path_to_move = 0;
}

static void	ft_lose(t_game **game, char *err)
{
	int	x;

	x = 0;
	while ((*game)->map[x])
	{
		free((*game)->map[x]);
		x++;
	}
	free((*game)->map);
	printf("%s", err);
	exit(0);
}


int spriteanimate(t_game *game)
{
    if(get_za_enemy_position(&game) != 0)
    {
        if(game->e_vars.sleep-- <= 0)
        {
            game->e_vars.x++;
            game->e_vars.sleep = 5;
        }
        if (game->e_vars.x == 3)
            game->e_vars.x = 0;
        if (game->e_vars.sleep_for_move-- <= 0)
        {
            move_enemy(&game);
            game->e_vars.sleep_for_move = 30;
        }
        if ((game->e_vars.y_e == game->p_y / 32)
		    && (game->e_vars.x_e == game->p_x / 32))
	    {
			ft_lose(&game, "L + Ratio\n");
		}
        render_img(&game);
    }
    if (game->collect <= 0)
		open_exit(&game);
	return (0);
}