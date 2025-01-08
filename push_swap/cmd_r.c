/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_r.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 23:44:56 by jonghan           #+#    #+#             */
/*   Updated: 2024/10/27 20:16:25 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_r(t_stack **stack, char *cmd)
{
	if (*stack == NULL)
		return ;
	(*stack)->bot->bot->top = NULL;
	(*stack)->bot->top = (*stack);
	(*stack) = (*stack)->bot;
	if (cmd)
		ft_putendl_fd(cmd, 1);
}

void	cmd_rr(t_stack **stack_a, t_stack **stack_b, char *cmd)
{
	cmd_r(stack_a, NULL);
	cmd_r(stack_b, NULL);
	if (cmd)
		ft_putendl_fd(cmd, 1);
}

void	cmd_reverse_r(t_stack **stack, char *cmd)
{
	if (*stack == NULL)
		return ;
	(*stack)->bot->top = (*stack);
	(*stack) = (*stack)->top;
	(*stack)->bot->top = NULL;
	if (cmd)
		ft_putendl_fd(cmd, 1);
}

void	cmd_reverse_rr(t_stack **stack_a, t_stack **stack_b, char *cmd)
{
	cmd_reverse_r(stack_a, NULL);
	cmd_reverse_r(stack_b, NULL);
	if (cmd)
		ft_putendl_fd(cmd, 1);
}
