/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 10:54:50 by gozsertt          #+#    #+#             */
/*   Updated: 2020/01/08 19:42:39 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int main()
{
	t_application	*application;
	t_color			*color;

	//allocate map struct
/*
	malloc_map_data
	open the .cub file
	stock all of the output inside a buff
	do all of the test
	do the parsing 
	And fill the structs like map struct...
	
*/


	
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
