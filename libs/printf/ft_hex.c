/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:12:22 by arashido          #+#    #+#             */
/*   Updated: 2023/01/31 16:54:56 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex(unsigned int n, char c)
{
	int		len;
	char	*hex;

	len = 1;
	if (c == 'X')
		hex = "0123456789ABCDEF";
	if (c == 'x')
		hex = "0123456789abcdef";
	if (n > 15)
		len += ft_hex(n / 16, c);
	ft_putchar (hex[n % 16]);
	return (len);
}

// #include <stdio.h>

// int main()
// {
// 	int num = 21;
// 	ft_hex(num, 'x');
// }

// buyoda biza hexidecimal number topamiz misol uchun bizada 
// n = 21; buyoda hozir n / 16 = 1 keyin 21 % 16 = 5 shunda 
// output: 15.