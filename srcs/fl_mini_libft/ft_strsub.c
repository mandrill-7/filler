/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 14:17:49 by fchanal           #+#    #+#             */
/*   Updated: 2016/11/17 20:55:04 by fchanal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*fresh;
	const char	*init;

	if (!s || !(fresh = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	init = fresh;
	while (len--)
		*fresh++ = s[start++];
	*fresh = '\0';
	return (fresh - (fresh - init));
}
