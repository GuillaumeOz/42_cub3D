/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 10:54:50 by gozsertt          #+#    #+#             */
/*   Updated: 2020/01/29 16:56:48 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int main(int argc, char **argv)
{
	t_config		*data;
	t_application	*application;
	t_color			*color;
	int				fd;

	if (argc != 2)
		catch_error("Main error 1");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		catch_error("Main error 2");
	data = cube_formatter("Cube3D", fd);
	application = malloc_application(400, 400, data->title);
	color = malloc_color(102, 51, 0);
	render_application(application);
	run_application(application);
//allocate map struct
/*
	malloc_map_data
	open the .cub file
	stock all of the output inside a buff
	do all of the test
	do the parsing 
	And fill the structs like map struct...
	DONE
*/

	// free_application(application);
	// free_map_data(data);

	// clear_application(application, color);


	//draw_ground()
	//put the event there
	//mlx_hook(application->win_ptr, ESC_KEY, int x_mask,
    //             int (*funct)(), void *param);
	//application is running there
	//render_application(application);


	// free_color(color); XX
	// free_application(application); XX


 	//exit(); for leaving the windows
	//EXIT_FAILURE;
	//EXIT_SUCCESS;
	return (0);
}
