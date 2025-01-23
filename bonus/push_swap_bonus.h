/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:16:24 by sait-amm          #+#    #+#             */
/*   Updated: 2024/04/02 16:49:36 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "./../functions/functions.h"
# include "./../get_next_line/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef INT_MAX

#  define INT_MAX 2147483647

# endif

# ifndef INT_MIN

#  define INT_MIN -2147483648

# endif

typedef struct e_Node
{
	int				data;
	int				pos;
	int				move_a;
	int				move_b;
	int				nb_mv;
	struct e_Node	*next;
}					t_Node;

// utils fiunction

void				operation_bonus(char *str, t_Node **a, t_Node **b);
void				push(t_Node **a, t_Node **b, char *str);
void				swap_stack(t_Node **s, char *str);
void				rotate_reverce(t_Node **s, char *str);
void				rotate(t_Node **s, char *str);
void				rrr(t_Node **a, t_Node **b, char *str);
void				rr(t_Node **a, t_Node **b, char *str);
t_Node				*ft_add_beg_bonus(t_Node **head, int c);
t_Node				*ft_add_beg(t_Node **head, int c);
int					ft_whitespace(char c);
void				ss(t_Node **a, t_Node **b, char *str);
int					ft_stack_empty_bonus(t_Node *b);

// stack
int					ft_stack_empty(t_Node *a);
int					ft_size_stack(t_Node *s);
void				ft_to_stack(t_Node **s, char **av);
void				ft_stack_bonus(t_Node **a, char **av, int ac);
int					is_sorted_stack_bonus(t_Node *a);

// checking function

int					ft_checkdigit_bonus(char *str);
int					ft_checkrepeat_bonus(t_Node **s, int k);
void				ft_to_stack(t_Node **s, char **av);
void				ft_stack_bonus(t_Node **a, char **av, int ac);
int					ft_checkdigit(char *str);
int					ft_checkrepeat(t_Node **s, int k);

// free function
void				free_split(char **str, int i);
void				free_list(t_Node **head);

// help function

void				error_bonus(char *str, t_Node **a, t_Node **b);
void				norm_error_bonus(t_Node **a, char **str);
int					cheker_int_bonus(int val, char *str);
int					len_str(char **str);

#endif