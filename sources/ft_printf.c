/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <william.ruetsuquet@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 19:56:23 by wruet-su          #+#    #+#             */
/*   Updated: 2023/04/30 02:30:08 by wruet-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	varl;
	t_args	first;

	first.buff = NULL;
	first.buff = NULL;
	first.not_arg = -1;
	first.next = NULL;
	if (!str || !str[0] || write(1, NULL, 0) == -1)
		return (-1);
	va_start(varl, str);
	if (ft_start(varl, (char *)str, &first))
		return (ft_lst_free_all(&first), -1);
	va_end(varl);
	return (ft_print_lst(&first));
}

int	ft_start(va_list varl, char *str, t_args *first)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i = ft_no_perc_sign(i, str, first);
		if (i == -1)
			return (-1);
		if (str[i])
			i = ft_args(varl, str, first, i + 1);
		if (i == -1)
			return (-1);
	}
	return (0);
}

int	ft_args(va_list varl, char *str, t_args *first, int i)
{
	char	*flags;
	char	type;
	char	*buff;

	flags = ft_get_flags(str, &i, i);
	if (!str[i] || !flags)
		return (write(1, "FLAGS\n", 7), -1);
	type = str[i++];
	if (!str[i - 1])
		return (write(1, "THING\n", 7), -1);
	buff = ft_get_buff(type, varl);
	if (!buff)
		return (free(flags), write(1, "BUFF ERROR\n", 12), -1);
	if (ft_add_lst(buff, flags, type, first))
	{
		free(buff);
		free(flags);
		return (write(1, "LISTS\n", 7), -1);
	}
	return (i);
}

int	ft_no_perc_sign(int i, char *str, t_args *first)
{
	int		y;
	char	*buff;

	y = i;
	while (str[i] && str[i] != '%')
		i++;
	if (i != y)
	{
		buff = ft_strdup_len(&str[y], i - y);
		if (!buff)
			return (-1);
		if (ft_add_lst_no_arg(buff, NULL, 42, first))
			return (-1);
	}
	return (i);
}
