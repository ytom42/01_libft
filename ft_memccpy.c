/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 23:21:27 by ytomiyos          #+#    #+#             */
/*   Updated: 2020/07/06 09:43:56 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, \
		int c, size_t n)
{
	int				i;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	i = 0;
	if (!dst && !src)
		return (NULL);
	while (n > 0)
	{
		d[i] = s[i];
		if (s[i] == (unsigned char)c)
			return (d + i + 1);
		i++;
		n--;
	}
	return (NULL);
}
