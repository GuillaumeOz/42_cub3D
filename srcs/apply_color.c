/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 10:02:42 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/04 11:36:46 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int			convert_color(t_color color)
{
// 	uchar_	converter[4];
	int		converter;

	converter = 0;
	converter |= color.b << 24;
	converter |= color.g << 16;
	converter |= color.r << 8;
	converter |= color.t;
	return (converter);
	// color.b = converter[0];
	// color.g = converter[1];
	// color.r = converter[2];
	// color.t = converter[3];


	// return (*((int *)converter));
}
