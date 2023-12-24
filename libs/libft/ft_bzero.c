/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 08:54:30 by arashido          #+#    #+#             */
/*   Updated: 2023/01/20 16:05:40 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
	return ;
}

// int main()
// {
//     char byte[5] = {1, 3, 'f', 2, 0};
//     ft_bzero(byte, 5);
//     int i = 0;
//     while (i < 5)
//     {
//         printf("%d", byte[1]);
//         /* code */
//         i++;
//     }
//     return (0);
// }
// bu bizda hamma kegan valuelarni 0 ga aylantirib beradi.
