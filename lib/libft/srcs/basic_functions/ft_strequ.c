/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:19:06 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/17 20:13:27 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_strequ(char const *s1, char const *s2)
{
	size_t	i;

	i = 0;
	if (s1 && s2)
	{
		while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
			i++;
		if (s1[i] == s2[i])
			return (true);
		else
			return (false);
	}
	else if (s1 || s2)
		return (false);
	else
		return (true);
}
