/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 12:38:46 by gozsertt          #+#    #+#             */
/*   Updated: 2019/12/30 12:58:52 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_color		create_color(uchar_ r, uchar_ g, uchar_ b)
{
	t_color	result;

	result.r = r;
	result.g = g;
	result.b = b;
	return (result);
}

t_color		*malloc_color(uchar_ r, uchar_ g, uchar_ b)
{
	t_color	*color;

	color = (t_color*)malloc(sizeof(t_color));
	if (color == NULL)
		return (NULL);
	*color = create_color(r, g, b);
	return (color);
}

void		destroy_color(t_color to_destroy)
{
	(void)to_destroy;
}

void		free_color(t_color *to_free)
{
	destroy_color(*to_free);
	free(to_free);
}

int			convert_color(t_color color)
{
	uchar_	converter[4];

	color.b = converter[0];
	color.g = converter[1];
	color.r = converter[2];
	converter[3] = 0;

	return (*((int *)converter));
}
