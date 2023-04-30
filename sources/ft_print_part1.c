/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_part1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <william.ruetsuquet@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 01:36:36 by wruet-su          #+#    #+#             */
/*   Updated: 2023/04/30 02:09:08 by wruet-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_flag_plus(t_args *lst)
{
	int	i;
	int	plus;

	plus = 0;
	i = ft_strlen(lst->buff);
	if (lst->type != 'd' && lst->type != 'i')
		return (write(1, "flag '+' can't be used for this type", 37), 0);
	if (ft_atoi_printf(lst->buff) >= 0 && ++plus)
		write(1, "+", 1);
	write(1, lst->buff, i);
	return (i + plus);
}

int	ft_flag_hashtag(t_args *lst)
{
	int	value;

	value = ft_strlen(lst->buff);
	if (!(lst->buff[0] == '0' && !lst->buff[1]))
	{
		if (lst->type == 'x')
			write(1, "0x", 2);
		if (lst->type == 'X')
			write(1, "0X", 2);
	}
	write(1, lst->buff, value);
	if ((lst->type == 'x' || lst->type == 'X') && \
		!(lst->buff[0] == '0' && !lst->buff[1]))
		value += 2;
	return (value);
}

int	ft_atoi_printf(const char *str)
{
	unsigned long long	result;
	int					sign;
	int					i;

	sign = 1;
	result = 0;
	i = 0;
	while (str[i] != '-' && !(str[i] >= '0' && str[i] <= '9'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - 48);
	if (i == 0)
		return (write(1, "Bad input: atoi fail", 21), -1);
	return (result * sign);
}

static int	ft_flag_minus_part2(t_args *lst, int width, int y)
{
	int		i;
	char	*buff;

	i = -1;
	buff = malloc(width + 1);
	i = -1;
	while (++i < width + 1)
		buff[i] = ' ';
	while (y-- > 0)
			buff[y] = lst->buff[y];
	write(1, buff, width);
	free(buff);
	return (width);
}

int	ft_flag_minus(t_args *lst)
{
	int	i;
	int	y;
	int	width;

	i = 0;
	if (lst->flags[0] == '-' && lst->flags[1] != '\0')
		i += 1;
	width = ft_atoi_printf(&lst->flags[i]);
	if (width == -1)
		return (write(1, "atoi err\n", 10), -1);
	y = 0;
	while (lst->buff[y])
		y++;
	if (y == 0 && lst->type != 's')
		y = 1;
	if (y > width)
	{
		i = ft_strlen(lst->buff);
		return (write(1, lst->buff, i), i);
	}
	return (ft_flag_minus_part2(lst, width, y));
}
