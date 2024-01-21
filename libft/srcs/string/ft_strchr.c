/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:04:21 by ahaarij           #+#    #+#             */
/*   Updated: 2024/01/19 10:28:44 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strchr(const char *s, int i)
{
	while (*s)
	{
		if (*s == (unsigned char)i)
			return ((char *)s);
		s++;
	}
	if (*s == (unsigned char)i)
		return ((char *)s);
	return (0);
}
