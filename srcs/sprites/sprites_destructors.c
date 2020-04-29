/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_destructors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 20:22:54 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/29 11:23:59 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void			destroy_sprites(t_sprites sprites)
{
	(void)sprites;
}

void			free_sprites(t_sprites *sprites)
{
	destroy_sprites(*sprites);
	free(sprites);
}

void			clear_sprites(t_sprites **sprites)
{
	t_sprites *lst;

	if (*sprites == NULL)
		return ;
	while (*sprites)
	{
		lst = *sprites;
		*sprites = lst->next;
		free(lst);
	}
	lst = NULL;
	sprites = NULL;
}
