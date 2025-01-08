/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:47:49 by jonghan           #+#    #+#             */
/*   Updated: 2024/10/26 18:55:53 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	arr_swap(int *arr, int j)
{
	int	tmp;

	tmp = arr[j];
	arr[j] = arr[j + 1];
	arr[j + 1] = tmp;
}

static int	*arr_sort(int *arr, int ac)
{
	int	i;
	int	j;
	int	*sort_arr;

	sort_arr = (int *)malloc(sizeof(int) * (ac + 1));
	if (!sort_arr)
		return (NULL);
	i = -1;
	while (++i < ac)
		sort_arr[i] = arr[i];
	i = -1;
	while (++i < ac)
	{
		j = -1;
		while (++j < ac - 1)
		{
			if (sort_arr[j] > sort_arr[j + 1])
				arr_swap(sort_arr, j);
		}
	}
	return (sort_arr);
}

static int	*indexing_arr(int *sort_arr, int *arr, int ac)
{
	int	i;
	int	j;
	int	*result_arr;

	result_arr = (int *)malloc(sizeof(int) * (ac + 1));
	if (!result_arr)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		j = 0;
		while (j < ac)
		{
			if (arr[i] == sort_arr[j])
				result_arr[i] = j;
			j++;
		}
		i++;
	}
	free(arr);
	free(sort_arr);
	return (result_arr);
}

int	*indexing(char **av)
{
	int	*arr;
	int	*sort_arr;

	arr = init_arr(av);
	if (!arr)
		return (NULL);
	sort_arr = arr_sort(arr, av_size(av));
	if (!sort_arr)
		return (NULL);
	return (indexing_arr(sort_arr, arr, av_size(av)));
}
