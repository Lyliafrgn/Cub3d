/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:48:22 by ofilloux          #+#    #+#             */
/*   Updated: 2025/06/11 16:15:17 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Adds the element 'new_node' at the end of the list.
 *
 * @param lst Pointer to the pointer of the first element of the list.
 * @param new_node The element to add at the end.
*/
void	ft_lstadd_back(t_list **lst, t_list *new_node)
{
	t_list	*temp;

	if (!*lst)
		*lst = new_node;
	else
	{
		temp = *lst;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}
}
