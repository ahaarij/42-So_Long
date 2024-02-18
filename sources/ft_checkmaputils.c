/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmaputils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 07:23:22 by ahaarij           #+#    #+#             */
/*   Updated: 2024/02/11 15:08:09 by ahaarij          ###   ########.fr       */
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

char	*ft_strjoinfree(char *s1, char *s2)
{
	char	*str;
	size_t	s1len;
	size_t	s2len;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	str = malloc(sizeof(char) * (s1len + s2len + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, s1len);
	ft_memcpy(str + s1len, s2, s2len + 1);
	str[s1len + s2len] = '\0';
	free(s1);
	return (str);
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
	exit(0);
}

void	checkelement(t_game **game, t_map *map)
{
	map->c = 0;
	map->p = 0;
	map->e = 0;
	map->y = get_height((*game)->map) - 1;
	while (map->y--)
	{
		map->x = 0;
		while ((*game)->map[map->y][map->x] != '\0')
		{
			if ((*game)->map[map->y][map->x] == 'E')
				map->e++;
			else if ((*game)->map[map->y][map->x] == 'P')
				map->p++;
			else if ((*game)->map[map->y][map->x] == 'C')
					map->c++;
			else if ((*game)->map[map->y][map->x] != '1' &&
				(*game)->map[map->y][map->x] != '0')
				unknown_element(&game, (*game)->map[map->y][map->x]);
			map->x++;
		}
	}
	if (map->c == 0 || map->p == 0 || map->e == 0 || map->p > 1)
		ft_error(&game, ft_error_message(map));
}

void	move_on_paths(int x, int y, t_map *map)
{
	char	type;
	type = map->copy[y][x];
	if (type == 'C')
	{
		map->c_check -= 1;
		map->copy[y][x] = '1';
	}
	else if (type == 'E')
	{
		map->e_check -= 1;
		map->copy[y][x] = '1';
	}
	else if (type == '0' || type == 'P')
		map->copy[y][x] = '1';
	else
		return ;
	move_on_paths(x + 1, y, map);
	move_on_paths(x - 1, y, map);
	move_on_paths(x, y + 1, map);
	move_on_paths(x, y - 1, map);
}

void	check_valid_path(t_game *game, t_map map)
{
	map.x = ft_strlen(*map.copy);
	scanplayer(&map, *game);
	map.c_check = map.c;
	map.e_check = map.e;
	move_on_paths(map.map_x, map.map_y, &map);
	if(map.c_check != 0 || map.e_check >= map.e)
	{
		write(2, "\033[1;31m🛑ERROR: ", 19);
		write(2, "NO VALID PATH\n\033[0m", 19);
		ft_exit_free(&map, game);
	}
}
