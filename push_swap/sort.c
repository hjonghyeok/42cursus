/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 22:17:07 by jonghan           #+#    #+#             */
/*   Updated: 2024/10/27 20:12:34 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	over_ten(t_stack **stack_a, t_stack **stack_b, int input_size)
{
	int	i;
	int	cnt;
	int	pivet[4];

	i = -1;
	cnt = 0;
	pivet[0] = input_size / 4;
	pivet[1] = input_size / 2;
	pivet[2] = input_size / 4 * 3;
	pivet[3] = input_size - 3;
	while (++i < 4)
	{
		while (1)
		{
			if (stack_size(*stack_a) <= 3 || cnt >= pivet[i])
				break ;
			if ((*stack_a)->bot->value < pivet[i])
			{
				cmd_pb(stack_a, stack_b, "pb");
				cnt++;
			}
			else
				cmd_r(stack_a, "ra");
		}
	}
}

static void	under_ten(t_stack **stack_a, t_stack **stack_b, int input_size)
{
	while (stack_size(*stack_a) > 3)
	{
		if ((*stack_a)->bot->value < input_size - 3)
			cmd_pb(stack_a, stack_b, "pb");
		else
			cmd_r(stack_a, "ra");
	}
}

static void	finish_rotate(t_stack **stack)
{
	int		i;
	int		size;
	t_stack	*tmp;

	tmp = *stack;
	i = 1;
	size = stack_size(*stack);
	while (tmp->value)
	{
		tmp = tmp->top;
		i++;
	}
	if (i > ft_abs(i - size))
		i = i - size;
	stack_rotate_a(stack, i);
}

void	pa_sort(t_stack **stack_a, t_stack **stack_b, int max)
{
	int	old_value;

	old_value = (*stack_a)->bot->value;
	while (stack_size((*stack_b)))
	{
		if ((*stack_a)->bot->value > (*stack_b)->bot->value && \
	(((*stack_a)->value == max || (*stack_a)->value < (*stack_b)->bot->value)))
		{
			old_value = (*stack_b)->bot->value;
			cmd_pa(stack_a, stack_b, "pa");
		}
		else
		{
			if (old_value < (*stack_b)->bot->value)
				cmd_r(stack_a, "ra");
			else
				cmd_reverse_r(stack_a, "rra");
		}
	}
}

void	stack_sort(t_stack **stack_a, t_stack **stack_b, int input_size)
{
	if (input_size == 1 || sorting_check(stack_a))
		return ;
	if (input_size == 2)
		stack_in_two(stack_a);
	else if (input_size == 3)
		stack_in_three(stack_a);
	else
	{
		if (input_size <= 150)
			under_ten(stack_a, stack_b, input_size);
		else
			over_ten(stack_a, stack_b, input_size);
		stack_in_three(stack_a);
		cmd_pa(stack_a, stack_b, "pa");
		if (input_size > 4)
			greedy_search(stack_a, stack_b, input_size - 1);
		finish_rotate(stack_a);
	}
}
