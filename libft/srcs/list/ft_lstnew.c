/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:05:28 by ahaarij           #+#    #+#             */
/*   Updated: 2024/01/19 10:26:33 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*hi;

	hi = (t_list *)malloc(sizeof(*hi));
	if (!hi)
		return (NULL);
	hi->content = content;
	hi->next = NULL;
	return (hi);
}
