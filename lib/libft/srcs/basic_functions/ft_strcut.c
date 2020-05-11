/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 19:52:51 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/25 13:29:35 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcut(char **s1, char delim)
{
	char	*tmp;
	char	*result;
	size_t	len;
	size_t	string_size;

	tmp = *s1;
	len = 0;
	string_size = 0;
	while (tmp[len] != '\0' && tmp[len] == delim)
		len++;
	while (tmp[len + string_size] != '\0' && tmp[len + string_size] != delim)
		string_size++;
	result = ft_strndup(tmp + len, string_size);
	return (result);
}
