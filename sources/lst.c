/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <william.ruetsuquet@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 19:47:14 by wruet-su          #+#    #+#             */
/*   Updated: 2023/04/30 02:30:08 by wruet-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_add_lst_no_arg(char *buff, char *flags, int not_arg, t_args *first)
{
	t_args	*lst;

	lst = malloc(sizeof(t_args));
	if (!lst)
		return (1);
	lst->buff = buff;
	lst->flags = flags;
	lst->not_arg = not_arg;
	lst->type = 0;
	lst->next = NULL;
	if (first->next == NULL)
	{
		first->next = lst;
		return (0);
	}
	while (first->next)
		first = first->next;
	first->next = lst;
	return (0);
}

int	ft_add_lst(char *buff, char *flags, char type, t_args *first)
{
	t_args	*lst;

	lst = malloc(sizeof(t_args));
	if (!lst)
		return (1);
	lst->buff = buff;
	lst->flags = flags;
	lst->not_arg = 0;
	lst->type = type;
	lst->next = NULL;
	if (first->next == NULL)
	{
		first->next = lst;
		return (0);
	}
	while (first->next)
		first = first->next;
	first->next = lst;
	return (0);
}

static int	ft_print_lst_part_2(t_args *lst)
{
	int	i;

	i = 0;
	if (lst->not_arg)
	{
		i = ft_strlen(lst->buff);
		write(1, lst->buff, i);
	}
	else if (lst->flags[0] == '\0')
	{
		i = ft_strlen(lst->buff);
		if (i == 0 && lst->type != 's')
		{
			write(1, &lst->buff[0], 1);
			i++;
		}
		else
			write(1, lst->buff, i);
	}
	else
		i = ft_print_with_flags(lst);
	return (i);
}

int	ft_print_lst(t_args *lst)
{
	int		count;
	t_args	*first;

	first = lst;
	lst = lst->next;
	count = 0;
	while (lst)
	{
		count += ft_print_lst_part_2(lst);
		lst = lst->next;
	}
	ft_lst_free_all(first);
	return (count);
}

void	ft_lst_free_all(t_args *lst)
{
	t_args	*temp;

	lst = lst->next;
	while (lst)
	{
		temp = lst->next;
		if (lst->buff)
			free(lst->buff);
		if (lst->flags)
			free(lst->flags);
		free(lst);
		lst = temp;
	}
}
