/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:27:23 by ahaarij           #+#    #+#             */
/*   Updated: 2024/02/11 09:06:27 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	unsigned int	j;
	unsigned int	i;
	char			*dest;

	i = 0;
	j = ft_strlen(s1);
	dest = (char *)malloc(sizeof(*dest) * (j + 1));
	if (!dest)
		return (NULL);
	while (i < j)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
