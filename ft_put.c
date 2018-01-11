/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 20:37:57 by tmerli            #+#    #+#             */
/*   Updated: 2018/01/09 18:04:25 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putc(va_list ap, t_format p)
{
	char	c;
	char	space;
	int		printed;

	printed = 0;
	space = (p.flags[3] && !p.flags[0]) ? '0' : ' ';
	c = (char)va_arg(ap, int);
	if (p.min > 1 && !p.flags[0])
	{
		while (printed < p.min - 1)
			printed += write(1, &space, 1);
	}
	printed += write(1, &c, 1);
	if (p.min > 1 && p.flags[0])
	{
		while (printed < p.min)
			printed += write(1, &space, 1);
	}
	return (printed);
}

int		ft_putpc(t_format p)
{
	char	c;
	char	space;
	int		printed;

	printed = 0;
	space = (p.flags[3] && !p.flags[0]) ? '0' : ' ';
	c = '%';
	if (p.min > 1 && !p.flags[0])
	{
		while (printed < p.min - 1)
			printed += write(1, &space, 1);
	}
	printed += write(1, &c, 1);
	if (p.min > 1 && p.flags[0])
	{
		while (printed < p.min)
			printed += write(1, &space, 1);
	}
	return (printed);
}

int		ft_puts(va_list ap, t_format p)
{
	char	*s;
	char	space;
	int		printed;
	int		len;

	printed = 0;
	space = (p.flags[3] && !p.flags[0]) ? '0' : ' ';
	s = va_arg(ap, char *);
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	len = (p.precision && p.precision < len) ? p.precision : len;
	len = (len < 0) ? 0 : len;
	if (p.min > len && !p.flags[0])
	{
		while (printed < p.min - len)
			printed += write(1, &space, 1);
	}
	printed += (p.precision) ? ft_putnstr(s, p.precision) : ft_putstr(s);
	if (p.min > len && p.flags[0])
	{
		while (printed < p.min)
			printed += write(1, &space, 1);
	}
	return (printed);
}

int		ft_putnb(va_list ap, t_format p)
{
	char		*disp;
	long long	num;

	disp = NULL;
	num = va_arg(ap, long long);
	if (p.length == 0 && p.type != 'p')
		disp = ft_get_d(p, num);
	if (((ft_isupper(p.type) && p.type != 'X') || p.length == 'l') &&
			p.type != 'p')
		disp = ft_get_l(p, num);
	else if (p.length == 'h' && p.type != 'p')
		disp = ft_get_h(p, num);
	else if (p.length == 'H' && p.type != 'p')
		disp = ft_get_hh(p, num);
	else if (p.length == 'L' || p.type == 'p' || p.length == 'j'
			|| p.length == 'z')
		disp = ft_get_ll(p, num);
	num = ft_flags(p, disp);
	if (disp)
		free(disp);
	return (num);
}

int		ft_put(va_list ap, t_format p)
{
	if (p.type == 'd' || p.type == 'D' || p.type == 'x' || p.type == 'X'
			|| p.type == 'o' || p.type == 'O' || p.type == 'u' || p.type == 'U'
			|| p.type == 'i' || p.type == 'p')
		return (ft_putnb(ap, p));
	else if (p.type == 'c' || p.type == 'C')
		return (ft_putc(ap, p));
	else if (p.type == 's' || p.type == 'S')
		return (ft_puts(ap, p));
	else if (p.type == '%')
		return (ft_putpc(p));
	else
		return (ft_putelse(p.type, p));
}
