/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 15:41:14 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/19 15:47:06 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_gnl	*fdselect(t_gnl **rootp, int fd)
{
	t_gnl				*head;

	if (*rootp == NULL)
	{
		if (malloc_root_gnl(rootp) == false)
			return (NULL);
		(*rootp)->next = NULL;
		return (*rootp);
	}
	head = *rootp;
	while (head)
	{
		if (head->fd == fd)
			return (head);
		if (head->next == NULL)
			break ;
		head = head->next;
	}
	if (malloc_next_gnl(head) == false)
		return (NULL);
	head->next->next = NULL;
	return (head->next);
}

void	gnl_freenode(t_gnl **rootp, int fd, t_gnl *head)
{
	t_gnl				*prev;

	head = *rootp;
	if ((*rootp)->fd == fd)
	{
		*rootp = (*rootp)->next;
		free(head->vct->str);
		free(head->vct);
		free(head);
		return ;
	}
	while (head)
	{
		if (head->fd == fd)
		{
			prev->next = head->next;
			free(head->vct->str);
			free(head->vct);
			free(head);
			break ;
		}
		prev = head;
		head = head->next;
	}
}

int	get_next_line(int fd, char **line)
{
	static t_gnl	*root;
	t_gnl			*head;
	int				ret;
	int				i;

	head = fdselect(&root, fd);
	if (!line || fd < 0 || head == NULL || read(fd, 0, 0) < 0)
		return (-1);
	head->fd = fd;
	ret = create_gnl_content(head, line, fd, &i);
	if (ret != -1)
	{
		if (head->vct->str[i] == '\n')
			ret = 1;
		else
			ret = 0;
	}
	gnl_vct_cutnfrom(head->vct, 0, i + 1);
	if (head->vct->len == 0)
		gnl_freenode(&root, head->fd, head);
	return (ret);
}
