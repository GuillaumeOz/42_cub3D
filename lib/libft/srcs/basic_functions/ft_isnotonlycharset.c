/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnotonlycharset.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:26:30 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/17 19:47:44 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_isnotonlycharset(const char *format, const char *charset)
{
	int	i;
	int	ascii[256];
	int	set_zero;

	i = -1;
	set_zero = 0;
	if (ft_strlen(format) < ft_strlen(charset))
		return (false);
	while (set_zero < 256)
		ascii[set_zero++] = 0;
	while (charset[++i])
		if (ascii[(int)charset[i]] == 0)
			ascii[(int)charset[i]] = 1;
	i = 0;
	while (format[i])
	{
		if (ascii[(int)format[i]] != 0)
			return (false);
		i++;
	}
	return (true);
}
