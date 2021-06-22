/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 19:58:11 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/17 20:07:24 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intlen(intmax_t n)
{
	intmax_t	num;
	size_t		length;

	length = 1;
	if (n < 0)
		num = n * (-1);
	else
		num = n;
	while (num >= 10)
	{
		num /= 10;
		length++;
	}
	return (length);
}
