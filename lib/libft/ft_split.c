/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylfergu <lylfergu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:37:11 by lylfergu          #+#    #+#             */
/*   Updated: 2025/02/16 18:44:24 by lylfergu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char const *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			counter++;
			while (s[i] && s[i] != c)
			{
				i++;
			}
		}
		else
		{
			i++;
		}
	}
	return (counter);
}

static char	*get_next_word(const char *s, char c, int	*start)
{
	char	*word;
	int		i;

	i = *start;
	while (s[i] && s[i] == c)
	{
		i++;
	}
	*start = i;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	word = ft_substr(s, *start, i - *start);
	if (!word)
	{
		return (NULL);
	}
	*start = i;
	return (word);
}

static	void	ft_free(char **result)
{
	int	i;

	if (!result)
	{
		return ;
	}
	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		countw;
	int		start;
	int		i;

	if (!s)
		return (NULL);
	countw = ft_wordcount(s, c);
	array = (char **)malloc(sizeof(*array) * (countw + 1));
	if (!array)
		return (NULL);
	i = 0;
	start = 0;
	while (i < countw)
	{
		array[i] = get_next_word(s, c, &start);
		if (!array[i])
		{
			ft_free(array);
			return (NULL);
		}
		i++;
	}
	array[i] = NULL;
	return (array);
}

/*int	main(void) 
{ 
	int	i;

  char **result = ft_split("oosummeroocampoohellooo", 'o');
  int count_words = ft_wordcount("oosummeroocampoohellooo", 'o');
  printf("Number of words: %d \n", count_words);
  i = 0;
  while (result[i])
  {
	  printf("%s\n", result[i]);
	  i++;
  }
  i = 0;
  while (result[i])
  {
	free(result[i]);
	i++;
  }
  free(result);
  return(0); 
}*/
