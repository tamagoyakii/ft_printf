/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:32:40 by jihyukim          #+#    #+#             */
/*   Updated: 2022/03/21 19:53:39 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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