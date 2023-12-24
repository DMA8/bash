/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 08:57:22 by arashido          #+#    #+#             */
/*   Updated: 2023/11/21 14:58:35 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (0);
}

// int main ()
// {
// 	char i[] = "hello";
// 	printf("%s",ft_strchr(i, 'l'));
// }
// bu bizga "l" dan boshla hamma harflar chiqaradi
// bunda biz  int char oziga l di iscii qib oladi
// keyin unga qushadi
