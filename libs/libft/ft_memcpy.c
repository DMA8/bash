/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 08:59:52 by arashido          #+#    #+#             */
/*   Updated: 2023/01/20 10:30:09 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dest;
	char	*source;

	i = 0;
	dest = (char *)dst;
	source = (char *)src;
	if (dest == source || !n)
	{
		return (dest);
	}
	while (i < n)
	{
		dest[i] = source[i];
		i++;
	}
	return (dest);
}

// int main ()
// {
// 	char m[6]= "hello";
// 	char n[7];
// 	printf("%s",ft_memcpy(n,m,7));
// }
// bu bizaga hozir bitta str dan ikkinchisiga valueni kochirib otadi