/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 10:54:50 by gozsertt          #+#    #+#             */
/*   Updated: 2019/12/30 15:03:54 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int main()
{
	t_application	*application;
	t_color			*color;

	application = malloc_application(400, 400, "test titre");
	color = malloc_color(255, 255, 255);

	clear_application(application, color);
	//put the event there
	//mlx_hook(application->win_ptr, ESC_KEY, int x_mask,
    //             int (*funct)(), void *param);
	//application is running there
	run_application(application);

	free_color(color);
	free_application(application);
 	//exit(); for leaving the windows
	//EXIT_FAILURE;
	//EXIT_SUCCESS;
	return (0);
}
