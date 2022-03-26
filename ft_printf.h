/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tohebeka <tohebeka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 16:51:41 by tohebeka      #+#    #+#                 */
/*   Updated: 2021/12/13 18:09:56 by tohebeka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define BIG "0123456789ABCDEF"
# define SMALL "0123456789abcdef"
# define DEC "0123456789"

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_args{
	char				*writenstr;
	char				writec;
	int					writennum;
	unsigned long long	ulong;
	unsigned int		unum;
	int					a;
	int					*counter;
}				t_args;

int		ft_printf(const char *str, ...);
int		ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);
int		ft_putnbr(long nbr, int base, char *base_str, int *counter);
int		ft_u_putlong(unsigned long nbr, int base, char *base_str, int *counter);

#endif
