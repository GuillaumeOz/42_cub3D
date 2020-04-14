/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ggl_tex_tab.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 15:15:33 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/13 16:48:45 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GGL_TEX_TAB_H
# define GGL_TEX_TAB_H

int		**malloc_tex_tab(t_image *image);
int		*create_tex_tab(t_image *image);
void	destroy_tex_tab(int	**to_destroy);
void	free_tax_tab(t_image *to_free);
void	put_tex_pix(t_image *image, t_vector2 pos, t_color tex_pix);

#endif