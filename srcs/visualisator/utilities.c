/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 19:14:55 by fchanal           #+#    #+#             */
/*   Updated: 2017/06/16 19:16:29 by fchanal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int64_t		ft_get(const char **s)
{
	size_t	n;
	bool	sign;

	while (**s == ' ')
		++*s;
	sign = (**s == '-');
	if (**s == '+' || **s == '-')
		++*s;
	n = (ft_isdigit(**s)) ? (*(*s)++ - 48) : 0;
	while (ft_isdigit(**s))
		n = (n * 10) + *(*s)++ - 48;
	return (sign ? -n : n);
}

void		visu_img_put(char *str, int s_l, t_coord pos, int color)
{
	str += (pos.y * (s_l * 4)) + pos.x * 4;
	*(int *)str = color;
}

int			visu_get_img_color(const char *str, int s_l, int x, int y)
{
	str += (y * (s_l * 4)) + x * 4;
	return (*(int *)str);
}
