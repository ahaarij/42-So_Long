/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:14:26 by ahaarij           #+#    #+#             */
/*   Updated: 2024/02/18 16:16:21 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;

	if (size && (count > (UINT_MAX / size)))
		return (NULL);
	result = malloc(size * count);
	if (!result)
		return (NULL);
	ft_bzero(result, size * count);
	return (result);
}
