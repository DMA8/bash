/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 08:58:00 by arashido          #+#    #+#             */
/*   Updated: 2023/01/25 18:39:06 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}

// int main ()
// {
// 	printf("%s", ft_strrchr("abdulloh rashidov",'h'));
// }
// bu funksiya bizga chappasiga keladi va bizga ohiridan 
// boshlab suragan narsamizdi chiara 
// out :h rashidov buladi