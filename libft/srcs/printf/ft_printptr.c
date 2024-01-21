/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 08:56:58 by ahaarij           #+#    #+#             */
/*   Updated: 2024/01/19 10:28:03 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	size_hex(unsigned long long n)
{
	int	size;

	size = 0;
	while (n)
	{
		size++;
		n /= 16;
	}
	return (size);
}

int	ft_hex(unsigned long long n)
{
	char			*base_16;
	int				size;

	size = size_hex(n);
	base_16 = "0123456789abcdef";
	if (n < 16)
	{
		if (ft_printchar(base_16[n]) == -1)
			return (-1);
	}
	else
	{
		ft_hex(n / 16);
		ft_hex(n % 16);
	}
	return (size);
}

int	ft_printptr(void *ptr)
{
	int	n;

	if (ft_printstr("0x") == -1)
		return (-1);
	n = ft_hex((unsigned long long) ptr);
	if (n != 0)
		return (n + 2);
	else
		return (3);
}
