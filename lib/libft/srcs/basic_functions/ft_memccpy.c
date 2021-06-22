/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 14:44:54 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/17 20:17:03 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*d_dest;
	unsigned char	*s_src;
	size_t			i;
	bool			find_c;

	if ((n == 0) || (dest == src))
		return (NULL);
	d_dest = (unsigned char *)dest;
	s_src = (unsigned char *)src;
	i = 0;
	find_c = false;
	while (i < n)
	{
		d_dest[i] = s_src[i];
		if (d_dest[i] == (unsigned char)c)
		{
			find_c = true;
			break ;
		}
		i++;
	}
	if (find_c == true)
		return (d_dest + i + 1);
	else
		return (NULL);
}
