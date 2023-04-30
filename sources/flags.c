/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <william.ruetsuquet@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 22:25:01 by wruet-su          #+#    #+#             */
/*   Updated: 2023/04/30 02:07:21 by wruet-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_get_flags(char *str, int *start, int y)
{
	char	*flags;
	int		i;

	i = y;
	i = ft_lenght_flags(&str[i], i);
	if (i == -1)
		return (write(1, "Bad imput in flags\n", 20), NULL);
	if (i > y)
		flags = ft_strdup_len(&str[y], i - y);
	else
	{
		flags = malloc(1);
		if (!flags)
			return (NULL);
		flags[0] = '\0';
		return (flags);
	}
	*start += i - y;
	return (flags);
}

void	ft_init_flags(t_flags *flags)
{
	flags->minus = 0;
	flags->plus = 0;
	flags->zero = 0;
	flags->hashtag = 0;
	flags->point = 0;
	flags->space = 0;
}

int	ft_lenght_flags(char *str, int start)
{
	int		i;
	t_flags	flags;
	int		flag_type;

	i = -1;
	ft_init_flags(&flags);
	while (str[++i])
	{
		flag_type = ft_is_flag(str[i], &flags);
		if (ft_is_a_conv(str[i]))
			return (start + i);
		if (flag_type == -1 && !ft_is_a_conv(str[i]))
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				while (str[i] && str[i] >= '0' && str[i] <= '9')
					i++;
				return (start + i);
			}
			return (write(1, "No conversion indicated\n", 25), -1);
		}
	}
	if (!str[i])
		return (write(1, "No conversion indicated\n", 25), -1);
	return (start + i);
}
