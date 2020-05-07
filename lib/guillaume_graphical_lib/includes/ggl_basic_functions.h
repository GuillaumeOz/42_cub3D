/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ggl_basic_functions.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:47:56 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/07 14:55:00 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GGL_BASIC_FUNCTIONS_H
# define GGL_BASIC_FUNCTIONS_H

void	ggl_putchar(char c);
size_t	ggl_strlen(const char *str);
char	*ggl_strdup(const char *s);
void	ggl_putstr(const char *str);
void	ggl_get_leaks(char *prog_name, char *msg);
char	*ggl_strcat(char *s1, const char *s2);
char	*ggl_strnew(size_t size);
char	*ggl_strjoin(char const *s1, char const *s2);

#endif
