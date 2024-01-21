/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 09:38:36 by ahaarij           #+#    #+#             */
/*   Updated: 2024/01/19 10:27:12 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*convdst;
	char	*convsrc;
	size_t	i;

	convdst = (char *)dst;
	convsrc = (char *)src;
	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		convdst[i] = convsrc[i];
		i++;
	}
	return (dst);
}
