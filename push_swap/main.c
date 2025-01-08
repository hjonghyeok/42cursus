/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:15:38 by jonghan           #+#    #+#             */
/*   Updated: 2024/10/27 17:53:44 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return (0);
	if (input_check(av) || init(&stack_a, ac, av))
	{
		ft_putstr_fd("Error\n", 2);
		memory_free(stack_a, stack_b);
		return (0);
	}
	stack_sort(&stack_a, &stack_b, av_size(av));
	memory_free(stack_a, stack_b);
}
