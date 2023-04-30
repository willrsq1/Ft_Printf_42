/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flag_zero.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <william.ruetsuquet@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:56:55 by wruet-su          #+#    #+#             */
/*   Updated: 2023/04/30 02:06:11 by wruet-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_zero_part2(t_args *lst, int width, int y, int i)
{
	if (lst->flags[0] == '.' && lst->type == 's')
	{
		if (y < width)
			width = y;
		write(1, lst->buff, width);
		return (width);
	}
	i = ft_strlen(lst->buff);
	if (lst->type == 's' && y >= width)
		return (write(1, lst->buff, i), i);
	if (lst->type == 's')
	{
		y = 0;
		while (y++ < width - i)
			write(1, " ", 1);
		write(1, lst->buff, i);
		return (width);
	}
	write(1, lst->buff, i);
	return (i);
}

static char	*ft_zero_part3(t_args *lst, char *buff, int y, int width)
{
	int	i;

	i = -1;
	while (++i < width + 1)
		buff[i] = '0';
	i--;
	buff[i] = '\0';
	while (y >= 0)
	{
		if (lst->buff[y] == '-' && lst->flags[0] == '0')
			buff[0] = lst->buff[y];
		else if (!(lst->flags[0] == '.' && y == 0 && lst->buff[y] == '-'))
			buff[i] = lst->buff[y];
		i--;
		y--;
	}
	return (buff);
}

int	ft_flag_zero(t_args *lst)
{
	int		i;
	int		y;
	int		width;
	char	*buff;

	i = 0;
	if (lst->flags[0] != '0')
		i++;
	width = ft_atoi_printf(&lst->flags[i]);
	if (width == -1)
		return (write(1, "atoi err\n", 10), -1);
	y = 0;
	while (lst->buff[y])
		y++;
	if (y > width || lst->type == 's')
		return (ft_zero_part2(lst, width, y, i));
	buff = malloc(width + 1);
	buff = ft_zero_part3(lst, buff, y, width);
	y = 0;
	if (lst->flags[0] == '.' && lst->buff[0] == '-' && ++y)
		write(1, &lst->buff[0], 1);
	write(1, buff, width);
	free(buff);
	return (width + y);
}
