/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 22:17:40 by hammeah           #+#    #+#             */
/*   Updated: 2025/12/15 08:08:21 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	struct s_stack	*prev;
	int				value;
	int				index;
	int				sort_index;
	int				push_cost;
	struct s_stack	*target_node;
	bool			lower_med;
	bool			flag_lower_to_push;
	struct s_stack	*next;
}					t_stack;

/*check.c*/
long				ft_atol(char *str);
int					ft_str_is_digit(char *str);
void				ft_create_node(t_stack **a, int nb);
int					ft_check_double(t_stack *a, int nb);
void				ft_create_stack(t_stack **a, char **str, int flag_split);

/*init.c*/
void				ft_complet_node(t_stack *a);
void				ft_find_target(t_stack *set, t_stack *src);
void				ft_push_cost(t_stack *a, t_stack *b);
void				ft_find_lowest(t_stack *src);
void				ft_init_stack(t_stack *a, t_stack *b);

/*error.c*/
void				ft_print_error(t_stack **src, char **split, int flag_split);
void				ft_free_split(char **split);
void				ft_free_stack(t_stack **src);
t_stack				*ft_lstlst(t_stack *lst);

/*sort.c*/
void				ft_sort_three(t_stack **a);
t_stack				*ft_max_value_node(t_stack *a);
bool				ft_stack_sort(t_stack *src);
int					ft_lst_len(t_stack *a);
t_stack				*ft_min_value_node(t_stack *a);

/*push_rules.c*/
void				ft_push(t_stack **src, t_stack **dst);
void				ft_push_b_to_a(t_stack **b, t_stack **a, int flag);
void				ft_push_a_to_b(t_stack **a, t_stack **b, int flag);
void				ft_rev_rotate_stacks(t_stack **a, t_stack **b,
						t_stack *lowest);

/*rotate_rules.c*/
void				ft_rotate(t_stack **src);
void				ft_rotate_a(t_stack **a, int flag);
void				ft_rotate_b(t_stack **b, int flag);
void				ft_rotate_ab(t_stack **a, t_stack **b, int flag);

/*reserve_rotate_rules.c*/
void				ft_rev_rotate(t_stack **src);
void				ft_rev_rotate_a(t_stack **a, int flag);
void				ft_rev_rotate_b(t_stack **b, int flag);
void				ft_rev_rotate_ab(t_stack **a, t_stack **b, int flag);

/*swap_rules.c*/
void				ft_swap(t_stack **src);
void				ft_swap_a(t_stack **a, int flag);
void				ft_swap_b(t_stack **b, int flag);
void				ft_swap_ab(t_stack **a, t_stack **b, int flag);

/*push_swap_algo.c*/
t_stack				*ft_find_lowest_push(t_stack *b);
void				ft_rotate_stacks(t_stack **a, t_stack **b, t_stack *lowest);
void				ft_push_lowest_node(t_stack **a, t_stack **b);
void				ft_lowest_on_top_a(t_stack **src, t_stack *lowest);
void				ft_lowest_on_top_b(t_stack **src, t_stack *lowest);

/*push_swap_algo_suite.c*/
void				ft_push_swap(t_stack **a, t_stack **b);

/*main.c*/
int					main(int argc, char **argv);

#endif