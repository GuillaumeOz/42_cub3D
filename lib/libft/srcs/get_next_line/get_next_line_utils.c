/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 12:40:03 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/19 15:24:09 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_gnl_vector	*gnl_vct_new(size_t size)
{
	t_gnl_vector	*vct;
	size_t			i;

	size += 1;
	vct = (t_gnl_vector *)malloc(sizeof(t_gnl_vector));
	if (vct == NULL)
		return (NULL);
	if (vct != NULL)
	{
		vct->size = size;
		vct->str = (char *)malloc(sizeof(char) * size);
		if (vct->str == NULL)
			return (NULL);
		vct->quart = size / 4;
		vct->len = 0;
	}
	i = 0;
	while (i < size)
	{
		vct->str[i] = '\0';
		i++;
	}
	return (vct);
}

bool	gnl_vct_extend(t_gnl_vector *vct, size_t expected_len)
{
	char	*tmp;
	size_t	i;

	if (vct == NULL || vct->size == 0)
		return (true);
	tmp = vct->str;
	while (vct->size <= expected_len)
	{
		vct->size *= 2;
		vct->quart *= 2;
	}
	vct->str = (char *)malloc((sizeof(char) * vct->size));
	if (vct->str == NULL)
		return (false);
	i = 0;
	while (i < vct->len)
	{
		vct->str[i] = tmp[i];
		i++;
	}
	free(tmp);
	tmp = NULL;
	return (true);
}

bool	gnl_vct_appnstr(t_gnl_vector *vct, char *addens, size_t n)
{
	unsigned long	i;
	size_t			expected_len;

	if (addens == NULL || vct == NULL || vct->str == NULL || n <= 0)
		return (true);
	i = 0;
	expected_len = vct->len + n;
	if (expected_len >= vct->size)
	{
		if (gnl_vct_extend(vct, expected_len) == false)
			return (false);
	}
	while (addens[i] && i < n)
	{
		vct->str[vct->len] = addens[i];
		vct->len++;
		i++;
	}
	vct->str[vct->len] = '\0';
	return (true);
}

bool	gnl_vct_cutnfrom(t_gnl_vector *vct, size_t idx, size_t n)
{
	size_t	i;
	size_t	j;

	if (vct == NULL || vct->str == NULL || idx >= vct->len)
		return (true);
	if (idx + n > vct->len)
		n = vct->len - idx;
	i = idx;
	j = idx + n;
	while (j < vct->size)
	{
		vct->str[i] = vct->str[j];
		i++;
		j++;
	}
	vct->len -= n;
	return (true);
}

int	gnl_strnchr_idx(char *s, char c, size_t n, int mode)
{
	size_t	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i] != c && i < n)
		i++;
	if (i == n)
	{
		if (c != '\0' && mode == 1)
			return (-1);
	}
	return (i);
}
