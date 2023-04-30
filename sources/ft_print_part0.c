/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_part1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <william.ruetsuquet@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 01:30:41 by wruet-su          #+#    #+#             */
/*   Updated: 2023/04/30 01:31:11 by wruet-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_with_flags(t_args *lst)
{
	if (lst->flags[0] == '0')
		return (ft_flag_zero(lst));
	if (lst->flags[0] == '+')
		return (ft_flag_plus(lst));
	if (lst->flags[0] == '-' || (lst->flags[0] >= '0' && lst->flags[0] <= '9'))
	{
		if (lst->flags[1] == '.')
			lst->flags[0] = '.';
		else
			return (ft_flag_minus(lst));
	}
	if (lst->flags[0] == '.')
		return (ft_flag_dot(lst));
	if (lst->flags[0] == ' ')
		return (ft_flag_space(lst));
	if (lst->flags[0] == '#')
		return (ft_flag_hashtag(lst));
	return (0);
}

int	ft_flag_space(t_args *lst)
{
	int	i;
	int	space;

	space = 0;
	i = ft_strlen(lst->buff);
	if (lst->type != 'd' && lst->type != 'i' && lst->type != 's')
		return (write(1, "flag ' ' can't be used for this type", 37), 0);
	if (lst->type == 's')
	{
		if (lst->buff[0] == '\0')
		{
			lst->flags[0] = '0';
			return (ft_flag_zero(lst));
		}
		write(1, lst->buff, i);
		return (i);
	}
	if (ft_atoi_printf(lst->buff) >= 0 && ++space)
		write(1, " ", 1);
	write(1, lst->buff, i);
	return (i + space);
}

int	ft_flag_dot(t_args *lst)
{
	if (lst->type == 's')
	{
		if (lst->buff[0] == '\0')
			return (0);
		if (!(lst->flags[1] >= '0' && lst->flags[1] <= '9'))
			return (0);
	}
	return (ft_flag_zero(lst));
}
