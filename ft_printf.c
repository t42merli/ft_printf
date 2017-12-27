/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 22:56:43 by tmerli            #+#    #+#             */
/*   Updated: 2017/12/26 21:41:23 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int ft_get_param(t_format *param,const char *p)
{
	int i;

	i = 0;
	i += ft_get_flags(param, &p[i]);
	param->min = ft_atoi(&p[i]);
	while (ft_isdigit(p[i]))
		i++;
	if (p[i] == '.')
	{
		i++;
		param->precision = ft_atoi(&p[i]);
		while (ft_isdigit(p[i]))
			i++;
	}
	else
		param->precision = 0;
	i += ft_get_length(param, &p[i]);
	if (is_type(p[i]))
		param->type = p[i++];
	else
		return (0);
	return (i);
}
/*
void	check_param(t_format param)
{
	int i;

	i = 0;
	printf("\n");
	while (i < 5)
	{
		printf("flags nb %i = %i\n", i + 1, param.flags[i]);
		i++;
	}
	printf("min : %i\n", param.min);
	printf("precision : %i\n", param.precision);
	printf("length : %c\n", param.length);
	printf("type : %c\n", param.type);
}
*/
int		ft_printf(const char *format, ...)
{
	va_list ap;
	t_format param;
	int i;
	int ret;
	int printed;

	printed = 0;
	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		ret = 0;
		if (format[i] == '%')
		{
			i++;
			if ((ret = ft_get_param(&param, &format[i])))
				printed += ft_put(ap, param);
//				;
//				check_param(param);
			i += ret;
		}
		ft_putchar(format[i++]);
		printed++;
	}
	va_end(ap);
	return (0);
}

int main(int argc, const char *argv[])
{
	char *s = "test bla %0+- 62hd awffa %+0d SF";
	printf("%s\n", s);
	ft_printf(s, 3);
	return 0;
}