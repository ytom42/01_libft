/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 09:57:29 by ytomiyos          #+#    #+#             */
/*   Updated: 2020/07/06 09:45:15 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int		i;
	int		src_size;

	i = 0;
	if (!dst)
		return (0);
	src_size = ft_strlen(src);
	if (dstsize == 0)
		return (src_size);
	while (src[i] && (dstsize - 1) > 0)
	{
		dst[i] = src[i];
		i++;
		dstsize--;
	}
	dst[i] = '\0';
	return (src_size);
}
