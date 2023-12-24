/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:24:46 by arashido          #+#    #+#             */
/*   Updated: 2023/11/21 14:51:22 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**join_array(char **final, char **s1, char **s2)
{
	int	i;
	int	j;
	int	total_rows;

	if (!final || !s1 || !s2)
		return (NULL);
	i = -1;
	j = -1;
	while (++i < ft_array_len(s1))
	{
		final[++j] = ft_strdup((char *)s1[i]);
	}
	i = -1;
	while (++i < ft_array_len(s2))
		final[++j] = ft_strdup((char *)s2[i]);
	total_rows = ft_array_len(s1) + ft_array_len(s2);
	final[total_rows] = NULL;
	return (final);
}

char	**ft_join(char **s1, char **s2)
{
	int		s1_rows;
	int		s2_rows;
	char	**final;

	s1_rows = 0;
	s2_rows = 0;
	if (!s1 || !s2)
		return (NULL);
	s1_rows = ft_array_len(s1);
	s2_rows = ft_array_len(s2);
	final = (char **)malloc((s1_rows + s2_rows + 1) * sizeof(char *));
	if (final == NULL)
		return (final);
	final = join_array(final, s1, s2);
	free_array(s1);
	return (final);
}
