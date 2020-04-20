/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_medikit.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 14:16:47 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/20 15:42:13 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_MEDIKIT_H
# define CUBE3D_MEDIKIT_H

typedef struct	s_medikit
{
	t_texture	tex;
	int			heal;
}				t_medikit;

t_medikit		create_medikit(char *p_tex, int p_heal);
void			destroy_medikit(t_medikit p_to_destroy);
#endif
