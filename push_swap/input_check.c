/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 05:56:17 by jonghan           #+#    #+#             */
/*   Updated: 2024/10/27 22:00:06 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	int_check(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	range_check(char *s)
{
	long	v;

	v = ft_atol(s);
	if (v < INT_MIN || v > INT_MAX)
		return (1);
	return (0);
}

int	input_check(char **av)
{
	char	**str;
	int		j;

	while (*++av)
	{
		if (*av[0] == 0)
			return (1);
		str = ft_split(*av, ' ');
		if (!str)
			return (1);
		j = 0;
		while (str[j])
		{
			if (int_check(str[j]) || range_check(str[j]))
			{
				split_free(str);
				return (1);
			}
			j++;
		}
		split_free(str);
	}
	return (0);
}
