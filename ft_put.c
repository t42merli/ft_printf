/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 20:37:57 by tmerli            #+#    #+#             */
/*   Updated: 2017/12/27 16:44:19 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "ft_printf.h"

char	*ft_get_l(t_format p, long long num)
{
	if (ft_to_lower(p.type) == 'd')
		disp = ft_itoa((long)num, 10);
	if (ft_to_lower(p.type) == 'o')
		disp = ft_itoa_base((unsigned long)num, 8);
	if (ft_to_lower(p.type) == 'u')
		disp = ft_itoa_base((unsigned long)num, 10);
	if (ft_to_lower(p.type) == 'x')
	{
		disp = ft_itoa_base((unsigned long)num, 16);
		if (p.type == 'X')
			ft_to_upper_s(&disp);
	}
	return (disp);
}

char	*ft_get_h(t_format p, long long num)
{
	char *disp;

	if (p.type == 'd' || p.type == 'i')
		disp = ft_itoa((short)num, 10);
	if (p.type == 'x')
		disp = ft_itoa_base((unsigned short)num, 16);
	if (p.type == 'u')
		disp = ft_itoa_base((unsigned short)num, 10);
	if (p.type == 'o')
		disp = ft_itoa_base((unsigned short)num, 8);
	return (disp);
}

int		ft_put(va_list ap, t_format p)
{
	char *disp;
	long long num;

	if (is_num(p.type))
	{
		num = va_arg(ap, long long);
		if (ft_isupper(p.type) || p.length = 'l')
			ft_get_l(p, num);
		else if (p.length == 'h')
			ft_get_h(p, num);
		else if (p.length == 'H')
			ft_get_hh(p, num);
		else if (p.length == 'L')
			ft_get_ll(p, num);
	}
	
}
