/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:18:41 by arashido          #+#    #+#             */
/*   Updated: 2023/01/23 18:00:12 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*s1;

	if (!s || !f)
		return (NULL);
	s1 = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!s1)
	{
		return (0);
	}
	i = 0;
	while (s[i])
	{
		s1[i] = f(i, s[i]);
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

// char my_func(unsigned int i, char str)
// {
// 	printf("%c \n", str);
// 	return str - 32;
// }
// int main()
// {
// 	char str[10] = "hello.";
// 	char *result = ft_strmapi(str, my_func);
// 	printf("The result is %s\n", result);
// 	return 0;
// }

// bu funksiya biza bergan str ni toliq aylanib yuborib nima shart bergan
// shun shartti bajarib qilib bizaga qaytaradi.