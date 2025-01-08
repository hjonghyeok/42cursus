/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:23:12 by jonghan           #+#    #+#             */
/*   Updated: 2024/10/27 22:00:52 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_print(t_stack *stack_a, t_stack *stack_b)
{
	ft_putstr_fd("Error\n", 1);
	memory_free(stack_a, stack_b);
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return (0);
	if (input_check(av) || init(&stack_a, ac, av))
		return (error_print(stack_a, stack_b));
	if (checker(&stack_a, &stack_b))
		return (error_print(stack_a, stack_b));
	if (sorting_check(&stack_a) && stack_b == NULL)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	memory_free(stack_a, stack_b);
	return (0);
}
