/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 16:44:22 by tmerli            #+#    #+#             */
/*   Updated: 2018/01/09 16:54:50 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnstr(char *str, int size)
{
	if (size <= 0)
		return (0);
	if (size > (int)ft_strlen(str))
		size = (int)ft_strlen(str);
	return (write(1, str, size));
}
