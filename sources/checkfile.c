/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:19:44 by ahaarij           #+#    #+#             */
/*   Updated: 2024/02/18 09:11:34 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	needle(char *str, char *to_find)
{
	int	i;

	i = 0;
	while (to_find[i])
	{
		if (to_find[i] != str[i])
			return (0);
		i++;
	}
	if (str[i] == '\0')
		return (1);
	return (0);
}

void	check_file_is_valid(char *file_line)
{
	while (*file_line)
	{
		if (*file_line == '.')
		{
			if (needle(file_line, ".ber"))
			{
				return ;
			}
		}
		file_line++;
	}
	ft_printf("Error: file is not valid");
	exit(0);
}
