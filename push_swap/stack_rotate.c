/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:38:58 by jonghan           #+#    #+#             */
/*   Updated: 2024/10/27 20:13:07 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_rotate_a(t_stack **stack_a, int r_a)
{
	int	a;

	a = ft_abs(r_a);
	while (a--)
	{
		if (r_a < 0)
			cmd_r(stack_a, "ra");
		else
			cmd_reverse_r(stack_a, "rra");
	}
}

static void	stack_rotate_b(t_stack **stack_b, int r_b)
{
	int	b;

	b = ft_abs(r_b);
	while (b--)
	{
		if (r_b < 0)
			cmd_reverse_r(stack_b, "rrb");
		else
			cmd_r(stack_b, "rb");
	}
}

void	stack_rr(t_stack **stack_a, t_stack **stack_b, int r_a, int r_b)
{
	if (r_a < 0 && r_b > 0)
	{
		while (1)
		{
			if (!r_a || !r_b)
				break ;
			r_a++;
			r_b--;
			cmd_rr(stack_a, stack_b, "rr");
		}
	}
	else if (r_a > 0 && r_b < 0)
	{
		while (1)
		{
			if (!r_a || !r_b)
				break ;
			r_a--;
			r_b++;
			cmd_reverse_rr(stack_a, stack_b, "rrr");
		}
	}
	stack_rotate_a(stack_a, r_a);
	stack_rotate_b(stack_b, r_b);
}
