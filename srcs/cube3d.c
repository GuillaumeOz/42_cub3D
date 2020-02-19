/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:25:29 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/19 19:36:10 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int main(int argc, char **argv)
{
	t_game_engine	engine;
	t_vector2		resolution;

	if (argc != 2)
		catch_error(MAIN_1);
	start_application(600, 600, "Cube3D");
	engine = create_game_engine();
	cube3d_parsing(&engine, argv[1], &resolution);
	return (0);
}
