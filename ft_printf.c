/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tohebeka <tohebeka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/09 10:53:25 by tohebeka      #+#    #+#                 */
/*   Updated: 2022/03/09 15:41:38 by tohebeka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_arg1(const char *str, int i, va_list *ap, t_args args)
{
	if (str[i + 1] == 'c')
	{
		args.writec = va_arg(*ap, int);
		write(1, &args.writec, 1);
		return (1);
	}	
	if (str[i + 1] == 's')
	{
		args.writenstr = va_arg(*ap, char *);
		if (!args.writenstr)
		{
			ft_putstr_fd("(null)", 1);
			return (6);
		}	
		ft_putstr_fd(args.writenstr, 1);
		return (ft_strlen(args.writenstr));
	}
	if (str[i + 1] == 'd' || str[i + 1] == 'i')
	{
		args.writennum = va_arg(*ap, int);
		*args.counter += ft_putnbr(args.writennum, 10, DEC, args.counter);
		return (*args.counter);
	}
	return (-1);
}

int	put_arg2(const char *str, int i, va_list *ap, t_args args)
{
	if (str[i + 1] == 'p')
	{
		args.ulong = va_arg(*ap, unsigned long);
		ft_putstr_fd("0x", 1);
		*args.counter += ft_u_putlong(args.ulong, 16, SMALL, args.counter);
		return (*args.counter + 2);
	}
	if (str[i + 1] == 'u')
	{
		args.unum = va_arg(*ap, unsigned int);
		*args.counter += ft_u_putlong(args.unum, 10, DEC, args.counter);
		return (*args.counter);
	}	
	if (str[i + 1] == 'x' || (str[i + 1] == 'X'))
	{
		args.unum = va_arg(*ap, int);
		if (str[i + 1] == 'x')
			*args.counter += ft_u_putlong(args.unum, 16, SMALL, args.counter);
		else
			*args.counter += ft_u_putlong(args.unum, 16, BIG, args.counter);
		return (*args.counter);
	}
	return (-1);
}

int	put_arg(const char *str, int i, va_list *ap)
{
	t_args	args;
	int		arg1;
	int		arg2;

	args.a = 0;
	args.counter = &args.a;
	arg1 = put_arg1(str, i, ap, args);
	arg2 = put_arg2(str, i, ap, args);
	if (arg1 == -1)
	{
		if (arg2 == -1)
		{
			if (str[i + 1] == '%')
			{
				write(1, "%%", 1);
				return (1);
			}
			return (-1);
		}
		else
			return (arg2);
	}
	else
		return (arg1);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		val;
	int		i;
	int		length;

	i = 0;
	length = 0;
	val = 0;
	va_start(ap, str);
	while (i < ft_strlen(str))
	{
		if (str[i] == '%')
		{
			length += put_arg(str, i, &ap);
			i += 2;
		}
		else
		{	
			write(1, &str[i], 1);
			i++;
			length++;
		}
	}
	va_end(ap);
	return (length);
}
int main()
{
	printf("%\n");
}