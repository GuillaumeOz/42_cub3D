/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ggl_vector2_list_behavior.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 12:14:06 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/05 14:58:15 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GGL_VECTOR2_LIST_BEHAVIOR_H
# define GGL_VECTOR2_LIST_BEHAVIOR_H

void		t_vector2tab_cpy(t_vector2 **old, t_vector2 **new_one);
size_t		t_vector2_list_calc_line(t_vector2_list *list, size_t index);
size_t		t_vector2_list_calc_elem(t_vector2_list *list, size_t index);
void		t_vector2_list_push_back(t_vector2_list *list, t_vector2 to_add);
t_vector2	t_vector2_list_at(t_vector2_list *list, size_t index);

#endif
