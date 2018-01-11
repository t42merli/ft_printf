/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putelse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 16:13:59 by tmerli            #+#    #+#             */
/*   Updated: 2018/01/09 17:40:12 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putelse(char c, t_format p)
{
	char	space;
	int		printed;

	printed = 0;
	space = (p.flags[3] && !p.flags[0]) ? '0' : ' ';
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
