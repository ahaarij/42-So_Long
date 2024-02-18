/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:38:21 by ahaarij           #+#    #+#             */
/*   Updated: 2024/02/18 09:24:29 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_text(t_game ***game)
{
	int		img_w;
	int		img_h;
	char	*text;
	char	*number;

	number = ft_itoa(++(**game)->movement);
	text = ft_strjoin("Move: ", number);
	(**game)->img = mlx_xpm_file_to_image(
			(**game)->mlx, "./assets/cobble.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(**game)->mlx, (**game)->win, (**game)->img, 0, 0);
	mlx_put_image_to_window(
		(**game)->mlx, (**game)->win, (**game)->img, 32, 0);
	mlx_put_image_to_window(
		(**game)->mlx, (**game)->win, (**game)->img, 32 * 2, 0);
	mlx_string_put((**game)->mlx, (**game)->win, 5, 10, 0xfffffff, text);
	free(text);
	free(number);
}
