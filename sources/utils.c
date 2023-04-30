/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <william.ruetsuquet@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:13:08 by wruet-su          #+#    #+#             */
/*   Updated: 2023/04/30 02:08:02 by wruet-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putstr(char *str)
{
	if (!str)
		return ;
	write(1, str, ft_strlen(str));
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

int	ft_is_flag(char c, t_flags *flags)
{
	if (flags == NULL)
	{
		if (c == '-' || c == '+' || c == '0' || c == '#' || \
			c == '.' || c == ' ')
			return (0);
		return (-1);
	}
	if (c == '-' )
		flags->minus += 1;
	else if (c == '+' )
		flags->plus += 1;
	else if (c == '0' )
		flags->zero += 1;
	else if (c == '#' )
		flags->hashtag += 1;
	else if (c == '.' )
		flags->point += 1;
	else if (c == ' ' )
		flags->space += 1;
	else
		return (-1);
	if (flags->minus > 1 || flags->plus > 1 || flags->zero > 1 || \
		flags->hashtag > 1 || flags->point > 1 || flags->space > 1)
		return (-1);
	return (0);
}

char	*ft_strdup_len(char *str, int len)
{
	char	*new;
	int		i;

	if (!str || len == 0)
		return (NULL);
	i = -1;
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	while (++i < len && str[i])
		new[i] = str[i];
	new[i] = '\0';
	return (new);
}

int	ft_is_a_conv(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || \
		c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}
