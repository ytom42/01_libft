/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 12:23:54 by ytomiyos          #+#    #+#             */
/*   Updated: 2020/07/11 16:23:54 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static	int		count_elements(char *str, char c)
// {
// 	int		i;
// 	int		count;

// 	i = 0;
// 	count = 0;
// 	if (str[i] != c)
// 		count++;
// 	i = 1;
// 	while (str[i])
// 	{
// 		if (str[i - 1] == c && str[i] != c)
// 			count++;
// 		i++;
// 	}
// 	return (count);
// }

// static	int		ft_free(char **list, int n)
// {
// 	int		i;

// 	i = 0;
// 	while (list[i])
// 	{
// 		free(list[i]);
// 		i++;
// 	}
// 	free(list);
// 	return (n);
// }

// char			**ft_split(char const *s, char c)
// {
// 	int		i;
// 	int		len;
// 	int		elements_n;
// 	char	**result;

// 	i = 0;
// 	if (*s == '\0')
// 		return (NULL);
// 	elements_n = count_elements((char *)s, c);
// 	if (!(result = (char**)malloc(sizeof(char*) * elements_n + 1)))
// 		return (NULL);
// 	result[elements_n] = NULL;
// 	while (i < elements_n)
// 	{
// 		len = 0;
// 		while (s[0] == c)
// 			s++;
// 		while (s[len] != c)
// 			len++;
// 		if (!(result[i] = ft_substr(s, 0, len)))
// 			i = ft_free(result, elements_n);
// 		s += len;
// 		i++;
// 	}
// 	return (result);
// }

static int		ft_count_words(char const *s, char c)
{
	int i;
	int words;
	int hasword;

	i = 0;
	words = 0;
	hasword = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		if (s[i] != c && s[i])
			hasword = 1;
		if (s[i] == c)
		{
			while (s[i] == c && s[i])
				i++;
			if (s[i])
				words++;
		}
		else
			i++;
	}
	return (words + hasword);
}

static	char	*ft_alloc_word(char const *s, char c)
{
	int		size;
	char	*tab;

	size = 0;
	tab = 0;
	while (s[size] && s[size] != c)
		size++;
	if (!(tab = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_strlcpy(tab, s, size + 1);
	return (tab);
}

char			**ft_split(char const *s, char c)
{
	int		count;
	int		words;
	char	**tab;

	count = -1;
	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	if (!(tab = malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	while (++count < words)
	{
		while (s[0] == c)
			s++;
		if (!(tab[count] = ft_alloc_word(s, c)))
		{
			while (count > 0)
				free(tab[count--]);
			free(tab);
			return (NULL);
		}
		s += ft_strlen(tab[count]);
	}
	tab[count] = 0;
	return (tab);
}