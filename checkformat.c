/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkformat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 13:50:07 by tmerli            #+#    #+#             */
/*   Updated: 2017/12/22 14:44:30 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_flags(t_format *param, const char *p)
{
	int i;

	i = 0;
	while (i < 5)
		param->flags[i++] = 0;
	i = 0;
	while (p[i] && (p[i] == '-' || p[i] == '+' || p[i] == ' ' || p[i] == '0'
				|| p[i] == '#'))
	{
		if (p[i] == '-')
			param->flags[0] = 1;
		if (p[i] == '+')
			param->flags[1] = 1;
		if (p[i] == ' ')
			param->flags[2] = 1;
		if (p[i] == '0')
			param->flags[3] = 1;
		if (p[i] == '#')
			param->flags[4] = 1;
		i++;
	}
	return (i);
}

int		ft_get_length(t_format *param, const char *p)
{
	int i;

	i = 0;
	param->length = 0;
	while (p[i] && (p[i] == 'l' || p[i] == 'h' || p[i] == 'j' || p[i] ==  'z')
			&& i < 2 && !(param->length == 'z' || param->length == 'j'))
	{
		if (!i)
			param->length = p[i];
		if (i && (param->length == 'l' ||  param->length == 'h'))
			param->length = ft_toupper(p[i]);
		else if (i)
			return (i);
		i++;
	}
	return (i);
}

int		is_type(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' || c == 'i'
			 || c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x'
			 || c == 'X' || c == 'c' || c == 'C')
		return (1);
	return (0);
}
