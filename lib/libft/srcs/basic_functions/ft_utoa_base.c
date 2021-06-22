/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:38:58 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/17 19:57:46 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_uintlen_base(uintmax_t nb, int base)
{
	size_t	length;

	length = 1;
	while (nb >= (uintmax_t)base)
	{
		nb /= base;
		length++;
	}
	return (length);
}

char	*ft_utoa_base(uintmax_t nb, char *base)
{
	char	*format;
	int		baselen;
	int		size;

	size = ft_uintlen_base(nb, ft_strlen(base));
	format = (char *)ft_memalloc(sizeof(char) * (size + 1));
	if (format == NULL)
		return (NULL);
	ft_memset(format, '0', size);
	baselen = ft_strlen(base);
	while (size > 0)
	{
		format[--size] = base[nb % baselen];
		nb /= baselen;
	}
	return (format);
}
