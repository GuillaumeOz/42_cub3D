/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ggl_strnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 14:53:48 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/07 19:51:15 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

char	*ggl_strnew(size_t size)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * size + 1);
	if (str == NULL)
		ggl_error("The malloc from ft_malloc failed");
	str[size] = '\0';
	return (str);
}
