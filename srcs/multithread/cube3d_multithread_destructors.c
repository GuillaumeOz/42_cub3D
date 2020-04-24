/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_multithread_destructors.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 13:54:09 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/24 13:54:16 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void					destroy_multithread_struct(t_multithread_struct object)
{
	free_player(object.hero);
	free_map(object.map);
	free_vector2(object.lst);
}

void					free_multithread_struct(t_multithread_struct *object)
{
	destroy_multithread_struct(*object);
	free(object);
}
