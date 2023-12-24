/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:34:25 by arashido          #+#    #+#             */
/*   Updated: 2023/01/31 20:44:03 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(char c, va_list lst)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(lst, int));
	else if (c == 's')
		len += ft_putstr(va_arg(lst, char *));
	else if (c == 'i' || c == 'd')
		len += ft_putnbr(va_arg(lst, int));
	else if (c == 'p')
		len += print_pointer(va_arg(lst, unsigned long));
	else if (c == 'u')
		len += ft_putund(va_arg(lst, unsigned int));
	else if (c == 'x')
		len += ft_hex(va_arg(lst, unsigned int), c);
	else if (c == 'X')
		len += ft_hex(va_arg(lst, unsigned int), c);
	else if (c == '%')
		len += ft_putchar(c);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	lst;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(lst, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_check(str[++i], lst);
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(lst);
	return (len);
}
