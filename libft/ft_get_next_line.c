/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go <go@student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:17:09 by go                #+#    #+#             */
/*   Updated: 2022/04/01 11:52:13 by go               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define BUFFER_SIZE 100

static t_lst	*ft_get_node(int fd, t_lst **lst);
static int		ft_read_fd_to_buf(t_lst **lst, t_lst **ptr);
static char		*ft_get_joined(t_lst **lst, t_lst **ptr, char *jnd, ssize_t i);
static int		ft_del_node(t_lst **lst, t_lst **ptr);

char	*ft_get_next_line(int fd)
{
	static t_lst	*lst = NULL;
	t_lst			*node;
	char			*joined;
	ssize_t			i;

	if (fd < 0)
		return (NULL);
	node = ft_get_node(fd, &lst);
	if (!node)
		return (NULL);
	joined = NULL;
	i = -1;
	while (*(node->buf + (++i)) != '\n')
	{
		if (*(node->buf + i) == '\0')
		{
			joined = ft_get_joined(&lst, &node, joined, i);
			if (!node)
				return (joined);
			i = -1;
		}
	}
	return (ft_get_joined(&lst, &node, joined, i));
}

static t_lst	*ft_get_node(int fd, t_lst **lst)
{
	t_lst	*result;

	result = *lst;
	while (result && result->fd != fd)
		result = result->next;
	if (!result)
	{
		result = (t_lst *)malloc(sizeof(t_lst));
		if (!result)
			return (NULL);
		result->buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!result->buf)
		{
			free(result);
			result = NULL;
			return (NULL);
		}
		result->fd = fd;
		result->next = NULL;
		ft_lstadd_back_gnl(lst, result);
		if (!ft_read_fd_to_buf(lst, &result))
			return (NULL);
	}
	return (result);
}

static int	ft_read_fd_to_buf(t_lst **lst, t_lst **ptr)
{
	ssize_t	read_size;
	t_lst	*node;

	node = *ptr;
	if (!node)
		return (0);
	read_size = read(node->fd, node->buf, BUFFER_SIZE);
	if (read_size < 0)
	{
		ft_del_node(lst, ptr);
		return (0);
	}
	(node->buf)[read_size] = '\0';
	return (1);
}

static char	*ft_get_joined(t_lst **lst, t_lst **ptr, char *joined, ssize_t i)
{
	char	*buf_rst;

	joined = ft_strjoin_free_args(joined, ft_substr((*ptr)->buf, 0, i + 1));
	if (((*ptr)->buf)[i] == '\n')
	{
		buf_rst = ft_substr((*ptr)->buf, i + 1, ft_strlen((*ptr)->buf) - i - 1);
		ft_memmove((*ptr)->buf, buf_rst, ft_strlen(buf_rst));
		((*ptr)->buf)[ft_strlen(buf_rst)] = '\0';
		free(buf_rst);
	}
	else
	{
		if (!ft_read_fd_to_buf(lst, ptr))
			return (NULL);
		if (!ft_strlen((*ptr)->buf))
			if (!ft_del_node(lst, ptr))
				return (NULL);
		if (!*joined)
		{
			free(joined);
			joined = NULL;
		}
	}
	return (joined);
}

static int	ft_del_node(t_lst **head, t_lst **node_ptr)
{
	t_lst	*prev;
	t_lst	*target;

	prev = NULL;
	target = *head;
	while (target && target != *node_ptr)
	{
		prev = target;
		target = target->next;
	}
	if (target)
	{
		if (prev)
			prev->next = target->next;
		else
			*head = target->next;
		free(target->buf);
		target->buf = NULL;
		free(*node_ptr);
		*node_ptr = NULL;
		return (1);
	}
	else
		return (0);
}
