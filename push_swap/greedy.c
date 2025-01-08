/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 00:19:05 by jonghan           #+#    #+#             */
/*   Updated: 2024/10/27 20:13:39 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	a_search(t_stack **stack, int target, int max)
{
	int		r;
	int		rr;
	t_stack	*tmp;

	tmp = *stack;
	rr = 0;
	while (1)
	{
		if (tmp->bot->value > target && \
				(tmp->value < target || tmp->value == max))
			break ;
		tmp = tmp->top;
		rr++;
	}
	r = rr - stack_size(*stack);
	if (rr < ft_abs(r))
		return (rr);
	return (r);
}

static int	b_search(t_stack **stack, int target)
{
	int		r;
	int		rr;
	t_stack	*tmp;

	tmp = *stack;
	rr = 0;
	while (tmp->value != target)
		tmp = tmp->top;
	while (tmp->top)
	{
		rr++;
		tmp = tmp->top;
	}
	r = rr - stack_size(*stack);
	if (rr < ft_abs(r))
		return (rr);
	return (r);
}

void	greedy_search(t_stack **s_a, t_stack **s_b, int max)
{
	int		a_min;
	int		b_min;
	int		total;
	t_stack	*tmp;

	while (*s_b)
	{
		tmp = *s_b;
		a_min = max;
		b_min = max;
		total = a_min + b_min;
		while (tmp)
		{
			if (total >= ft_abs(a_search(s_a, tmp->value, max)) + \
					ft_abs(b_search(s_b, tmp->value)))
			{
				a_min = a_search(s_a, tmp->value, max);
				b_min = b_search(s_b, tmp->value);
				total = ft_abs(a_min) + ft_abs(b_min);
			}
			tmp = tmp->top;
		}
		stack_rr(s_a, s_b, a_min, b_min);
		cmd_pa(s_a, s_b, "pa");
	}
}
