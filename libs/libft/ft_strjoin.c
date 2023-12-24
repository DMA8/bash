/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:17:56 by arashido          #+#    #+#             */
/*   Updated: 2023/01/21 12:58:40 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	n;
	char	*j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	j = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!j)
		return (NULL);
	i = 0;
	n = 0;
	while (s1[i])
	{
		j[n++] = s1[i++];
	}
	i = 0;
	while (s2[i])
	{
		j[n++] = s2[i++];
	}
	j[n] = 0;
	return (j);
}

// bu bizaga ikkita funksiyani bir biriga qoshib beradi
// agarda bizaga 2 ta str dan bittasi NULL boladigan bosa bizaga NULL qaytaradi
// 'abdulloh''rashidov' = abdullohrashidov