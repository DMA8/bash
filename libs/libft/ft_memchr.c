/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:00:07 by arashido          #+#    #+#             */
/*   Updated: 2023/01/20 10:16:54 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}

// int	main()
// {
// 	char t[6] = {'h', 'e', 'l', 'l', 'o'};
// 	printf ("%s", ft_memchr(t, 'e', 6));
// }

// cs	char  'o'
// bu yerda bizga o ni qidiry``abdi