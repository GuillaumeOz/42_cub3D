/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ggl_get_leaks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 14:32:42 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/07 14:59:27 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

void	ggl_get_leaks(char *prog_name, char *msg)
{
	char	*command;
	char	*tmp;

	tmp = ggl_strdup("leaks ");
	command = ggl_strjoin(tmp, prog_name);
	free(tmp);
	tmp = command;
	command = ggl_strjoin(tmp, " | grep 'total leaked bytes'");
	free(tmp);
	system(command);
	ggl_putstr(msg);
	ggl_putchar('\n');
	ggl_putchar('\n');
	free(command);
}
