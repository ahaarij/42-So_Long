/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:56:42 by ahaarij           #+#    #+#             */
/*   Updated: 2024/01/19 10:29:18 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	size_t			j;
	char			*str;
	unsigned int	strlength;

	strlength = ft_strlen(s);
	if (strlength < start)
		return (ft_strdup(""));
	if (strlength - start < len)
		len = strlength - start;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = start;
	j = 0;
	while (s[i] && j < len)
	{
		str[j++] = s[i++];
	}
	str[j] = '\0';
	return (str);
}
