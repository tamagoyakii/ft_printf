/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:22:51 by jihyukim          #+#    #+#             */
/*   Updated: 2022/03/21 19:51:16 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_printf.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*dst;
	int		i;

	dst = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!(dst))
		return (0);
	i = 0;
	while (*(s1 + i))
	{
		*(dst + i) = *(s1 + i);
		i++;
	}
	*(dst + i) = 0;
	return (dst);
}

// int convertor_p(va_list ap)
// {
// 	char	*p;
	
// 	write(1, va_arg(ap, char *), )
// }

void	write_nbr(long long n)
{
	char	buf;

	if (!(n / 10))
	{
		buf = n + 48;
		write(1, &buf, 1);
	}
	else
	{
		buf = n % 10 + 48;
		write_nbr(n / 10);
		write(1, &buf, 1);
	}
}

int	convertor_u (va_list ap)
{
	unsigned int	d;
	int				count;

	d = va_arg(ap, int);
	write_nbr(d);
	count = 0;
	while (d > 0)
	{
		d /= 10;
		count++;
	}

	return (count);
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

int	format_convertor(char f, va_list ap)
{
	switch(f)
	{
		// case 'c':
		// 	return (convertor_c(ap));
		// 	break;
		// case 's':
		// 	return (convertor_s(ap));
		// 	break;
		// case 'p':
		// 	return (convertor_p(ap));
		// 	break;
		case 'd':
		case 'i':
			return (convertor_d(ap));
			break;
		case 'u':
			return (convertor_u(ap));
			break;
		// case 'x':
		// case 'X':
		// 	break;
		case '%':
			write(1, "%", 1);
			return (1);
			break;
	}
	return (1);
}

int	format_detector(const char *format, int index, va_list ap)
{
	char	*type;
	int		type_index;

	index++;
	type = "cspdiuxX%";
	type_index = 0;
	while (type[type_index])
	{
		if (format[index] == type[type_index])
		{
			return (format_convertor(format[index], ap));
		}
		type_index++;
	}
	return (1);
}


int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		index;
	int		count;

	va_start(ap, format);  
	index = 0;
	count = 0;
	while(format[index])
	{
		if (format[index] != '%')
		{
			write(1, &format[index], 1);
			index++;
			count++;
		}
		else
		{
			count += format_detector(format, index, ap);
			index += 2;
		}
	}
	va_end(ap);
	printf("%d", count);
	return (count);
}

int main()
{
	printf("%d\n", printf("Hello Wor%%ld %d", -11223344));
	ft_printf("Hello Wor%%ld %d", -11223344);
	return (0);
}