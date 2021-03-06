/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:22:51 by jihyukim          #+#    #+#             */
/*   Updated: 2022/03/24 17:16:10 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_detector(const char *format, int index, va_list ap)
{
	char	*type;
	int		type_index;

	type = "cspdiuxX%";
	type_index = 0;
	while (type[type_index])
	{
		if (format[index] == type[type_index++])
			return (format_convertor(format[index], ap));
	}
	return (1);
}

int	format_convertor(char f, va_list ap)
{
	if (f == 'c')
		return (convertor_c(ap));
	if (f == 's')
		return (convertor_s(ap));
	if (f == 'p')
		return (convertor_p(ap));
	if (f == 'd' || f == 'i')
		return (convertor_d(ap));
	if (f == 'u')
		return (convertor_u(ap));
	if (f == 'x' || f == 'X')
		return (convertor_x(ap, f));
	if (f == '%')
		write(1, "%", 1);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		index;
	int		count;

	va_start(ap, format);
	index = -1;
	count = 0;
	while (format[++index])
	{
		if (format[index] != '%')
		{
			write(1, &format[index], 1);
			count++;
		}
		else
			count += format_detector(format, ++index, ap);
	}
	va_end(ap);
	return (count);
}
