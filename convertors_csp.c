/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertors_csp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:34:55 by jihyukim          #+#    #+#             */
/*   Updated: 2022/03/22 19:21:17 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convertor_c(va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	if (!c)
		return (0);
	else
		write(1, &c, 1);
	return (1);
}

int	convertor_s(va_list ap)
{
	char	*str;
	int		len;

	str = va_arg(ap, char *);
	if (!str)
		return (0);
	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}

int	convertor_p(va_list ap)
{
	unsigned long long	buf;
	int					index;
	int					count;
	char				res[16];

	buf = va_arg(ap, long long);
	index = -1;
	while (++index < 16 && buf)
	{
		res[index] = "0123456789abcdef"[buf % 16];
		buf /= 16;
	}
	count = index + 2;
	write(1, "0x", 2);
	while (--index >= 0 && res[index])
		write(1, &res[index], 1);
	return (count);
}
