/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:55:31 by jonghan           #+#    #+#             */
/*   Updated: 2024/10/27 21:37:46 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_cmd(char *cmd)
{
	if (!ft_strncmp("sa", cmd, ft_strlen(cmd)))
		return (0);
	else if (!ft_strncmp("sb", cmd, ft_strlen(cmd)))
		return (0);
	else if (!ft_strncmp("ss", cmd, ft_strlen(cmd)))
		return (0);
	else if (!ft_strncmp("pa", cmd, ft_strlen(cmd)))
		return (0);
	else if (!ft_strncmp("pb", cmd, ft_strlen(cmd)))
		return (0);
	else if (!ft_strncmp("ra", cmd, ft_strlen(cmd)))
		return (0);
	else if (!ft_strncmp("rb", cmd, ft_strlen(cmd)))
		return (0);
	else if (!ft_strncmp("rr", cmd, ft_strlen(cmd)))
		return (0);
	else if (!ft_strncmp("rra", cmd, ft_strlen(cmd)))
		return (0);
	else if (!ft_strncmp("rrb", cmd, ft_strlen(cmd)))
		return (0);
	else if (!ft_strncmp("rrr", cmd, ft_strlen(cmd)))
		return (0);
	return (1);
}

int	cmds_check(t_list *cmds)
{
	t_list	*tmp;

	tmp = cmds;
	while (tmp)
	{
		if (is_cmd((char *)tmp->content))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	cmd_play(char *cmd, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strncmp("sa", cmd, ft_strlen(cmd)))
		cmd_s(stack_a, NULL);
	else if (!ft_strncmp("sb", cmd, ft_strlen(cmd)))
		cmd_s(stack_b, NULL);
	else if (!ft_strncmp("ss", cmd, ft_strlen(cmd)))
		cmd_ss(stack_a, stack_b, NULL);
	else if (!ft_strncmp("pa", cmd, ft_strlen(cmd)))
		cmd_pa(stack_a, stack_b, NULL);
	else if (!ft_strncmp("pb", cmd, ft_strlen(cmd)))
		cmd_pb(stack_a, stack_b, NULL);
	else if (!ft_strncmp("ra", cmd, ft_strlen(cmd)))
		cmd_r(stack_a, NULL);
	else if (!ft_strncmp("rb", cmd, ft_strlen(cmd)))
		cmd_r(stack_b, NULL);
	else if (!ft_strncmp("rr", cmd, ft_strlen(cmd)))
		cmd_rr(stack_a, stack_b, NULL);
	else if (!ft_strncmp("rra", cmd, ft_strlen(cmd)))
		cmd_reverse_r(stack_a, NULL);
	else if (!ft_strncmp("rrb", cmd, ft_strlen(cmd)))
		cmd_reverse_r(stack_b, NULL);
	else if (!ft_strncmp("rrr", cmd, ft_strlen(cmd)))
		cmd_reverse_rr(stack_a, stack_b, NULL);
}

int	checker(t_stack **stack_a, t_stack **stack_b)
{
	t_list	*list;
	t_list	*free_lst;
	void	(*del)();

	list = read_std();
	free_lst = list;
	del = del_list;
	if (!list)
		return (1);
	if (cmds_check(list))
	{
		ft_lstclear(&list, del);
		free(list);
		return (1);
	}
	while (list)
	{
		cmd_play((char *)list->content, stack_a, stack_b);
		list = list->next;
	}
	ft_lstclear(&free_lst, del);
	free(free_lst);
	return (0);
}
