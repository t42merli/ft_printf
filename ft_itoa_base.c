/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 18:21:54 by tmerli            #+#    #+#             */
/*   Updated: 2017/12/27 18:49:04 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static intft_count(unsigned n)
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

char	*ft_itoa_base(unsigned long long n, base)
{
	char *nbr;
	char *base;

	base = "0123456789abcdef";

