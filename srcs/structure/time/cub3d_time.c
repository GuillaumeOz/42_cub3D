/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 11:14:03 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/20 15:38:09 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_time	*malloc_time(void)
{
	t_time	*time;

	time = (t_time *)malloc(sizeof(t_time));
	if (time == NULL)
		cub3d_error(ERROR_TIME1, "A t_time can't be malloc");
	*time = create_time();
	return (time);
}

t_time	create_time(void)
{
	t_time	time;

	time.oldTime = 0;
	time.time = 0;
	return (time);
}

void	destroy_time(t_time time)
{
	time.oldTime = 0;
	time.time = 0;
	(void)time;
}

void	free_time(t_time *time)
{
	destroy_time(*time);
	free(time);
}
