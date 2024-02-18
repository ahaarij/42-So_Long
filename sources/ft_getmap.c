/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:27:37 by ahaarij           #+#    #+#             */
/*   Updated: 2024/02/12 10:30:05 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_msgerror(void)
{
	perror("ERROR:");
	exit(1);
}

int	get_height(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}
void	ft_exit_free(t_map *map, t_game *game)
{
	if (game->map)
		free(game->map);
	if (map->copy)
		free(map->copy);
	if (map->file)
		free(map->file);
	if (map->line)
		free(map->file);
	exit(0);
}

void	get_map(t_map *map, t_game *game)
{
	int		fd;

	map->y = 0;
	map->line = "";
	map->file = NULL;
	fd = open(map->filename, O_RDONLY);
	if (fd == -1)
		printf("Not working\n");
	while (map->line)
	{
		map->line = get_next_line(fd);
		if (map->line == NULL)
			break ;
		map->file = ft_strjoinfree(map->file, map->line);
		free(map->line);
		if (!map->file)
			ft_exit_free(map, game);
		map->y++;
	}
	close(fd);
	game->map = ft_split(map->file, '\n');
	map->copy = ft_split(map->file, '\n');
	if (!game->map || !map->copy)
		ft_exit_free(map, game);
	free(map->file);
}