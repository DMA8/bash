/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 08:59:41 by arashido          #+#    #+#             */
/*   Updated: 2023/01/25 19:08:58 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dstr;
	char	*srcr;

	dstr = (char *)dst;
	srcr = (char *)src;
	if (dst == src)
		return (dst);
	if (src < dst)
	{
		while (len--)
		{
			dstr[len] = srcr[len];
		}
		return (dst);
	}
	else
	{
		while (len--)
		{
			*dstr++ = *srcr++;
		}
		return (dst);
	}
}

// int main()
// {
// 	char i[] = "good";
// 	char c[] = "hello";

// 	printf("n: %s\n", ft_memmove(&i, &c, 5));
// 	return (0);
// }
// bunda bizdi hotira kuchadi boshqa joyga 