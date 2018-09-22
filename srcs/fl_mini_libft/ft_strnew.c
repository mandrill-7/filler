/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 09:30:47 by fchanal           #+#    #+#             */
/*   Updated: 2016/11/17 21:28:19 by fchanal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char		*s;
	const char	*init;

	if (!(s = (char *)malloc(sizeof(char) * ++size)))
		return (NULL);
	init = s;
	while (size--)
		*s++ = '\0';
	return ((char*)init);
}
