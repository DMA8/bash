/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:47:08 by arashido          #+#    #+#             */
/*   Updated: 2023/01/23 17:36:09 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s;

	s = malloc (ft_strlen(s1) + 1);
	if (!s)
		return (NULL);
	s = ft_memcpy(s, s1, ft_strlen(s1) + 1);
	return (s);
}

// int	main(void)
// {
// 	char	str[] = "hello";
// 	char	*s2;
// 	s2 = ft_strdup(str);
// 	printf("%s", s2);
// }
