/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tohebeka <tohebeka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/09 15:07:06 by tohebeka      #+#    #+#                 */
/*   Updated: 2021/12/10 18:17:01 by tohebeka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
		i++;
	write(fd, s, i);
}

int	ft_putnbr(long nbr, int base, char *base_str, int *counter)
{
	if (nbr < 0)
	{
		*counter += write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr >= base)
		*counter += ft_putnbr(nbr / base, base, base_str, counter);
	write(1, &base_str[nbr % base], 1);
	return (1);
}

int	ft_u_putlong(unsigned long nbr, int base, char *base_str, int *counter)
{
	if (nbr < 0)
	{
		*counter += write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr >= (unsigned long) base)
		*counter += ft_u_putlong(nbr / base, base, base_str, counter);
	write(1, &base_str[nbr % base], 1);
	return (1);
}
