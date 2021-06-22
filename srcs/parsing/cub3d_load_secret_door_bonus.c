/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_load_secret_door_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 18:10:58 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/20 17:48:48 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_secret_door_bonus(t_engine *engine)
{
	if (engine->secret_door == NULL)
		cub3d_error(ERROR_PARSING40,
			"Secret door informations cannot be load");
}
