/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmaputils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 07:23:22 by ahaarij           #+#    #+#             */
/*   Updated: 2024/02/09 14:54:20 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	*ft_error_message(t_map *map)
{
	if (map->c == 0)
		return ("ERROR: 'C' IS MISSING!");
	if (map->p == 0)
		return ("ERROR: 'P' IS MISSING!");
	if (map->e == 0)
		return ("ERROR: 'E' IS MISSING!");
	if (map->p == 0)
		return ("ERROR: element 'P' is missing!");
	if (map->p > 1)
		return ("ERROR: there is more than one element 'P'");
	return ("ERROR: element missing in the map");
	
}

static int	get_width(char **map)
{
	return (ft_strlen(map[0]));
}

static int	check_C(t_game **game, int x, int y)
{
    int height = get_height((*game)->map);
    int width = get_width((*game)->map);

    // if (y > 0 && (*game)->map[y - 1][x] != '1')
    //     return (0);
    // if (y < height - 1 && (*game)->map[y + 1][x] != '1')
    //     return (0);
    // if (x > 0 && (*game)->map[y][x - 1] != '1')
    //     return (0);
    // if (x < width - 1 && (*game)->map[y][x + 1] != '1')
    //     return (0);
	if ((y > 0 && (*game)->map[y - 1][x] != '1') && (y < height - 1 && (*game)->map[y + 1][x] != '1') && (x > 0 && (*game)->map[y][x - 1] != '1') && (x < width - 1 && (*game)->map[y][x + 1] != '1'))
		return (0);
    return (1);
}


static char	*unknown_element(t_game ***game, char c)
{
	int	x;

	x = 0;
	while ((**game)->map[x])
	{
		free((**game)->map[x]);
		x++;
	}
	free((**game)->map);
	printf("ERROR: are u dumb, this is NOT an element... : %c\n", c);
	exit(1);
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
			{
					if (!check_C(game, map.y, map.x))
                    	ft_error(&game, ("Element 'C' is Surrounded By Walls!\n"));
					map.c++;
			}
			else if ((*game)->map[map.y][map.x] != '1' &&
				(*game)->map[map.y][map.x] != '0')
				unknown_element(&game, (*game)->map[map.y][map.x]);
			map.x++;
		}
	}
	if (map.c == 0 || map.p == 0 || map.e == 0 || map.p > 1)
		ft_error(&game, ft_error_message(&map));
}
