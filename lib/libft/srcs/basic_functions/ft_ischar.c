/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ischar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 16:02:49 by gozsertt          #+#    #+#             */
/*   Updated: 2021/04/19 17:45:50 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ischar(const char *charset, int c)
{
	while (*charset)
	{
		if (*charset == c)
			return (true);
		charset++;
	}
	return (false);
}
