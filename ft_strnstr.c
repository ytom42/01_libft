/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 21:49:55 by ytomiyos          #+#    #+#             */
/*   Updated: 2020/07/06 09:51:11 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *need, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (need[0] == '\0')
		return ((char *)hay);
	while (hay[i] && (len > i))
	{
		while (hay[i + j] == need[j] && need[j] && (i + j < len))
			j++;
		if (need[j] == '\0')
			return ((char *)&hay[i]);
		j = 0;
		i++;
	}
	return (NULL);
}
