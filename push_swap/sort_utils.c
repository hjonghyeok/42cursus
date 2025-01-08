/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 00:01:59 by jonghan           #+#    #+#             */
/*   Updated: 2024/10/27 00:02:42 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_in_two(t_stack **stack)
{
	if ((*stack)->value < (*stack)->top->value)
		cmd_s(stack, "sa");
}

void	stack_in_three(t_stack **stack)
{
	int	min;
	int	max;

	min = 0;
	max = 0;
	min_max_get((*stack), &min, &max);
	if (min == 1)
	{
		if (max == 0)
			cmd_s(stack, "sa");
		else if (max == 2)
			cmd_r(stack, "ra");
	}
	else if (min == 0)
	{
		if (max == 2)
			cmd_s(stack, "sa");
		cmd_reverse_r(stack, "rra");
	}
	else if (min == 2 && max == 1)
	{
		cmd_s(stack, "sa");
		cmd_r(stack, "ra");
	}
}

int	sorting_check(t_stack **stack)
{
	int		i;
	t_stack	*tmp;

	i = stack_size(*stack) - 1;
	tmp = *stack;
	while (i >= 0)
	{
		if (tmp->value != i)
			return (0);
		i--;
		tmp = tmp->top;
	}
	return (1);
}
