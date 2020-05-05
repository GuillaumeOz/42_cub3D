/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 12:41:59 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/05 14:30:04 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

float	degree_to_radian(float p_degree)
{
	return (p_degree * M_PI / 180);
}

float	radian_to_degree(float p_radian)
{
	return (p_radian * 180 / M_PI);
}
