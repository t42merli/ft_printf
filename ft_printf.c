/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 22:56:43 by tmerli            #+#    #+#             */
/*   Updated: 2018/01/09 17:30:05 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_get_param(t_format *param, const char *p)
{
	int i;
	int ret;

	ret = 0;
	i = 0;
	i += ft_get_flags(param, &p[i]);
	param->min = ft_atoi(&p[i]);
	while (ft_isdigit(p[i]))
		i++;
	if (p[i] == '.')
	{
		i++;
		ret = ft_atoi(&p[i]);
		param->precision = (ret) ? ret : -1;
		while (ft_isdigit(p[i]))
			i++;
	}
	else
		param->precision = 0;
	i += ft_get_length(param, &p[i]);
	param->type = p[i++];
	return (i);
}

int		ft_printf2(char *tmp, va_list ap)
{
	int			i;
	int			printed;
	t_format	param;

	printed = 0;
	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == '%')
		{
			i++;
			i += ft_get_param(&param, &tmp[i]);
			if (param.type)
				printed += ft_put(ap, param);
		}
		if (tmp[i] && tmp[i] != '%')
			printed += write(1, &tmp[i++], 1);
	}
	return (printed);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			printed;
	char		*tmp;

	tmp = ft_strdup(format);
	va_start(ap, format);
	printed = ft_printf2(tmp, ap);
	free(tmp);
	va_end(ap);
	return (printed);
}
