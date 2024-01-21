/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:38:41 by ahaarij           #+#    #+#             */
/*   Updated: 2024/01/21 10:02:04 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*hi;

	if (new == NULL)
		return ;
	hi = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (hi->next)
			hi = hi->next;
		hi->next = new;
	}
}
