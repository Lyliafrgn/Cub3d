/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:56:08 by ofilloux          #+#    #+#             */
/*   Updated: 2025/06/11 15:28:47 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//void *f(void *content);

t_list	*freelist(void (*del)(void *), void **new_content, t_list **new_list)
{
	del(*new_content);
	ft_lstclear(&(*new_list), del);
	return (NULL);
}

/**
 * @brief Iterates over a list, applies a function to each element’s content,
 *        and creates a new list with the results.
 *
 * This function traverses the linked list `lst` and applies the function `f`
 * to the content of each node to create new content. For each transformed
 * content,a new node is allocated and added to the new list.
 * If any allocation fails, the function uses `del` to free all allocated
 * content and nodes before returning NULL.
 *
 * @param lst Pointer to the first element of the input list.
 * @param f Function to apply to each element's content.
 * @param del Function to free the content of an element if needed.
 * @return Pointer to the first element of the new list, or NULL on failure.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	tmp = lst;
	while (tmp)
	{
		new_content = f(tmp->content);
		new_node = ft_lstnew(new_content);
		if (new_node == NULL)
			return (freelist(del, &new_content, &new_list));
		ft_lstadd_back(&new_list, new_node);
		tmp = tmp->next;
	}
	return (new_list);
}
/*
void *f(void *content)
{
	int	i;
	int	len;
	char	*str;
	char	*new_str;

	str = (char *)content;
	len = ft_strlen(str);
	new_str = malloc((len + 1)* sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < len)
	{
        new_str[i] = 'a';
		i++;
	}
	new_str[len] = '\0';
	return (new_str);
}

#include <stdio.h>
void print_list(t_list *lst)
{
	if (lst)
    {
		while (lst != NULL)
		{
        	printf("%s\n", (char *)lst->content);
        	lst = lst->next;
    	}
	}
}

int main(void)
{
    t_list	*lst;

	lst = NULL;
//	lst = ft_lstnew("Hello");
    ft_lstadd_back(&lst, ft_lstnew("Oliv"));
    ft_lstadd_back(&lst, ft_lstnew("yo"));
    ft_lstadd_back(&lst, ft_lstnew("man"));

	print_list(lst);
    t_list *mapped_lst = ft_lstmap(lst, f, free);

    print_list(lst);
	ft_lstclear(&lst, free);
    printf("Liste transformée:\n");
    print_list(mapped_lst);

    ft_lstclear(&mapped_lst, free);


    return (0);
}
*/
