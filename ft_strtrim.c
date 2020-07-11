/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 21:26:58 by ytomiyos          #+#    #+#             */
/*   Updated: 2020/07/07 15:35:59 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		check_c(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	int		start_index;
	int		end_index;
	char	*ptr;

	start_index = 0;
	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	while (check_c((char *)set, s1[start_index]))
		start_index++;
	end_index = ft_strlen(s1) - 1;
	while (check_c((char *)set, s1[end_index]))
		end_index--;
	len = end_index - start_index + 1;
	if (len <= 0)
		return (ft_strdup(""));
	ptr = (char*)malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, &s1[start_index], len + 1);
	return (ptr);
}
