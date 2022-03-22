/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:32:40 by jihyukim          #+#    #+#             */
/*   Updated: 2022/03/22 18:38:36 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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
