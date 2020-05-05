/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ggl_math.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:57:47 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/05 14:33:32 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GGL_MATH_H
# define GGL_MATH_H

float			degree_to_radian(float p_degree);
floa			radian_to_degree(float p_radian);
t_vector2_list	calc_line(t_vector2 start, t_vector2 end);
t_vector2		normalize_vector2(t_vector2 p_vector);
int				convert_2di_1di(t_vector2 pos, t_vector2 size);
float			convert_2d_1d(t_vector2 pos, t_vector2 size);

#endif
