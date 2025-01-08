/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 22:57:35 by jonghan           #+#    #+#             */
/*   Updated: 2024/11/19 00:37:59 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	check_float(char *str)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] < 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] == '.')
			cnt++;
		else if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	if (cnt > 1)
		return (1);
	return (0);
}

int	check_int(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] < 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_ar(int ac, char **av)
{
	if (ac <= 1)
		return (ar_error());
	if (!ft_memcmp(av[1], "h", 2))
		return (help());
	if ((ft_memcmp(av[1], "m", 2) && ft_memcmp(av[1], "j", 2)) && \
			ft_memcmp(av[1], "b", 2))
		return (no_match());
	if (!ft_memcmp(av[1], "j", 2))
	{
		if (ac != 4 || check_float(av[2]) || check_float(av[3]))
			return (float_error());
	}
	else if (!ft_memcmp(av[1], "b", 2))
	{
		if (ac != 4 || check_int(av[2]) || check_int(av[3]))
			return (int_error());
	}
	else if (!ft_memcmp(av[1], "m", 2))
	{
		if (ac != 2)
			return (mandelbrot_error());
	}
	return (0);
}
