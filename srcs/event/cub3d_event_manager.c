/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_event_manager.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:22:14 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/21 22:15:38 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	event_manager(t_engine *engine)
{
	application_control(&key_release, KEYRELEASE,
		KEYRELEASEMASK, (void*)engine);
	application_control(&key_press, KEYPRESS,
		KEYPRESSMASK, (void*)engine);
	application_exit_control(&quit, DESTROYCROSSNOTIFY,
		DESTROYNOTIFY, (void*)engine);
}
