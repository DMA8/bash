/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 08:57:35 by arashido          #+#    #+#             */
/*   Updated: 2023/11/21 14:58:54 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize)
	{
		while (i < dstsize - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

// int main ()
// {
//     char d[] = {"xyz"};
//     char s[] = {"ccccc"};
//     printf("d: %zu", ft_strlcpy(d, s, 4));
//     return (0);
// }
// bunda hozi copy qildu s ni d ga
// almashtirdi va uni uzunligini chiqardi
// out : d : 5
