/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_application.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 15:06:58 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/10 14:54:29 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int             event_gen(int keycode)
{
	if (keycode == ESC_KEY)
		exit(0);
    	//mlx_destroy_window(application->mlx_ptr, application->win_ptr);
	return (53);
}
