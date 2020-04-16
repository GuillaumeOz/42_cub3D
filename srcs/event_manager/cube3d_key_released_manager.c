/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_key_released_manager.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 15:58:28 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/16 16:39:50 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool    key_releaser()
{
    
}

int cube3d_key_release_manager(int key, void *param)
{
    int32_t	control;
	int		i;

	control = NOEVENTMASK;
	i = -1;
	key_loader(key, &control);
	while (g_cube3d_key_handler[++i].marker_control != NOCONTRL)
		if (control & g_cube3d_key_handler[i].marker_control)
			g_cube3d_key_handler[i].controler(control, param);
	return(control != NOEVENTMASK ? true : false);
}
