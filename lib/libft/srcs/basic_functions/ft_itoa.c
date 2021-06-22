/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 17:54:42 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/17 20:27:19 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	set_negatif_info(char *output, int *n)
{
	output[0] = '-';
	(*n) *= (-1);
}

char	*ft_itoa(int n)
{
	char	*output;
	size_t	nb_len;

	if (n == -2147483648)
	{
		output = ft_strdup("-2147483648");
		return (output);
	}
	nb_len = (int)ft_intlen(n);
	if (n < 0)
		nb_len++;
	output = (char *)malloc(sizeof(char) * (nb_len + 1));
	if (output == NULL)
		return (NULL);
	if (n < 0)
		set_negatif_info(output, &n);
	else
		output[0] = '0';
	output[nb_len] = '\0';
	while (n != 0)
	{
		output[--nb_len] = (n % 10) + '0';
		n /= 10;
	}
	return (output);
}
