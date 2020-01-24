/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 10:38:49 by gozsertt          #+#    #+#             */
/*   Updated: 2020/01/24 12:58:15 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	parse_resolution(t_vector **resolution_size, char *format)
{
	format++;
	while (*format == ' ')
		format++;
	(*resolution_size)->x = ft_atoi(format);
	while (*format != ' ')
		format++;
	while (*format == ' ')
		format++;
	(*resolution_size)->y = ft_atoi(format);
}

void	parse_texture(char **texture, char *format)
{
	char	*tmp;
	int		i;

	i = 0;
	while (*format != ' ')
		format++;
	while (*format == ' ')
		format++;
	while (format[i] != ' ')
		i++;
	tmp = ft_strndup(format, i);
	if (tmp == NULL)
		catch_error("Malloc_parser error 1");	
	(*texture) = ft_strjoinfre((*texture), tmp, 1, 1);
	if ((*texture) == NULL)
		catch_error("Malloc_parser error 2");
}

void	parse_environment(t_color **environment, char *format)
{
	while (*format != ' ')
		format++;
	while (*format == ' ')
		format++;
	(*environment)->r = ft_atoi(format);
	while (*format != ',')
		format++;
	format++;
	(*environment)->g = ft_atoi(format);
	while (*format != ',')
		format++;
	format++;
	(*environment)->b = ft_atoi(format);
}
