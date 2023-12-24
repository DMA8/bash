/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 08:59:34 by arashido          #+#    #+#             */
/*   Updated: 2023/01/20 08:59:36 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i++] = c;
	}
	return (b);
}

// int main (int argc, char *argv[])
// {
//     char arr1[] = { 3, 4};
//     char arr2[] = { 1, 2};
//     ft_memset(arr1, 1, 2 * sizeof(char));
//     printf("%d %d\n", arr1[0], arr1[1]);
//     return(0);
// }
// out 1 1 buladi buladi 