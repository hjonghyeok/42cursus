/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:17:20 by jonghan           #+#    #+#             */
/*   Updated: 2024/10/27 17:43:49 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	t_stack	*tmp;
	int		size;

	size = 0;
	tmp = stack;
	while (tmp)
	{
		tmp = tmp->top;
		size++;
	}
	return (size);
}

t_stack	*stack_new(int value)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->value = value;
	stack->bot = NULL;
	stack->top = NULL;
	return (stack);
}

void	stack_push(t_stack **stack, t_stack *n)
{
	t_stack	*tmp;

	if (!n)
		return ;
	if (!*stack)
	{
		*stack = n;
		return ;
	}
	tmp = *stack;
	while (tmp->top)
		tmp = tmp->top;
	n->bot = tmp;
	tmp->top = n;
	(*stack)->bot = n;
}

int	init(t_stack **stack_a, int ac, char **av)
{
	int		i;
	t_stack	*stack;
	int		*idx_arr;

	if (ac == 1)
		return (0);
	i = av_size(av);
	idx_arr = indexing(av);
	if (!idx_arr)
		return (1);
	while (i-- > 0)
	{
		stack = stack_new(idx_arr[i]);
		if (stack == NULL)
			return (1);
		stack_push(stack_a, stack);
	}
	free(idx_arr);
	return (0);
}
