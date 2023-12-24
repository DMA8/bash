/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:00:01 by arashido          #+#    #+#             */
/*   Updated: 2023/01/20 10:28:01 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*m;
	const unsigned char	*j;
	size_t				i;

	i = 0;
	m = (unsigned char *)s1;
	j = (unsigned char *)s2;
	while (i < n)
	{
		if (m[i] != j[i])
			return (m[i] - j[i]);
		i++;
	}
	return (0);
}

// int main()
// {
// 	char s1[] = "hello";
// 	char s2[] = "assalom";
// 	printf("%d", ft_memcmp(s1, s2, 5));
// }

// output is 7 chunki bizaga ikkita str lani solishtirib ulani ascii table da 
// turgan ornini bir biridan ayirib bizaga output beradi hozir buyoda
// 104 - 97 = 7
