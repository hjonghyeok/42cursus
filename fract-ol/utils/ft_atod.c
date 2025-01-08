/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 22:18:00 by jonghan           #+#    #+#             */
/*   Updated: 2024/11/15 23:55:39 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	ft_atod(char *str)
{
	int		i;
	int		j;
	int		m;
	double	result;

	i = 0;
	m = 1;
	result = 0.0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] < 13))
		i++;
	if (str[i] == '-')
		m = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	i--;
	while (str[++i] && str[i] != '.')
		result = result * 10 + (str[i] - 48);
	if (!str[i])
		return (result * m);
	j = ft_strlen(str);
	while (str[--j] != '.')
		result += (str[j] - 48) * pow(0.1, j - i);
	return (result * m);
}
