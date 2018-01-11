/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getlength.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 21:35:26 by tmerli            #+#    #+#             */
/*   Updated: 2018/01/09 17:41:01 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_l(t_format p, long long num)
{
	char *disp;

	if (ft_tolower(p.type) == 'd' || p.type == 'i')
		disp = ft_itoa((long)num);
	if (ft_tolower(p.type) == 'o')
		disp = ft_itoa_base((unsigned long)num, 8);
	if (ft_tolower(p.type) == 'u')
		disp = ft_itoa_base((unsigned long)num, 10);
	if (ft_tolower(p.type) == 'x')
		disp = ft_itoa_base((unsigned long)num, 16);
	if (p.type == 'X')
		ft_toupper_s(&disp);
	return (disp);
}

char	*ft_get_h(t_format p, long long num)
{
	char *disp;

	if (p.type == 'd' || p.type == 'i')
		disp = ft_itoa((short)num);
	if (ft_tolower(p.type) == 'x')
		disp = ft_itoa_base((unsigned short)num, 16);
	if (p.type == 'u')
		disp = ft_itoa_base((unsigned short)num, 10);
	if (p.type == 'o')
		disp = ft_itoa_base((unsigned short)num, 8);
	if (p.type == 'X')
		ft_toupper_s(&disp);
	return (disp);
}

char	*ft_get_hh(t_format p, long long num)
{
	char *disp;

	if (p.type == 'd' || p.type == 'i')
		disp = ft_itoa((char)num);
	if (ft_tolower(p.type) == 'x')
		disp = ft_itoa_base((unsigned char)num, 16);
	if (p.type == 'u')
		disp = ft_itoa_base((unsigned char)num, 10);
	if (p.type == 'o')
		disp = ft_itoa_base((unsigned char)num, 8);
	if (p.type == 'X')
		ft_toupper_s(&disp);
	return (disp);
}

char	*ft_get_ll(t_format p, long long num)
{
	char *disp;

	if (p.type == 'd' || p.type == 'i')
		disp = ft_itoa((long long)num);
	if (ft_tolower(p.type) == 'x' || p.type == 'p')
		disp = ft_itoa_base((unsigned long long)num, 16);
	if (p.type == 'u')
		disp = ft_itoa_base((unsigned long long)num, 10);
	if (p.type == 'o')
		disp = ft_itoa_base((unsigned long long)num, 8);
	if (p.type == 'X')
		ft_toupper_s(&disp);
	return (disp);
}

char	*ft_get_d(t_format p, long long num)
{
	char *disp;

	if (p.type == 'd' || p.type == 'i')
		disp = ft_itoa((int)num);
	if (ft_tolower(p.type) == 'x' || p.type == 'p')
		disp = ft_itoa_base((unsigned int)num, 16);
	if (p.type == 'u')
		disp = ft_itoa_base((unsigned int)num, 10);
	if (p.type == 'o')
		disp = ft_itoa_base((unsigned int)num, 8);
	if (p.type == 'X')
		ft_toupper_s(&disp);
	return (disp);
}
