/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_set_sprite_screen_x.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:58:51 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/19 17:30:15 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_sprite_screen_x(t_sprite_calc *sprite_calc, t_engine *engine)
{
	sprite_calc->sprite_screen_x = (int)((engine->resolution.x / 2)
			* (1 + sprite_calc->inv_transform.x
				/ sprite_calc->inv_transform.y));
}
