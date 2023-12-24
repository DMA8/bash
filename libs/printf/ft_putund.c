/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putund.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:54:44 by arashido          #+#    #+#             */
/*   Updated: 2023/01/31 19:10:21 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putund(unsigned int n)
{
	int	len;

	len = 0;
	if (n > 9)
	{
		len += ft_putund(n / 10);
	}
	len += ft_putchar((n % 10) + '0');
	return (len);
}

// int	main(void)
// {
// 	ft_putund(-1500000);
// }
