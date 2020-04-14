/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_constructors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 20:21:28 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/14 20:22:40 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_sprites		create_sprites(t_ray p_ray, t_vector2 p_pos, char p_type)
{
	t_sprites result;

	result.ray = p_ray;
	result.pos = p_pos;
	result.type = p_type;
	return (result);
}

t_sprites		*malloc_sprites(t_ray p_ray, t_vector2 p_pos, char p_type)
{
	t_sprites *result;

	result = (t_sprites*)malloc(sizeof(t_sprites));
	if (result == NULL)
		catch_error(MALLOC_SPRITES_1);
	*result = create_sprites(p_ray, p_pos, p_type);
	return (result);
}
