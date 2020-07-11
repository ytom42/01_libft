/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 07:53:59 by ytomiyos          #+#    #+#             */
/*   Updated: 2020/07/04 20:37:31 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_len(int n)
{
	int			len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	int		i;
	int		len;
	char	*ptr;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = count_len(n);
	if (!(ptr = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (n < 0)
	{
		n = -n;
		ptr[0] = '-';
		i = 1;
	}
	ptr[len] = '\0';
	while (len--)
	{
		ptr[len] = n % 10 + '0';
		n = n / 10;
		if (i == len)
			break ;
	}
	return (ptr);
}
