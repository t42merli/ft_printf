/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 13:46:35 by tmerli            #+#    #+#             */
/*   Updated: 2017/12/29 23:57:11 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		put_0x(t_format p, char *disp)
{
	int printed;

	printed = 0;
	if (p.type == 'p' || ( p.type == 'x' && disp[0] != '0'))
		printed = write(1, "0x", 2);
	if (p.type == 'X' && disp[0] != '0')
		printed = write(1, "0X", 2);
	if (ft_tolower(p.type) == 'o')
		printed = write(1, "0", 1);
	return (printed);
}

int		put_space(t_format p, int len, char c, char *disp)
{
	int printed;

	printed = 0;
	len = (p.precision > len) ? p.precision : len;
	if (p.type == 'o' && p.flags[4] && disp[0] != '0')
		len++;
	if ((ft_tolower(p.type) == 'x' ||p.type == 'p')
			&& p.flags[4] && disp[0] != '0')
		len += 2;
	while (len < p.min)
	{
		write(1, &c, 1);
		printed++;
		len++;
	}
	return (printed);
}

int		put_sign(t_format p, char *disp)
{
	int printed;

	printed = 0;
	if ((ft_tolower(p.type) == 'd' || p.type == 'i') && disp[0] != '-')
	{
		if (p.flags[2] && !p.flags[1])
			printed = write(1, " ", 1);
		else if (p.flags[1])
			printed = write(1, "+", 1);
	}
	else if (disp[0] == '-')
		printed += write(1, disp, 1);
	return (printed);
}

int		put_precision(t_format p, int len)
{
	int printed;
	
	printed = 0;
	while (len < p.precision)
	{
		write(1, "0", 1);
		len++;
		printed++;
	}
	return (printed);
}

int		ft_flags(t_format p, char *disp)
{
	int len;
	int printed;

	len = ft_strlen(disp);
	printed = 0;
	if (!p.flags[0] && (!p.flags[3] || p.precision))
		printed += put_space(p, len, ' ', disp);
	printed += put_sign(p, disp);
	if (disp[0] == '-')
		len--;
	if (p.flags[4])
		printed += put_0x(p, disp);
	if (!p.flags[0] && p.flags[3] && !p.precision)
		printed += put_space(p, len, '0', disp);
	if (p.precision)
		printed += put_precision(p, len);
	if (!(p.precision == -1 && disp[0] == '0'))
	{
		(disp[0] == '-') ? ft_putstr(&disp[1]) : ft_putstr(disp);
		printed += len;
	}
	if (p.flags[0])
		printed += put_space(p, len, ' ', disp);
	return (printed);
}
