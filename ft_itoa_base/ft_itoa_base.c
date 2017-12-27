/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 13:36:55 by exam              #+#    #+#             */
/*   Updated: 2017/12/27 16:44:14 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa_base(unsigned int nb2, int base)
{
	char *nbr;
	long nb = nb2;
	int i = 0;
	long tmp = nb;
	char *bs = "0123456789ABCDEF";

	if (nb == 0)
	{
		nbr = (char*)malloc(sizeof(char) * 2);
		nbr[0] = '0';
		nbr[1] = '\0';
		return (nbr);
	}
	if (nb < 0 && base == 10)
	{
		tmp = tmp * - 1;
		i++;
	}
	else if (nb < 0)
	{
		tmp = tmp * - 1;
		nb = nb * - 1;
	}
	while (tmp > 0)
	{
		tmp = tmp / base;
		i++;
	}
	nbr = (char*)malloc(sizeof(char) * i + 1);
	if (nb < 0 && base == 10)
	{
		nbr[0] = '-';
		nb = nb * - 1;
	}
	tmp = i;
	i--;
	while (nb > 0)
	{
		nbr[i] = bs[nb % base];
		nb = nb / base;
		i--;
	}
	nbr[tmp] = '\0';
	return (nbr);
}
