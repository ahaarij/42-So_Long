/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:11:52 by ahaarij           #+#    #+#             */
/*   Updated: 2024/01/19 10:27:36 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	format(const char *input, unsigned int *i, va_list *args)
{
	unsigned int	counter;

	counter = 0;
	if (input[*i] == 'c')
		counter += ft_printchar(va_arg(*args, int));
	else if (input[*i] == 's')
		counter += ft_printstr(va_arg(*args, char *));
	else if (input[*i] == 'p')
		counter += ft_printptr(va_arg(*args, void *));
	else if (input[*i] == 'd' || input [*i] == 'i')
		counter += ft_printnbr(va_arg(*args, int));
	else if (input [*i] == 'u')
		counter += ft_printuint(va_arg(*args, int));
	else if (input [*i] == 'x')
		counter += ft_printhex(va_arg(*args, int), 1);
	else if (input [*i] == 'X')
		counter += ft_printhex(va_arg(*args, int), 0);
	else if (input [*i] == '%')
	{
		ft_printchar('%');
		return (1);
	}
	return (counter);
}

int	ft_printf(const char *input, ...)
{
	va_list			args;
	unsigned int	i;
	unsigned int	counter;

	i = 0;
	counter = 0;
	va_start(args, input);
	while (input[i])
	{
		if (input[i] == '%')
		{
			i++;
			counter += format(input, &i, &args);
		}
		else
			counter += ft_printchar(input[i]);
		i++;
	}
	va_end (args);
	return (counter);
}
