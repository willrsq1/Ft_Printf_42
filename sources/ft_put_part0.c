/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_part0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <william.ruetsuquet@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:38:39 by wruet-su          #+#    #+#             */
/*   Updated: 2023/04/30 02:06:37 by wruet-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_get_buff(char c, va_list varl)
{
	if (c == 'c')
		return (ft_char(va_arg(varl, int)));
	else if (c == 's')
		return (ft_string(va_arg(varl, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(varl, int)));
	else if (c == 'u')
		return (ft_putnbr_unsigned(va_arg(varl, unsigned int)));
	else if (c == 'p')
		return (ft_putnbr_ptr(va_arg(varl, unsigned long long)));
	else if (c == 'x')
		return (ft_putnbr_base_small(va_arg(varl, unsigned int)));
	else if (c == 'X')
		return (ft_putnbr_base_big(va_arg(varl, unsigned int)));
	else if (c == '%')
		return (ft_char('%'));
	return (NULL);
}

char	*ft_char(char c)
{
	char	*buff;

	buff = malloc(2);
	if (!buff)
		return (NULL);
	buff[0] = c;
	buff[1] = '\0';
	return (buff);
}

static char	*ft_string_null(void)
{
	char	*buff;

	buff = malloc(8);
	buff[0] = '(';
	buff[1] = 'n';
	buff[2] = 'u';
	buff[3] = 'l';
	buff[4] = 'l';
	buff[5] = ')';
	buff[6] = '\0';
	return (buff);
}

char	*ft_string(char *str)
{
	int		i;
	char	*buff;

	i = 0;
	if (!str)
		return (ft_string_null());
	while (str && str[i])
		i++;
	buff = malloc(i + 1);
	if (!buff)
		return (NULL);
	i = -1;
	while (str && str[++i])
		buff[i] = str[i];
	buff[i] = '\0';
	return (buff);
}
