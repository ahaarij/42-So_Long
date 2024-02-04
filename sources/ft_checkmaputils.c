/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmaputils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 07:23:22 by ahaarij           #+#    #+#             */
/*   Updated: 2024/02/04 07:32:39 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	ft_error_message(t_map *map)
{
	if (map->c == 0)
		return ("ERROR: 'C' IS MISSING!");
	if (map->p == 0)
		return ("ERROR: 'P' IS MISSING!");
	if (map->e == 0)
		return ("ERROR: 'E' IS MISSING!");
	
	
}


void	checkelement(t_game **game)
{
	t_map map;

	map.c = 0;
	map.p = 0;
	map.e = 0;
	map.y = get_height((*game)->map) - 1;
	while (map.y--)
	{
		map.x = 0;
		while ((*game)->map[map.y][map.x] != '\0')
		{
			if ((*game)->map[map.y][map.x] == 'E')
				map.e++;
			else if ((*game)->map[map.y][map.x] == 'P')
				map.p++;
			else if ((*game)->map[map.y][map.x] == 'C')
				map.c++;
			else if ((*game)->map[map.y][map.x] != '1' &&
				(*game)->map[map.y][map.x] != '0')
				unknown_element(&game, (*game)->map[map.y][map.x]);
			map.x++;
		}
	}
	if (map.c == 0 || map.p == 0 || map.e == 0 || map.p > 1)
		ft_error(&game, ft_error_message(&map));
}
