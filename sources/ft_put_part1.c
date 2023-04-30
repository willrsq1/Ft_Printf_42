/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_part1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <william.ruetsuquet@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 01:07:36 by wruet-su          #+#    #+#             */
/*   Updated: 2023/04/30 02:07:10 by wruet-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_putnbr_min_int(char *buffer)
{
	free(buffer);
	buffer = malloc(15);
	if (!buffer)
		return (NULL);
	buffer[0] = '-';
	buffer[1] = '2';
	buffer[2] = '1';
	buffer[3] = '4';
	buffer[4] = '7';
	buffer[5] = '4';
	buffer[6] = '8';
	buffer[7] = '3';
	buffer[8] = '6';
	buffer[9] = '4';
	buffer[10] = '8';
	buffer[11] = '\0';
	return (buffer);
}

static char	*ft_putnbr_p2(char *buffer, int i, int minus, int nb)
{
	while (i > 0)
	{
		buffer[i + minus - 1] = (nb % 10) + 48;
		nb = nb / 10;
		i--;
	}
	return (buffer);
}

char	*ft_putnbr(int nb)
{
	char	*buffer;
	int		i;
	int		nb_cpy;
	int		minus;

	buffer = malloc(15);
	if (!buffer)
		return (NULL);
	minus = 0;
	if (nb == -2147483648)
		return (buffer = ft_putnbr_min_int(buffer));
	if (nb < 0 && ++minus)
	{
		nb = -nb;
		buffer[0] = '-';
	}
	nb_cpy = nb;
	i = 0;
	while (++i && nb_cpy > 9)
		nb_cpy = nb_cpy / 10;
	buffer[i + minus] = '\0';
	return (ft_putnbr_p2(buffer, i, minus, nb));
}

char	*ft_putnbr_unsigned(unsigned int nb)
{
	char				*buffer;
	int					i;
	unsigned int		nb_cpy;

	buffer = malloc(15);
	if (!buffer)
		return (NULL);
	nb_cpy = nb;
	i = 0;
	while (++i && nb_cpy > 9)
		nb_cpy = nb_cpy / 10;
	buffer[i] = '\0';
	while (i > 0)
	{
		buffer[i - 1] = (nb % 10) + 48;
		nb = nb / 10;
		i--;
	}
	return (buffer);
}
