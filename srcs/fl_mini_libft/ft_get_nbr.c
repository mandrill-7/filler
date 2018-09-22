/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 01:49:22 by fchanal           #+#    #+#             */
/*   Updated: 2017/04/02 01:49:55 by fchanal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint64_t		ft_get_nbr(const char **s)
{
	size_t	n;

	while (**s == ' ')
		++*s;
	n = (ft_isdigit(**s)) ? (*(*s)++ - 48) : 0;
	while (ft_isdigit(**s))
		n = (n * 10) + *(*s)++ - 48;
	return (n);
}
