/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2_normalize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 17:12:11 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/14 17:13:46 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

t_vector2	normalize_vector2(t_vector2 p_vector)
{
	float	norme;

	norme = sqrt(pow(p_vector.x, 2) + pow(p_vector.y, 2));
	p_vector.x /= norme;
	p_vector.y /= norme;
	return (p_vector);
}
