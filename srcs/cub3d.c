/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:19:11 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/22 12:28:30 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	quit(void *param)
{
	t_engine	*engine;

	engine = (t_engine *)param;
	free_engine(engine);
	printf("The game has been closed\n");
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_engine	*engine;

	engine = malloc_engine();
	parsing(engine, argc, argv);
	if (engine->bonus & RESOLUTION_BONUS)
		resize_application(engine->app,
			engine->resolution.x, engine->resolution.y);
	if (engine->bonus & SAVE_BONUS)
		save_bmp(engine);
	mlx_loop_hook(engine->app->mlx_ptr, &routine, engine);
	mlx_loop(engine->app->mlx_ptr);
	return (EXIT_SUCCESS);
}
