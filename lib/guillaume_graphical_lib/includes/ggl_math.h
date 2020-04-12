/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ggl_math.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:57:47 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/11 13:10:20 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GGL_MATH_H
# define GGL_MATH_H

float           degree_to_radian(float p_degree);
float           radian_to_degree(float p_radian);
t_vector2_list	calc_line(t_vector2 start, t_vector2 end);

#endif