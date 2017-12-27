/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 22:40:36 by tmerli            #+#    #+#             */
/*   Updated: 2017/12/27 17:54:01 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"
#include <locale.h>

char	*ft_itoa_base(int nb, int base);

int main(int argc, const char *argv[])
{
	long long n;
	n = 9223372036854775807;
/*	char s[4];
	int c = ft_atoi(argv[1]);
	int i = 3;
	ft_memcpy(s, (char*)&c, 4);
	while (i >= 0)
	{
		write(1, &s[i], 1);
		i--;
	}
	setlocale(LC_ALL, "");
	char *str = "wefre";*/
	ft_putstr(ft_itoa(n));
	printf("\n%lld", n);
	return 0;
}
