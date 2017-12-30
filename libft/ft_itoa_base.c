/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 18:21:54 by tmerli            #+#    #+#             */
/*   Updated: 2017/12/29 17:03:38 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(unsigned long long n, int base)
{
	int i;

	i = 0;
	while (n > 0)
	{
		n = n / base;
		i++;
	}
	return (i - 1);
}

char		*ft_itoa_base(unsigned long long n, int base)
{
	char	*nbr;
	char	*bs;
	int		i;
	int		tmp;

	if (n == 0)
	{
		if (!(nbr = ft_strnew(1)))
			return (NULL);
		nbr[0] = '0';
		return (nbr);
	}
	bs = "0123456789abcdef";
	tmp = ft_count(n, base);
	if (!(nbr = ft_strnew(tmp)))
		return (NULL);
	i = tmp;
	while (i >= 0)
	{
		nbr[i] = bs[n % base];
		n = n / base;
		i--;
	}
//	nbr[tmp + 1] = '\0';
	return (nbr);
}
