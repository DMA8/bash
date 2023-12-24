/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:20:49 by arashido          #+#    #+#             */
/*   Updated: 2023/01/21 17:57:50 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, s + i);
		i++;
	}
}

// void my_func(unsigned int i, char *str)
// {
// 	printf("the result is: %s\n", str);
// }
// int main(void)
// {
// 	char str[10] = "Hello.";
// 	ft_striteri(str, my_func);
// 	printf("The result is %s\n", str);
// }

// bu funksiya bizga str iterate qilib ozim create qilgan funksiyaga qarab 
// bizaga result qaytaradi