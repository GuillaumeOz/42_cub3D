/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 10:54:50 by gozsertt          #+#    #+#             */
/*   Updated: 2020/01/02 10:22:03 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int main()
{
	t_application	*application;
	t_color			*color;

	application = malloc_application(400, 400, "test titre");
	color = malloc_color(102, 51, 0);

	clear_application(application, color);
	//draw_ground()
	//put the event there
	//mlx_hook(application->win_ptr, ESC_KEY, int x_mask,
    //             int (*funct)(), void *param);
	//application is running there
	//render_application(application);
	render_application(application);
	run_application(application);

	free_color(color);
	free_application(application);
 	//exit(); for leaving the windows
	//EXIT_FAILURE;
	//EXIT_SUCCESS;
	return (0);
}
