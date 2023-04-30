/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <william.ruetsuquet@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:07:46 by wruet-su          #+#    #+#             */
/*   Updated: 2023/04/30 02:31:03 by wruet-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h> //for tests

# ifndef BASE_HEX_CAPS
#  define BASE_HEX_CAPS "0123456789ABCDEF"
# endif

# ifndef BASE_HEX_MIN
#  define BASE_HEX_MIN "0123456789abcdef"
# endif

typedef struct s_args	t_args;

typedef struct s_args
{
	char	*buff;
	char	*flags;
	char	type;
	int		not_arg;
	t_args	*next;
}		t_args;

typedef struct s_flags
{
	int		minus;
	int		plus;
	int		zero;
	int		hashtag;
	int		point;
	int		space;
}		t_flags;

/*		BUFF_CREATION.C */

char	*ft_get_buff(char c, va_list varl);
char	*ft_char(char c);
char	*ft_string(char *str);

/*		FT_PRINT_PART0.C*/

int		ft_print_with_flags(t_args *lst);
int		ft_flag_space(t_args *lst);
int		ft_flag_dot(t_args *lst);

/*		FT_PRINT_PART1.C*/

int		ft_flag_plus(t_args *lst);
int		ft_flag_hashtag(t_args *lst);
int		ft_atoi_printf(const char *str);
int		ft_flag_minus(t_args *lst);

/*		FT_FLAG_ZERO.C*/

int		ft_flag_zero(t_args *lst);

/*		FT_PRINTF.C */

int		ft_start(va_list varl, char *str, t_args *first);
int		ft_printf(const char *str, ...);
int		ft_args(va_list varl, char *str, t_args *first, int i);
int		ft_no_perc_sign(int i, char *str, t_args *first);

/*		FLAGS.C */

char	*ft_get_flags(char *str, int *pos, int y);
int		ft_lenght_flags(char *str, int start);

/*		LST.C */

int		ft_add_lst_no_arg(char *buff, char *flags, int not_arg, t_args *first);
int		ft_add_lst(char *buff, char *flags, char type, t_args *first);
int		ft_print_lst(t_args *lst);
void	ft_lst_free_all(t_args *lst);

/*		UTILS.C */

char	*ft_strdup_len(char *str, int len);
void	ft_putstr(char *str);
int		ft_is_flag(char c, t_flags *flags);
int		ft_strlen(char *str);
int		ft_is_a_conv(char c);

/*		FT_PUT_PART1.C */

char	*ft_putnbr(int nb);
char	*ft_putnbr_unsigned(unsigned int nb);

/*		FT_PUT_PART2.C */

char	*ft_putnbr_ptr(unsigned long long nb);
char	*ft_putnbr_base_small(unsigned int nb);
char	*ft_putnbr_base_big(unsigned int nb);

#endif
