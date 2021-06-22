/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_constructor.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 21:04:13 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/19 15:54:16 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	malloc_root_gnl(t_gnl **rootp)
{
	*rootp = (t_gnl *)malloc(sizeof(t_gnl));
	if (*rootp == NULL)
		return (false);
	(*rootp)->vct = gnl_vct_new(VCT_DEFSIZE);
	if ((*rootp)->vct == NULL)
		return (false);
	return (true);
}

bool	malloc_next_gnl(t_gnl *head)
{
	head->next = (t_gnl *)malloc(sizeof(t_gnl));
	if (head->next == NULL)
		return (false);
	head->next->vct = gnl_vct_new(VCT_DEFSIZE);
	if (head->next->vct == NULL)
		return (false);
	return (true);
}

static char	*gnl_strndup(const char *src, int len)
{
	int		i;
	char	*ret;

	if (len <= 0)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * len + 1);
	if (ret == NULL)
		return (NULL);
	ret[len] = '\0';
	i = 0;
	while (i < len)
	{
		ret[i] = src[i];
		i++;
	}
	return (ret);
}

int	create_gnl_content(t_gnl *head, char **line, int fd, int *i)
{
	char	buf[GNL_BUFFER_SIZE];
	int		ret;

	while (gnl_strnchr_idx(head->vct->str, '\n', head->vct->len, 1) == -1)
	{
		ret = read(fd, buf, GNL_BUFFER_SIZE);
		if (ret <= 0)
			break ;
		gnl_vct_appnstr(head->vct, &(*buf), ret);
	}
	ret = read(fd, buf, GNL_BUFFER_SIZE);
	if (ret != -1 && ret != -2)
		gnl_vct_appnstr(head->vct, buf, ret);
	*i = gnl_strnchr_idx(head->vct->str, '\n', head->vct->len, 2);
	if (*i == 0)
		*line = gnl_strndup("", 1);
	else
		*line = gnl_strndup(head->vct->str, *i);
	return (ret);
}
