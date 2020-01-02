/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 10:02:42 by gozsertt          #+#    #+#             */
/*   Updated: 2020/01/02 10:22:32 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int			convert_color(t_color color)
{
	uchar_	converter[4];

	color.b = converter[0];
	color.g = converter[1];
	color.r = converter[2];
	converter[3] = 255;

	return (*((int *)converter));
}
