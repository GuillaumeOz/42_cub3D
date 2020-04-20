/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medikit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 14:21:16 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/20 14:25:50 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_medikit	create_medikit(char *p_tex, int p_heal)
{
	t_medikit	result;

	result.tex = create_texture(p_tex);
	result.heal = p_heal;
	return (result);
}

void		destroy_medikit(t_medikit p_to_destroy)
{
	destroy_texture(p_to_destroy.tex);
}
