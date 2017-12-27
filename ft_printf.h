/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 14:11:02 by tmerli            #+#    #+#             */
/*   Updated: 2017/12/22 18:48:33 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"

typedef struct	s_format
{
	short			flags[5];
	int				min;
	int				precision;
	char			length;
	char			type;
	unsigned int	printed;
}				t_format;

int		ft_printf(const char *format, ...);
int		ft_get_flags(t_format *param, const char *format);
int		ft_get_length(t_format *parma, const char *format);
int		is_type(char c);

#endif
