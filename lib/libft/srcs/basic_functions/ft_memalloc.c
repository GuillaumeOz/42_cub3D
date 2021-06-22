/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 17:24:30 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/17 20:03:44 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*ptr;

	ptr = NULL;
	if (size != 0)
	{
		ptr = (unsigned char *)malloc(sizeof(char) * size);
		if (ptr == NULL)
			ft_error("The malloc from ft_memalloc failed");
		ft_memset(ptr, 0, size);
	}
	else
		ft_error("The memalloc for malloc is egal to 0");
	return ((void *)ptr);
}
