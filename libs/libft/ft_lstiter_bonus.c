/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:54:41 by ofilloux          #+#    #+#             */
/*   Updated: 2025/06/11 15:25:18 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Iterates over a linked list and applies a function to each element's
 *        content.
 *
 * This function traverses the entire list starting from `lst` and applies
 * the function pointed to by `f` to the content of each node.
 * If the list or function pointer is NULL, the function does nothing.
 *
 * @param lst Pointer to the first element of the list.
 * @param f Function to apply to the content of each list element.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;

	if (!lst || !f)
		return ;
	tmp = lst;
	while (tmp)
	{
		f(tmp->content);
		tmp = tmp->next;
	}
}
