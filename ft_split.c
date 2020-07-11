/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 12:23:54 by ytomiyos          #+#    #+#             */
/*   Updated: 2020/07/11 18:57:40 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		count_elements(char *str, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i] == c && str[i])
		i++;
	while (str[i])
	{
		count++;
		while (str[i] != c && str[i])
			i++;
		while (str[i] == c && str[i])
			i++;
	}
	return (count);
}

static	int		ft_free(char **list, int n)
{
	int		i;

	i = 0;
	while (list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
	return (n);
}

char			**ft_split(char const *s, char c)
{
	int		i;
	int		len;
	int		elements_n;
	char	**result;

	i = 0;
	if (*s == '\0')
		return (NULL);
	elements_n = count_elements((char *)s, c);
	if (!(result = (char**)malloc(sizeof(char*) * (elements_n + 1))))
		return (NULL);
	result[elements_n] = NULL;
	while (i < elements_n)
	{
		len = 0;
		while (*s == c)
			s++;
		while (s[len] != c)
			len++;
		if (!(result[i] = ft_substr(s, 0, len)))
			i = ft_free(result, elements_n);
		s += len;
		i++;
	}
	return (result);
}
