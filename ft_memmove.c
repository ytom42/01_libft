/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 23:43:41 by ytomiyos          #+#    #+#             */
/*   Updated: 2020/07/03 12:11:54 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	if (!d && !s)
		return (NULL);
	if (d < s)
		return (ft_memcpy(d, s, len));
	while (len > 0)
	{
		d[len - 1] = s[len - 1];
		len--;
	}
	return (dst);
}
