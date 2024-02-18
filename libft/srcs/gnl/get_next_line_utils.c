/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 09:10:32 by ahaarij           #+#    #+#             */
/*   Updated: 2024/02/18 09:30:23 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_strgnl(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchrgnl(const char *s, int i)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (unsigned char)i)
			return ((char *)s);
		s++;
	}
	if (*s == (unsigned char)i)
		return ((char *)s);
	return (NULL);
}

char	*ft_strdupgnl(const char *src)
{
	unsigned int	i;
	unsigned int	j;
	char			*dest;

	i = 0;
	j = ft_strgnl(src);
	dest = (char *)malloc(sizeof(*dest) * (j + 1));
	if (!dest)
		return (NULL);
	while (i < j)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1)
		return (ft_strdupgnl(s2));
	if (!s2)
		return (ft_strdupgnl(s1));
	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strgnl(s1) + ft_strgnl(s2) + 1));
	if (!str)
		return (NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free (s1);
	return (str);
}
