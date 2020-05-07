/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ggl_strjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 14:47:01 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/07 15:01:12 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

char	*ggl_strjoin(char const *s1, char const *s2)
{
	char *new_str;

	if (s1 || s2)
	{
		if (!s2)
			return (ggl_strdup((char *)s1));
		if (!s1)
			return (ggl_strdup((char *)s2));
		if (!(new_str = ggl_strnew(ggl_strlen(s1) + ggl_strlen(s2) + 1)))
			return (NULL);
		return (ggl_strcat(ggl_strcat(new_str, s1), s2));
	}
	return (NULL);
}
