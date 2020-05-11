/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ggl_vector2_list_destructors.h                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 11:31:05 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/05 14:43:13 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GGL_VECTOR2_LIST_DESTRUCTORS_H
# define GGL_VECTOR2_LIST_DESTRUCTORS_H

void	destroy_t_vector2_list(t_vector2_list to_delete);
void	free_t_vector2_list(t_vector2_list *to_free);
void	t_vector2_list_clear(t_vector2_list *list);

#endif
