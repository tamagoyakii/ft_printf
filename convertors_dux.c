/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertors_dux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:13:23 by jihyukim          #+#    #+#             */
/*   Updated: 2022/03/24 17:14:17 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convertor_d(va_list ap)
{
	long long	num;
	int			count;

	num = va_arg(ap, int);
	if (!num)
	{
		write(1, "0", 1);
		return (1);
	}
	count = 0;
	if (num < 0)
	{
		write(1, "-", 1);
		num *= -1;
		count++;
	}
	write_nbr(num);
	while (num > 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

int	convertor_u(va_list ap)
{
	unsigned int	num;
	int				count;

	num = va_arg(ap, int);
	if (!num)
	{
		write(1, "0", 1);
		return (1);
	}
	count = 0;
	write_nbr(num);
	while (num > 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

int	convertor_x(va_list ap, char f)
{
	unsigned int	buf;
	char			*base;
	char			res[16];
	int				index;
	int				count;

	buf = va_arg(ap, int);
	if (!buf)
	{
		write(1, "0", 1);
		return (1);
	}
	base = set_base(f);
	index = -1;
	while (++index < 16 && buf)
	{
		res[index] = base[buf % 16];
		buf /= 16;
	}
	count = index;
	while (--index >= 0 && res[index])
		write(1, &res[index], 1);
	return (count);
}

char	*set_base(char f)
{
	char	*base;

	if (f == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	return (base);
}
