/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 14:11:02 by tmerli            #+#    #+#             */
/*   Updated: 2017/12/29 21:37:20 by tmerli           ###   ########.fr       */
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
int		ft_put(va_list ap, t_format p);
int		ft_flags(t_format p, char *disp);
char	*ft_get_ll(t_format p, long long num);
char	*ft_get_l(t_format p, long long num);
char	*ft_get_hh(t_format p, long long num);
char	*ft_get_h(t_format p, long long num);
char	*ft_get_d(t_format p, long long num);

#endif
