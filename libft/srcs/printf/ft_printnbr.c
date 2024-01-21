/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:15:03 by ahaarij           #+#    #+#             */
/*   Updated: 2024/01/19 10:28:01 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_printnbr(int number)
{
	int	digits;

	digits = 0;
	if (number == -2147483648)
		return (ft_printstr("-2147483648"));
	else if (number < 0)
	{
		digits += ft_printchar('-');
		number *= -1;
	}
	if (number > 9)
		digits += ft_printnbr(number / 10);
	digits += ft_printchar((number % 10) + 48);
	return (digits);
}
