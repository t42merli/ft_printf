/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 20:37:57 by tmerli            #+#    #+#             */
/*   Updated: 2017/12/30 14:21:30 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "ft_printf.h"

int		ft_put(va_list ap, t_format p)
{
	char *disp;
	long long num;

	disp = NULL;
	num = 1;
	if (p.type == 'd' || p.type == 'D' || p.type == 'x' || p.type == 'X'
			|| p.type == 'o' || p.type == 'O' || p.type == 'u' || p.type == 'U'
			|| p.type == 'i' || p.type == 'p')
	{
		num = va_arg(ap, long long);
		if (p.length == 0)
			disp = ft_get_d(p, num);
		if ((ft_isupper(p.type) && p.type != 'X') || p.length == 'l')
			disp = ft_get_l(p, num);
		else if (p.length == 'h')
			disp = ft_get_h(p, num);
		else if (p.length == 'H')
			disp = ft_get_hh(p, num);
		else if (p.length == 'L' || p.type == 'p' || p.length == 'j' || p.length == 'z')
			disp = ft_get_ll(p, num);
		num = ft_flags(p, disp);
	}
	else if (ft_tolower(p.type) == 's')
		return(ft_putstr(va_arg(ap, char*)));
	else if (ft_tolower(p.type) == 'c')
		ft_putchar((char)va_arg(ap, int));
	else if (p.type == '%')
		ft_putchar('%');
	return (num);
}
