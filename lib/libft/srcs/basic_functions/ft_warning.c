/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_warning.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:12:56 by gozsertt          #+#    #+#             */
/*   Updated: 2021/04/16 14:32:25 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_warning(char *warning_msg)
{
	ft_putstr("Warning : ");
	ft_putstr(warning_msg);
	write(1, "\n", 1);
}
