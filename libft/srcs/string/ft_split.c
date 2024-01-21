/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:55:09 by ahaarij           #+#    #+#             */
/*   Updated: 2024/01/19 10:28:39 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	wordcount(char *str, char c)
{
	int	i;
	int	word;

	i = 1;
	word = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] != c)
		{
			word++;
			while (str[i] != c && str[i])
				i++;
		}
		else
			i++;
	}
	return (word);
}

static void	freemem(char **str, int i)
{
	if (!str)
		return ;
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free (str);
}

static char	**allocate_memory(const char *s, char c)
{
	char	**mem;
	int		word;

	if (*s == '\0')
	{
		mem = malloc(sizeof(char *));
		if (!mem)
			return (NULL);
		mem[0] = NULL;
		return (mem);
	}
	word = wordcount((char *)s, c);
	mem = malloc(sizeof(char **) * (word + 1));
	if (!mem)
		return (NULL);
	mem[word] = 0;
	return (mem);
}

static char	**fill_memory(char **mem, const char *s, char c, int word)
{
	int		j;
	size_t	i;
	size_t	len;

	i = 0;
	j = 0;
	while (s[i] && j < word)
	{
		while (s[i] == c)
			i++;
		len = 0;
		while (s[i + len] != c && s[i + len])
			len++;
		mem[j] = ft_substr(s, i, len);
		if (!mem[j])
		{
			freemem(mem, j - 1);
			return (NULL);
		}
		i += len;
		j++;
	}
	return (mem);
}

char	**ft_split(const char *s, char c)
{
	char	**mem;
	int		word;

	if (!s)
		return (NULL);
	mem = allocate_memory(s, c);
	if (!mem)
		return (NULL);
	if (*s == '\0' && c != '\0')
	{
		mem[0] = NULL;
		return (mem);
	}
	word = wordcount((char *)s, c);
	mem = fill_memory(mem, s, c, word);
	return (mem);
}
