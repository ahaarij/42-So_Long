/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 23:50:12 by ahaarij           #+#    #+#             */
/*   Updated: 2024/02/18 09:11:55 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_exit(t_game ***game)
{
	int	x;

	x = 0;
	while ((**game)->map[x])
	{
		free((**game)->map[x]);
		x++;
	}
	printf("You Won!\n");
	free((**game)->map);
	mlx_destroy_window((**game)->mlx, (**game)->win);
	exit(0);
}
