/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:51:45 by ofilloux          #+#    #+#             */
/*   Updated: 2025/06/11 16:14:58 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Adds the element 'new' at the beginning of the list.
 *
 * @param lst Pointer to the pointer of the first element of the list.
 * @param new_node The element to add at the front.
*/
void	ft_lstadd_front(t_list **lst, t_list *new_node)
{
	if (lst && new_node)
	{
		new_node->next = *lst;
		*lst = new_node;
	}
}

/*
int	main(void)
{
	t_list	*a;
	t_list	*b;

	a = ft_lstnew("a");
	b = ft_lstnew("b");
	ft_lstadd_front(&a, &b);
	printf("%s\n", (char *)a->content);//should return "b"
	return (0);
}*/
