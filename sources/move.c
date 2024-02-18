/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 23:45:33 by ahaarij           #+#    #+#             */
/*   Updated: 2024/02/18 13:37:35 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	collected(t_game ***g)
{
	int		w_img;
	int		h_img;

	(**g)->collect--;
	(**g)->map[((**g)->p_y / 32)][((**g)->p_x / 32)] = '0';
	(**g)->img = mlx_xpm_file_to_image(
			(**g)->mlx, "./assets/floor.xpm", &w_img, &h_img);
	mlx_put_image_to_window(
		(**g)->mlx, (**g)->win, (**g)->img, (**g)->p_x, (**g)->p_y);
}

void	to_right(t_game **game)
{
	int	w_img;
	int	h_img;

	(*game)->img = mlx_xpm_file_to_image(
			(*game)->mlx, "./assets/floor.xpm", &w_img, &h_img);
	mlx_put_image_to_window(
		(*game)->mlx, (*game)->win, (*game)->img, (*game)->p_x, (*game)->p_y);
	if ((*game)->map[((*game)->p_y / 32)][((*game)->p_x / 32) + 1] == 'E')
	{
		if ((*game)->collect <= 0)
		{
			// mlx_string_put((*game)->mlx, (*game)->win, 100, 100, 0xff0000, "GG's");
			// sleep(5);
			ft_exit(&game);
		}
	}
	else if ((*game)->map[((*game)->p_y / 32)][((*game)->p_x / 32) + 1] != '1')
	{
		(*game)->p_x += 32;
		put_text(&game);
	}
	if ((*game)->map[((*game)->p_y / 32)][((*game)->p_x / 32)] == 'C')
		collected(&game);
	(*game)->img = mlx_xpm_file_to_image(
			(*game)->mlx, "./assets/slimeright.xpm", &w_img, &h_img);
	mlx_put_image_to_window(
		(*game)->mlx, (*game)->win, (*game)->img, (*game)->p_x, (*game)->p_y);
}

void	to_left(t_game **game)
{
	int	w_img;
	int	h_img;

	(*game)->img = mlx_xpm_file_to_image(
			(*game)->mlx, "./assets/floor.xpm", &w_img, &h_img);
	mlx_put_image_to_window(
		(*game)->mlx, (*game)->win, (*game)->img, (*game)->p_x, (*game)->p_y);
	if ((*game)->map[((*game)->p_y / 32)][((*game)->p_x / 32) - 1] == 'E')
	{
		if ((*game)->collect <= 0)
		{
			// mlx_string_put((*game)->mlx, (*game)->win, 100, 100, 0xff0000, "GG's");
			// sleep(5);
			ft_exit(&game);
		}
	}
	else if ((*game)->map[((*game)->p_y / 32)][((*game)->p_x / 32) - 1] != '1')
	{
		(*game)->p_x -= 32;
		put_text(&game);
	}
	if ((*game)->map[((*game)->p_y / 32)][((*game)->p_x / 32)] == 'C')
		collected(&game);
	(*game)->img = mlx_xpm_file_to_image(
			(*game)->mlx, "./assets/slimeleft.xpm", &w_img, &h_img);
	mlx_put_image_to_window(
		(*game)->mlx, (*game)->win, (*game)->img, (*game)->p_x, (*game)->p_y);
}

void	to_up(t_game **v)
{
	int	w_img;
	int	h_img;

	(*v)->img = mlx_xpm_file_to_image(
			(*v)->mlx, "./assets/floor.xpm", &w_img, &h_img);
	mlx_put_image_to_window(
		(*v)->mlx, (*v)->win, (*v)->img, (*v)->p_x, (*v)->p_y);
	if ((*v)->map[((*v)->p_y / 32) - 1][((*v)->p_x / 32)] == 'E')
	{
		if ((*v)->collect <= 0)
		{
			// mlx_string_put((*v)->mlx, (*v)->win, 100, 100, 0xff0000, "GG's");
			// sleep(5);
			ft_exit(&v);
		}
	}
	else if ((*v)->map[((*v)->p_y / 32) - 1][((*v)->p_x / 32)] != '1')
	{
		(*v)->p_y -= 32;
		put_text(&v);
	}
	if ((*v)->map[((*v)->p_y / 32)][((*v)->p_x / 32)] == 'C')
		collected(&v);
	(*v)->img = mlx_xpm_file_to_image(
			(*v)->mlx, "./assets/slimeup.xpm", &w_img, &h_img);
	mlx_put_image_to_window(
		(*v)->mlx, (*v)->win, (*v)->img, (*v)->p_x, (*v)->p_y);
}

void	to_down(t_game **v)
{
	int		w_img;
	int		h_img;

	(*v)->img = mlx_xpm_file_to_image(
			(*v)->mlx, "./assets/floor.xpm", &w_img, &h_img);
	mlx_put_image_to_window(
		(*v)->mlx, (*v)->win, (*v)->img, (*v)->p_x, (*v)->p_y);
	if ((*v)->map[((*v)->p_y / 32) + 1][((*v)->p_x / 32)] == 'E')
	{
		if ((*v)->collect <= 0)
		{
			// mlx_string_put((*v)->mlx, (*v)->win, 100, 100, 0xff0000, "GG's");
			// sleep(5);
			ft_exit(&v);
		}
	}
	else if ((*v)->map[((*v)->p_y / 32) + 1][((*v)->p_x / 32)] != '1')
	{
		(*v)->p_y += 32;
		put_text(&v);
	}
	if ((*v)->map[((*v)->p_y / 32)][((*v)->p_x / 32)] == 'C')
		collected(&v);
	(*v)->img = mlx_xpm_file_to_image(
			(*v)->mlx, "./assets/slimedown.xpm", &w_img, &h_img);
	mlx_put_image_to_window(
		(*v)->mlx, (*v)->win, (*v)->img, (*v)->p_x, (*v)->p_y);
}
