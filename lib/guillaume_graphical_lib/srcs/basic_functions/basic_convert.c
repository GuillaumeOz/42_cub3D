/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 15:44:40 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/23 15:45:33 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

int		convert_2di_1di(t_vector2 pos, t_vector2 size)
{
	return ((int)(pos.x) + ((int)(pos.y) * (int)(size.x)));
}

float	convert_2d_1d(t_vector2 pos, t_vector2 size)
{
	return (pos.x + (pos.y * size.x));
}
