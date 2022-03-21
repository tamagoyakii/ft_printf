/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:34:55 by jihyukim          #+#    #+#             */
/*   Updated: 2022/03/21 19:53:10 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convertor_c (va_list ap)
{
	char c;

	c = va_arg(ap, int);
	write(1, &c, 1);
	return (1);
}

int	convertor_s (va_list ap)
{
	char	*s;
	int		len;

	s = ft_strdup(va_arg(ap, char *));
	len = ft_strlen(s);
	write(1, s, len);
	return (len);
}

int	convertor_d (va_list ap)
{
	long long	n;
	int			d;
	int			count;

	d = va_arg(ap, int);
	n = d;
	count = 0;
	if (d < 0)
	{
		write(1, "-", 1);
		n *= -1;
		count++;
	}
	write_nbr(n);
	while (n > 0)
	{
		n /= 10;
		count++;
	}

	return (count);
}

int	convertor_u (va_list ap)
{
	unsigned int	d;
	int				count;

	d = va_arg(ap, int);
	count = 0;
	write_nbr(d);
	while (d > 0)
	{
		d /= 10;
		count++;
	}

	return (count);
}