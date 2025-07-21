/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:53:55 by ofilloux          #+#    #+#             */
/*   Updated: 2025/06/11 15:23:51 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
/*
void	del(void *content)
{
	free(content);
	stuff = NULL;
}
*/

/**
 * @brief Deletes a single list element.
 *
 * Applies the function 'del' to the content of the element,
 * then frees the element itself.
 *
 * @param lst The element to delete.
 * @param del Function to delete the element's content.
*/
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (del && lst)
	{
		del(lst->content);
		free(lst);
		lst = NULL;
	}
}
/*
int	main(void)
{
	t_list	*node;

	node = ft_lstnew("blabla");
	printf("%s\n", (char *)node->content);
	printf("%p\n", (char *)node->content);
	ft_lstdelone(node1, del);
	printf("%s\n", (char *)node->content);
	printf("%p\n", (char *)node->content);

	return (0);
}*/
