/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 13:08:56 by ytomiyos          #+#    #+#             */
/*   Updated: 2020/07/03 14:14:32 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ptr = (char*)malloc(sizeof(char) * (s1_len + s2_len) + 1);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s1, s1_len);
	ft_strlcpy((ptr + s1_len), s2, (s2_len + 1));
	return (ptr);
}
