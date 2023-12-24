/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 08:57:53 by arashido          #+#    #+#             */
/*   Updated: 2023/01/20 15:25:30 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *n, size_t l)
{
	size_t	i;

	i = 0;
	if (*n == '\0')
	{
		return ((char *)s);
	}
	if (!l)
		return (0);
	i = ft_strlen((char *)n);
	while (*s != '\0' && l-- >= i)
	{
		if (*s == *n && ft_memcmp(s, n, i) == 0)
			return ((char *)s);
		s++;
	}
	return (0);
}

// int main ()
// {
// 	const char	*largestring = "Bar Foo Lpz";
// 	const char	*smallstring = "Bar";
//     char		*ptr;

// 	ptr = ft_strnstr(largestring, smallstring, 4);
// 	printf("%s",ptr); 
// }
// bu bizga 1 suzdi topadi boshqasi bulsa taxtdi chiqarmaydi
// outda hozi butun taxt chiqado