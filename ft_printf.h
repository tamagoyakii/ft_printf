/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:39:24 by jihyukim          #+#    #+#             */
/*   Updated: 2022/03/22 18:18:46 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef char	t_bool;

int		ft_printf(const char *format, ...);
int		format_detector(const char *format, int index, va_list ap);
int		format_convertor(char f, va_list ap);
int		convertor_c(va_list ap);
int		convertor_s(va_list ap);
int		convertor_p(va_list ap);
int		convertor_d(va_list ap);
int		convertor_u(va_list ap);
int		convertor_x(va_list ap, char f);
int		ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
void	write_nbr(long long n);

#endif