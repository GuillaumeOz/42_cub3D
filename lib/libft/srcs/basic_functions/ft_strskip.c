/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strskip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 18:32:08 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/17 20:11:28 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strskip(char *str, char to_skip)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] == to_skip)
		i++;
	return (i);
}
