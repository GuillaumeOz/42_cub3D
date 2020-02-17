/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_parsing.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 19:33:03 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/17 19:38:31 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_PARSING_H
# define CUBE3D_PARSING_H

parse_map(t_game_engine *engine, int fd);
parse_game_engine(t_game_engine *engine, int fd, resolution);

void cube3d_parsing(t_game_engine *engine, char *map_name, t_vector2 *resolution);
#endif
