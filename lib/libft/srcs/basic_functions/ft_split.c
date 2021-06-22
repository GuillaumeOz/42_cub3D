/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 17:32:04 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/17 20:01:02 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_malloc_and_get_word(const char *s, int c, size_t len)
{
	char	*word;
	size_t	i;

	word = NULL;
	word = (char *)ft_memalloc(sizeof(char) * (len + 1));
	if (word == NULL)
		ft_error("The ft_split malloc have failed");
	i = -1;
	while (s[++i] && s[i] != c)
		word[i] = s[i];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**list;
	size_t	i;
	size_t	k;
	size_t	len;

	if (s == NULL)
		ft_error("The src string is NULL in ft_split");
	list = NULL;
	list = (char **)malloc(sizeof(char *) * (ft_count_elems(s, c) + 1));
	if (list == NULL)
		ft_error("The list** cannot be malloc in ft_split");
	i = -1;
	k = 0;
	while (s[++i])
	{
		if (s[i] != c)
		{
			len = ft_seglen(s, i, c);
			list[k++] = ft_malloc_and_get_word(s + i, c, len);
			i += len - 1;
		}
	}
	list[k++] = NULL;
	return (list);
}
