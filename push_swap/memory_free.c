/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 22:39:30 by jonghan           #+#    #+#             */
/*   Updated: 2024/10/25 15:04:24 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	memory_free(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp;

	while (stack_a)
	{
		tmp = stack_a;
		stack_a = stack_a->top;
		free(tmp);
	}
	while (stack_b)
	{
		tmp = stack_b;
		stack_b = stack_b->top;
		free(tmp);
	}
}

void	split_free(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}
