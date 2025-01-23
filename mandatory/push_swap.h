/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 10:53:50 by sait-amm          #+#    #+#             */
/*   Updated: 2024/03/30 02:27:59 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./../functions/functions.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
// #include <stdbool.h>

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

typedef struct e_array
{
	int				n;
	int				max_length;
	int				*str;
	int				*res;
}					t_array;

// function utils in stack

void				push(t_Node **a, t_Node **b, char *str);
void				swap_stack(t_Node **s, char *str);
void				rotate_reverce(t_Node **s, char *str);
void				rotate(t_Node **s, char *str);
void				rrr(t_Node **a, t_Node **b, char *str);
void				rr(t_Node **a, t_Node **b, char *str);
void				ft_swap(int *a, int *b);
int					ft_stack_empty(t_Node *a);
int					ft_size_stack(t_Node *s);

// array

void				ft_sort_array(int *str, int n);
int					*ft_to_array(t_Node *s, int l);
int					ft_len(char **str);

// stack a

int					ft_checkdigit(char *str);
int					ft_checkrepeat(t_Node **s, int k);
t_Node				*ft_add_beg(t_Node **head, int c);
void				ft_to_stack(t_Node **s, char **av);
void				ft_stack(t_Node **a, char **av, int ac);
int					is_sorted_stack(t_Node *top);

// LongestincrreasingSubsequence

int					*longestincreasingsub(int *array, int n);
int					*array_lis(int *array, int *n_lis, int *lis_index);
int					*max_len(int *arr, int n, int **lis, int **lis_index);

// push to stack b

int					search(int *array, int a, int n);
int					length(int *arr, int n, int *l);
int					max(int *lis, int n);
void				ft_push_to_b(t_Node **a, t_Node **b, t_array *l);

// initialization

void				initial_lis(int **lis, int **lis_index, int n);
void				initial_array(t_Node *a, int n, t_array *lis);
void				initial_pos(t_Node **b);

// cost

int					target_a(t_Node *a, int k);
void				count_move_a(t_Node *a, t_Node **b);
void				count_move_b(t_Node **b);
void				num_move(t_Node *a, t_Node **b);
int					abs(int a);
void				nb_mv(t_Node **b);
void				cost_node(t_Node **b, t_Node *a);
int					*best_elem(t_Node *b, t_Node *a);

// push to stack a

void				cost_positive(t_Node **a, t_Node **b, int *move);
void				cost_negative(t_Node **a, t_Node **b, int *move);
void				ft_push_to_a(t_Node **a, t_Node **b, int *move);
void				ft_to_b_empty(t_Node **b, t_Node **a);
void				ft_sign_1(t_Node **a, t_Node **b, int *move);
void				ft_sign_2(t_Node **a, t_Node **b, int *move);
int					ft_position_max(t_Node *s);

// function to sort

void				ft_sort_a(t_Node **a, t_Node **b);
void				ft_sort_3(t_Node **s);
void				sort_inf_5(t_Node **a, t_Node **b, int n);

// function to free

void				free_split(char **str, int i);
void				free_array(t_array *l);
void				free_list(t_Node **head);

// help function

int					cheker_int(int val, char *str);
int					min_stack(t_Node *a);
int					len_str(char **str);
int					min_pos_stack(t_Node *a);
void				norm_error(t_Node **a, char **str);
void				fun_norm(int *lis, int *a, int *b, int i);
void				fun_norm2(int *n, int m, t_Node *a);
int					ft_len(char **str);
#endif