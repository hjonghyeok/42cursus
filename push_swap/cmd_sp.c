/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_sp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 23:12:21 by jonghan           #+#    #+#             */
/*   Updated: 2024/10/27 20:16:57 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_s(t_stack **stack, char *cmd)
{
	int	tmp;

	if (*stack == NULL)
		return ;
	tmp = (*stack)->bot->value;
	(*stack)->bot->value = (*stack)->bot->bot->value;
	(*stack)->bot->bot->value = tmp;
	if (cmd)
		ft_putendl_fd(cmd, 1);
}

void	cmd_ss(t_stack **stack_a, t_stack **stack_b, char *cmd)
{
	cmd_s(stack_a, NULL);
	cmd_s(stack_b, NULL);
	if (cmd)
		ft_putendl_fd(cmd, 1);
}

void	cmd_pa(t_stack **stack_a, t_stack **stack_b, char *cmd)
{
	t_stack	*tmp;

	if (stack_size(*stack_b) == 0)
		return ;
	if (stack_size(*stack_b) == 1)
	{
		tmp = (*stack_b);
		(*stack_b) = NULL;
	}
	else
	{
		tmp = (*stack_b)->bot;
		(*stack_b)->bot = (*stack_b)->bot->bot;
		(*stack_b)->bot->top = NULL;
	}
	stack_push(stack_a, tmp);
	if (cmd)
		ft_putendl_fd(cmd, 1);
}

void	cmd_pb(t_stack **stack_a, t_stack **stack_b, char *cmd)
{
	t_stack	*tmp;

	if (stack_size(*stack_a) == 0)
		return ;
	if (stack_size((*stack_a)) == 1)
	{
		tmp = (*stack_a);
		(*stack_a) = NULL;
	}
	else
	{
		tmp = (*stack_a)->bot;
		(*stack_a)->bot = (*stack_a)->bot->bot;
		(*stack_a)->bot->top = NULL;
	}
	stack_push(stack_b, tmp);
	if (cmd)
		ft_putendl_fd(cmd, 1);
}
