/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertors_dux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:13:23 by jihyukim          #+#    #+#             */
/*   Updated: 2022/03/23 15:39:12 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convertor_d(va_list ap)
{
	long long	num_copy;
	int			num;
	int			count;

	num = va_arg(ap, int);
	if (!num)
	{
		write(1, "0", 1);
		return (1);
	}
	num_copy = num;
	count = 0;
	if (num < 0)
	{
		write(1, "-", 1);
		num_copy *= -1;
		count++;
	}
	write_nbr(num_copy);
	while (num_copy > 0)
	{
		num_copy /= 10;
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

int	convertor_x(va_list ap)
{
	unsigned int	buf;
	int				index;
	int				count;
	char			res[16];

	buf = va_arg(ap, int);
	if (!buf)
	{
		write(1, "0", 1);
		return (1);
	}
	index = -1;
	while (++index < 16 && buf)
	{
		res[index] = "0123456789abcdef"[buf % 16];
		buf /= 16;
	}
	count = index;
	while (--index >= 0 && res[index])
		write(1, &res[index], 1);
	return (count);
}

int	convertor_X(va_list ap)
{
	unsigned int	buf;
	int				index;
	int				count;
	char			res[16];

	buf = va_arg(ap, int);
	if (!buf)
	{
		write(1, "0", 1);
		return (1);
	}
	index = -1;
	while (++index < 16 && buf)
	{
		res[index] = "0123456789ABCDEF"[buf % 16];
		buf /= 16;
	}
	count = index;
	while (--index >= 0 && res[index])
		write(1, &res[index], 1);
	return (count);
}
