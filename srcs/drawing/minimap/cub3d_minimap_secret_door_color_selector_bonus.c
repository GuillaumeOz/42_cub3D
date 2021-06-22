/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_minimap_secret_door_color_selector_bo        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 14:32:39 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/19 17:18:38 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	minimap_secret_door_color_selector_bonus(t_color *color, char c)
{
	if (c == 'a')
		*color = create_color(250, 160, 0, 255);
	else if (c == 'b')
		*color = create_color(250, 150, 0, 255);
	else if (c == 'c')
		*color = create_color(250, 140, 0, 255);
	else if (c == 'd')
		*color = create_color(250, 130, 0, 255);
	else if (c == 'e')
		*color = create_color(250, 120, 0, 255);
	else if (c == 'f')
		*color = create_color(250, 110, 0, 255);
	else if (c == 'g')
		*color = create_color(250, 100, 0, 255);
	else if (c == 'h')
		*color = create_color(250, 90, 0, 255);
	else if (c == 'i')
		*color = create_color(250, 80, 0, 255);
	else if (c == 'j')
		*color = create_color(250, 70, 0, 255);
	else if (c == 'k')
		*color = create_color(250, 60, 0, 255);
}
