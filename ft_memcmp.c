/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 23:38:06 by ytomiyos          #+#    #+#             */
/*   Updated: 2020/07/04 19:40:06 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if ((!str1 && !str2) || !n)
		return (0);
	while (n > 0)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
		n--;
	}
	return (0);
}
