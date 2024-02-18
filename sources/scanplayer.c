/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanplayer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 09:14:51 by ahaarij           #+#    #+#             */
/*   Updated: 2024/02/18 09:15:04 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	scanplayer(t_map *map, t_game game)
{
	map->map_y = 0;
	map->map_x = 0;
	map->y = get_height(game.map);
	map->x = ft_strlen(*game.map);
	while (map->map_y < map->y)
	{
		while (map->map_x < map->x)
		{
			if (map->copy[map->map_y][map->map_x] == 'P')
				break ;
			map->map_x++;
		}
		if (map->copy[map->map_y][map->map_x] == 'P')
			break ;
		map->map_x = 0;
		map->map_y++;
	}
}
