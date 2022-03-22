/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertors_dux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:13:23 by jihyukim          #+#    #+#             */
/*   Updated: 2022/03/22 19:00:48 by jihyukim         ###   ########.fr       */
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

int	convertor_x(va_list ap, char f)
{
	unsigned int	buf;
	int				index;
	int				count;
	char			*hex;
	char			res[16];

	buf = va_arg(ap, int);
	// if (!buf)
	// {
	// 	write(1, "0", 1);
	// 	return (1);
	// }
	if (f == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	index = -1;
	while (++index < 16)
	{
		res[index] = hex[buf % 16];
		buf /= 16;
	}
	count = index;
	while (--index >= 0 && res[index])
		write(1, &res[index], 1);
	return (count);
}

// int	convertor_x(va_list ap, char f)
// {
// 	unsigned int	buf;
// 	int				index;
// 	int				count;
// 	char			*hex;
// 	char			*res;

// 	buf = va_arg(ap, int);
// 	if (!buf)
// 	{
// 		write(1, "0", 1);
// 		return (1);
// 	}
// 	if (f == 'x')
// 		hex = "0123456789abcdef";
// 	else
// 		hex = "0123456789ABCDEF";
// 	index = -1;
// 	res = to_hex(buf, hex, &index);
// 	while (++index < 16)
// 	{
// 		res[index] = hex[buf % 16];
// 		buf /= 16;
// 	}
// 	count = index;
// 	while (--index >= 0 && res[index])
// 		write(1, &res[index], 1);
// 	return (count);
// }

// char	*to_hex(unsigned long long buf, char *hex, int *index)
// {
// 	char	res[16];

// 	while (++*index < 16)
// 	{
// 		res[*index] = hex[buf % 16];
// 		buf /= 16;
// 	}
// 	return (res);
// }