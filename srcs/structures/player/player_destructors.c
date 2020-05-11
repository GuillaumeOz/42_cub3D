/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_destructors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 11:11:19 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/05 18:40:22 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		destroy_player(t_player to_destroy)
{
	(void)to_destroy;
}

void		free_player(t_player *to_free)
{
	destroy_player(*to_free);
	free(to_free);
}
