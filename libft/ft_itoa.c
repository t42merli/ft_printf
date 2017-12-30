/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:43:35 by tmerli            #+#    #+#             */
/*   Updated: 2017/12/29 21:08:46 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_count(unsigned long long n)
{
	int i;

	i = 1;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(long long n)
{
	char		*str;
	int			i;
	int			j;
	unsigned long long	nb;

	nb = n;
	i = 0;
	if (!(str = ft_strnew(i)))
		return (NULL);
	j = 0;
	if (n < 0)
	{
		str[j++] = '-';
		nb = n * -1;
	}
	else if (n > 0)
		i--;
	i += ft_count(nb);
	while (i > j)
	{
		str[i-- - 1] = (char)((nb % 10) + 48);
		nb = nb / 10;
	}
	return (str);
}
