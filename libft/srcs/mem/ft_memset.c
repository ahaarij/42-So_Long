/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:30:16 by ahaarij           #+#    #+#             */
/*   Updated: 2024/01/19 10:27:20 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memset(void *a, int b, size_t len)
{
	char	*convert;
	size_t	i;

	convert = (char *)a;
	i = 0;
	while (i < len)
	{
		convert[i] = b;
		i++;
	}
	return (a);
}
