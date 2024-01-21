/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 16:45:55 by ahaarij           #+#    #+#             */
/*   Updated: 2024/01/19 10:27:00 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*conv;

	conv = (char *)s;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)conv[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
