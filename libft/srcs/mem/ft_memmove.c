/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 09:19:30 by ahaarij           #+#    #+#             */
/*   Updated: 2024/01/19 10:27:16 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*convdst;
	char	*convsrc;
	size_t	i;

	i = 0;
	convdst = (char *)dst;
	convsrc = (char *)src;
	if (convdst > convsrc)
	{
		while (len > i)
		{
			len--;
			convdst[len] = convsrc[len];
		}
		return (dst);
	}
	else
		ft_memcpy(convdst, convsrc, len);
	return (dst);
}
