/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:32:02 by ahaarij           #+#    #+#             */
/*   Updated: 2024/02/03 14:09:01 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_error(t_game ***game, char *error)
{
	int	x;

	x = 0;
	while ((**game)->map[x])
	{
		free((**game)->map[x]);
		x++;
	}
	free((**game)->map);
	printf("%s", error);
	exit(1);
}

static void	check_is_rectangle(t_game **game)
{
	int	x_map;
	int	y_map;
	int	height;
	int	backup;

	height = get_height((*game)->map);
	y_map = 0;

	while (y_map != height);
	{
		x_map = 0;
		while((*game)->map[y_map][x_map] != '\0')
			x_map++;
		y_map++;
		if (backup != 0)
		{
			if (backup != x_map)
				ft_error(&game, "Map is not rectangular");		
		}
		else
			backup = x_map;
	}
}

static int	check_line(char *line)
{
	int	i;

	i = 0;
	while(line[i] != '\0')
	{
		if(line[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

static void	check_walls(t_game **game)
{
	char	*error;
	int		i;

	error = "Map is not closed!";
	if (check_line((*game)->map[0]))
		ft_error(&game, error);
	i = get_height((*game)->map);
	while (i)
	{
		if((*game)->map[i][0] != '1' || (*game)->map[i][ft_strlen((*game)->map) - 1] != '1')
			ft_error(&game, error);
		i--;
	}
	if (check_line((*game)->map[get_height((*game)->map) - 1]))
		ft_error(&game, error);
}

void	checkmapvalid(t_game *game)
{
	check_is_rectangle(&game);
	check_walls(&game);
}