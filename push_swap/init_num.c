/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:09:11 by jonghan           #+#    #+#             */
/*   Updated: 2024/10/27 00:07:46 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	in_arr(int *arr, int c, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	av_size(char **av)
{
	char	**strs;
	int		j;
	int		cnt;

	cnt = 0;
	while (*++av)
	{
		strs = ft_split(*av, ' ');
		if (!strs)
			return (-1);
		j = 0;
		while (strs[j])
			j++;
		cnt += j;
		split_free(strs);
	}
	return (cnt);
}

static int	get_arr(int *arr, char **strs, int *i)
{
	int	j;

	j = 0;
	while (strs[j])
	{
		*i += 1;
		arr[*i] = ft_atoi(strs[j]);
		if (in_arr(arr, arr[*i], *i))
		{
			free(arr);
			split_free(strs);
			return (1);
		}
		j++;
	}
	return (0);
}

int	*init_arr(char **av)
{
	int		i;
	char	**strs;
	int		*arr;

	arr = (int *)malloc(sizeof(int) * av_size(av));
	if (!arr)
		return (NULL);
	i = -1;
	while (*++av)
	{
		strs = ft_split(*av, ' ');
		if (!strs)
		{
			free(arr);
			return (NULL);
		}
		if (get_arr(arr, strs, &i))
			return (NULL);
		split_free(strs);
	}
	return (arr);
}
