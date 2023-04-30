/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_part2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <william.ruetsuquet@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 01:12:14 by wruet-su          #+#    #+#             */
/*   Updated: 2023/04/30 02:14:55 by wruet-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_putnbr_ptr_null(void)
{
	char	*buffer;

	buffer = malloc(8);
	buffer[0] = '(';
	buffer[1] = 'n';
	buffer[2] = 'i';
	buffer[3] = 'l';
	buffer[4] = ')';
	buffer[5] = '\0';
	return (buffer);
}

char	*ft_putnbr_ptr(unsigned long long nb)
{
	char					*buffer;
	int						i;
	unsigned long long		nb_cpy;

	if (!nb)
		return (ft_putnbr_ptr_null());
	buffer = malloc(25);
	if (!buffer)
		return (NULL);
	buffer[0] = '0';
	buffer[1] = 'x';
	nb_cpy = nb;
	i = 2;
	while (++i && nb_cpy > 15)
		nb_cpy = nb_cpy / 16;
	buffer[i] = '\0';
	while (i > 2)
	{
		buffer[i - 1] = (BASE_HEX_MIN[nb % 16]);
		nb = nb / 16;
		i--;
	}
	return (buffer);
}

char	*ft_putnbr_base_small(unsigned int nb)
{
	char					*buffer;
	int						i;
	unsigned long long		nb_cpy;

	buffer = malloc(35);
	if (!buffer)
		return (NULL);
	nb_cpy = nb;
	i = 0;
	while (++i && nb_cpy > 15)
		nb_cpy = nb_cpy / 16;
	buffer[i] = '\0';
	while (i > 0)
	{
		buffer[i - 1] = (BASE_HEX_MIN[nb % 16]);
		nb = nb / 16;
		i--;
	}
	return (buffer);
}

char	*ft_putnbr_base_big(unsigned int nb)
{
	char					*buffer;
	int						i;
	unsigned long long		nb_cpy;

	buffer = malloc(35);
	if (!buffer)
		return (NULL);
	nb_cpy = nb;
	i = 0;
	while (++i && nb_cpy > 15)
		nb_cpy = nb_cpy / 16;
	buffer[i] = '\0';
	while (i > 0)
	{
		buffer[i - 1] = (BASE_HEX_CAPS[nb % 16]);
		nb = nb / 16;
		i--;
	}
	return (buffer);
}
