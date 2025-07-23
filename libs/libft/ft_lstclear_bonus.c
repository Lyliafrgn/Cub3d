/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:52:20 by ofilloux          #+#    #+#             */
/*   Updated: 2025/06/11 15:23:24 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

/*
void	del(void *stuff)
{
	if (stuff)
		free(stuff);

	stuff = NULL;
}
*/

/**
 * @brief Deletes and frees all elements of the list.
 *
 * Applies the function 'del' to the content of each element,
 * frees the element, and sets the list pointer to NULL.
 *
 * @param lst Pointer to the pointer of the first element of the list.
 * @param del Function used to delete the content of an element.
 */
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (*lst && del)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			if ((*lst)->content)
				del((*lst)->content);
			(*lst)->next = NULL;
			free(*lst);
			*lst = tmp ;
		}
	}
	*lst = NULL;
}

/*
int	main(void)
{
	t_list	*node_a;
	t_list	*node_b;

	node_a = ft_lstnew("1");
	node_b = ft_lstnew("2");
	node_a->next = node_b;

	printf("%s",node_b->content);
	ft_lstclear(&node_b, del);
	printf("%s",node_b->content);
	return (0);
}*/
