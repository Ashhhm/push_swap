/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 18:29:59 by hammeah           #+#    #+#             */
/*   Updated: 2025/12/15 14:57:50 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include "push_swap.h"
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_gnllist
{
	char				*str;
	struct s_gnllist	*next;
}						t_gnllist;

/*get_next_line.c*/
char					*get_next_line(int fd);
void					ft_create_str(int fd, t_gnllist **list);
void					ft_add_to_list(char *buffer, t_gnllist **list,
							int byte_read);
void					ft_return_line(t_gnllist *list, char **ret);
void					ft_next_ret(t_gnllist **list);

/*get_next_line_utils.c*/
int						ft_checking_backslast(t_gnllist *list);
t_gnllist				*ft_lstlast_b(t_gnllist *list);
int						ft_len_line(t_gnllist *list);
void					ft_free_list(t_gnllist *list);
int						ft_strlen_b(char *str);

/*cmd_read.c*/
void					ft_print_err(t_stack **a, t_stack **b, int flag);
void					ft_cmd_read(char *line_cmd, t_stack **a, t_stack **b);
void					ft_line_cmd(char *line_cmd, t_stack **a, t_stack **b);

#endif