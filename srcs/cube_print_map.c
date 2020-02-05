/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_print_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 16:07:02 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/05 19:37:38 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	cube_print_map(t_config *config, t_application *application)
{
	t_vector	square_pos;
	int			i;
	int			j;

	i = -1;
	j = -1;
	square_pos = create_vector(0.0, 0.0);
	while (config->map[++i] != NULL)
	{
		while (config->map[i][++j])
			if (config->map[i][j] == '1')
			{
				draw_rectangle(config, application, square_pos);
				square_pos.x += config->proportionality->x;
			}
			else
				square_pos.x += config->proportionality->x;
		j = -1;
		square_pos.x = 0.0;
		square_pos.y += config->proportionality->y;
	}
}
