/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_time_setter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 11:16:56 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/20 15:37:22 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_old_time(t_time *time)
{
	time->oldTime = time->time;
}

void	set_current_time(t_time *time)
{
	struct timeval	get_time;
	int				state;

	state = gettimeofday(&get_time, NULL);
	if (state == -1)
		cub3d_error(ERROR_TIME2, "Current time cannot be set");
	time->time = (get_time.tv_sec * 1000)
		+ (get_time.tv_usec / 1000);
}
