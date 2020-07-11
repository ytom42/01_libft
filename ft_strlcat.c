/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 14:26:15 by ytomiyos          #+#    #+#             */
/*   Updated: 2020/07/06 09:45:00 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, \
size_t dstsize)
{
	size_t		i;
	size_t		n;
	size_t		dst_size;
	size_t		src_size;

	i = 0;
	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	n = dstsize - dst_size;
	if (dst_size >= dstsize)
		return (dstsize + src_size);
	while (src[i] && (n - 1) > 0)
	{
		dst[dst_size + i] = src[i];
		i++;
		n--;
	}
	dst[dst_size + i] = '\0';
	return (dst_size + src_size);
}
