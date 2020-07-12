/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 12:23:54 by ytomiyos          #+#    #+#             */
/*   Updated: 2020/07/12 10:12:10 by ytomiyos         ###   ########.fr       */
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

static	void	ft_free(char **list)
{
	int		i;

	i = 0;
	while (list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
	return ;
}

static	char	*new_list(char *s, char c)
{
	int		len;
	char	*tmp;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (!(tmp))
		return (NULL);
	ft_strlcpy(tmp, s, len + 1);
	return (tmp);
}

char			**ft_split(char const *s, char c)
{
	int		i;
	int		elements_n;
	char	**result;

	i = 0;
	if (!s)
		return (NULL);
	elements_n = count_elements((char *)s, c);
	if (!(result = (char**)malloc(sizeof(char*) * (elements_n + 1))))
		return (NULL);
	result[elements_n] = NULL;
	while (i < elements_n)
	{
		while (*s == c)
			s++;
		if (!(result[i] = new_list((char *)s, c)))
		{
			ft_free(result);
			return (NULL);
		}
		s += ft_strlen(result[i]);
		i++;
	}
	return (result);
}
