/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:57:51 by yidouiss          #+#    #+#             */
/*   Updated: 2023/03/02 16:01:40 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	spc(char ws)
{
	if (ws == ' ' || ws == '\n' || ws == '\t')
		return (1);
	if (ws == '\v' || ws == '\f' || ws == '\r')
		return (1);
	return (0);
}

int	sig(char sig)
{
	if (sig == '-' || sig == '+')
		return (1);
	return (0);
}

int	num(char num)
{
	if (num >= '0' && num <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	j = 0;
	res = 0;
	while (spc(str[i]))
		i++;
	if (sig(str[i]) && sig(str[i + 1]))
		return (0);
	while (sig(str[i]))
	{
		if (str[i] == '-')
			j++;
		i++;
	}
	while (num(str[i]))
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	if (j % 2 == 1)
		res *= -1;
	return (res);
}
