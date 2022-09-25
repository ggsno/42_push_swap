/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go <go@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 22:43:30 by go                #+#    #+#             */
/*   Updated: 2022/09/25 21:07:41 by go               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "./libft/libft.h"

int	ft_check_error(int argc, char **argv);
t_list *ft_create_list(int argc, char **argv);
t_list *ft_create_list(int argc, char **argv);
int	ft_pa(t_list **list_a, t_list **list_b);
int	ft_pb(t_list **list_a, t_list **list_b);
int	ft_ra(t_list **list_a, int is_print);
int	ft_rb(t_list **list_b, int is_print);
int	ft_rr(t_list **list_a, t_list **list_b);
int	ft_sa(t_list **list_a, int is_print);
int	ft_sb(t_list **list_b, int is_print);
int	ft_ss(t_list **list_a, t_list **list_b);
int	ft_rra(t_list **list_a, int is_print);
int	ft_rrb(t_list **list_b, int is_print);
int	ft_rrr(t_list **list_a, t_list **list_b);

#endif
