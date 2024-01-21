/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 09:09:19 by ahaarij           #+#    #+#             */
/*   Updated: 2024/01/19 10:27:59 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	size_hex(unsigned int n)
{
	int	size;

	if (n <= 0)
		size = 1;
	else
		size = 0;
	while (n)
	{
		size++;
		n /= 16;
	}
	return (size);
}

int	ft_printhex(unsigned int n, int x)
{
	char			*base_16;
	int				size;

	size = size_hex(n);
	base_16 = "0123456789abcdef";
	if (x == 0)
		base_16 = "0123456789ABCDEF";
	if (n < 16)
	{
		if (ft_printchar(base_16[n]) == -1)
			return (-1);
	}
	else
	{
		if (ft_printhex(n / 16, x) == -1)
			return (-1);
		if (ft_printhex(n % 16, x) == -1)
			return (-1);
	}
	return (size);
}
