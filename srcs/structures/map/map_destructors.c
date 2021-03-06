/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_destructors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 15:13:12 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/08 16:39:50 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	destroy_map(t_map to_destroy)
{
	int	i;

	i = -1;
	while (++i < to_destroy.size.y)
		free(to_destroy.board[i]);
	free(to_destroy.board);
}

void	free_map(t_map *to_free)
{
	destroy_map(*to_free);
	free(to_free);
}
