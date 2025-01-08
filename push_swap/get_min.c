/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 23:23:35 by jonghan           #+#    #+#             */
/*   Updated: 2024/10/21 22:47:17 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_max_get(t_stack *stack, int *min, int *max)
{
	t_stack	*lst;
	int		l_min;
	int		l_max;
	int		i;

	lst = stack;
	l_max = lst->value;
	l_min = lst->value;
	lst = lst->top;
	i = 1;
	while (lst)
	{
		if (l_max < lst->value)
		{
			l_max = lst->value;
			*max = i;
		}
		if (l_min > lst->value)
		{
			l_min = lst->value;
			*min = i;
		}
		lst = lst->top;
		i++;
	}
}
