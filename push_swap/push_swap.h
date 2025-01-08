/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:14:22 by jonghan           #+#    #+#             */
/*   Updated: 2024/10/27 21:36:55 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define BUF_SIZE 5

typedef struct s_stack
{
	int				value;
	struct s_stack	*bot;
	struct s_stack	*top;
}					t_stack;

// stack
t_stack				*stack_new(int value);
void				stack_push(t_stack **stack, t_stack *n);
int					init(t_stack **stack_a, int ac, char **av);
int					stack_size(t_stack *stack);
void				stack_rotate_a(t_stack **stack_a, int r_a);

// cmd
void				cmd_s(t_stack **stack, char *cmd);
void				cmd_ss(t_stack **stack_a, t_stack **stack_b, char *cmd);
void				cmd_pa(t_stack **stack_a, t_stack **stack_b, char *cmd);
void				cmd_pb(t_stack **stack_a, t_stack **stack_b, char *cmd);
void				cmd_r(t_stack **stack, char *cmd);
void				cmd_rr(t_stack **stack_a, t_stack **stack_b, char *cmd);
void				cmd_reverse_r(t_stack **stack, char *cmd);
void				cmd_reverse_rr(t_stack **stack_a, t_stack **stack_b,
						char *cmd);

// sort
void				stack_sort(t_stack **stack_a, t_stack **stack_b,
						int input_size);
void				stack_in_two(t_stack **stack);
void				stack_in_three(t_stack **stack);
int					sorting_check(t_stack **stack);

// greedy
void				greedy_search(t_stack **stack_a, t_stack **stack_b,
						int max);
void				stack_rr(t_stack **stack_a, t_stack **stack_b, int r_a,
						int r_b);

// utils
long				ft_atol(const char *nptr);
int					ft_abs(int n);
int					input_check(char **av);
void				min_max_get(t_stack *stack, int *min, int *max);
int					*indexing(char **av);
int					av_size(char **av);
int					*init_arr(char **av);

//memory
void				memory_free(t_stack *stack_a, t_stack *stack_b);
void				split_free(char **strs);

//bonus
t_list				*read_std(void);
int					checker(t_stack **stack_a, t_stack **stack_b);
void				del_list(void *content);

#endif
