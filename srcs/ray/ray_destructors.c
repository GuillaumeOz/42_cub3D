/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_destructors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 19:18:35 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/14 19:52:53 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	destroy_ray(t_ray p_ray)
{
	(void)p_ray;
}

void	free_ray(t_ray *p_ray)
{
	destroy_ray(*p_ray);
	free(p_ray);
}
