/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go <go@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 22:43:30 by go                #+#    #+#             */
/*   Updated: 2022/09/29 14:17:49 by go               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				c;
	struct s_list	*n;
}t_list;

int		ft_atoi(const char *str);
t_list	*ft_lstnew(int c);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *list);
int		ft_putstr(char *s);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);
int		ft_get_bigger(int a, int b);
int		ft_abs(int num);
int		ft_pa(t_list **list_a, t_list **list_b);
int		ft_pb(t_list **list_a, t_list **list_b);
int		ft_ra(t_list **list_a, int is_print);
int		ft_rb(t_list **list_b, int is_print);
int		ft_rr(t_list **list_a, t_list **list_b);
int		ft_sa(t_list **list_a, int is_print);
int		ft_sb(t_list **list_b, int is_print);
int		ft_ss(t_list **list_a, t_list **list_b);
int		ft_rra(t_list **list_a, int is_print);
int		ft_rrb(t_list **list_b, int is_print);
int		ft_rrr(t_list **list_a, t_list **list_b);
int		ft_check_error(int argc, char **argv);
t_list	*ft_set_list(int argc, char **argv);
void	ft_sort(t_list **list_a, t_list **list_b);

#endif
