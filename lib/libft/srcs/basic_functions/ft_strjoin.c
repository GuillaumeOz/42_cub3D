/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 21:03:49 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/17 20:04:44 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;

	if (s1 || s2)
	{
		if (!s2)
			return (ft_strdup((char *)s1));
		if (!s1)
			return (ft_strdup((char *)s2));
		new_str = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (new_str == NULL)
			return (NULL);
		return (ft_strcat(ft_strcat(new_str, s1), s2));
	}
	return (NULL);
}
