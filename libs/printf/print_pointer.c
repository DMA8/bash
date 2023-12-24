/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:16:18 by arashido          #+#    #+#             */
/*   Updated: 2023/01/31 20:37:38 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_p(unsigned long n)
{
	int		len;
	char	*hex;

	len = 1;
	hex = "0123456789abcdef";
	if (n > 15)
		len += ft_hex_p(n / 16);
	ft_putchar(hex[n % 16]);
	return (len);
}

int	print_pointer(unsigned long n)
{
	int	len;

	len = ft_putstr("0x");
	if (n == 0)
		len += ft_putchar('0');
	else
		len += ft_hex_p(n);
	return (len);
}
