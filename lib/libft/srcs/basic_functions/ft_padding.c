/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 17:25:12 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/17 19:51:53 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_padding(int size, char c)
{
	char	*buffer;
	int		i;

	buffer = NULL;
	if (size > 0)
	{
		buffer = (char *)malloc(sizeof(char) * (size + 1));
		if (buffer == NULL)
			return (NULL);
		i = 0;
		while (i < size)
			buffer[i++] = c;
		buffer[i] = '\0';
	}
	return (buffer);
}
