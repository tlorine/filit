/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:49:12 by tlorine           #+#    #+#             */
/*   Updated: 2019/04/15 18:10:42 by tlorine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t c;

	i = 0;
	c = 0;
	if (s1 || s2)
	{
		while (s1[i] != '\0')
			i++;
		while (c < n && s2[c] != '\0')
		{
			s1[i] = s2[c];
			i++;
			c++;
		}
		s1[i] = '\0';
		return (s1);
	}
	return (NULL);
}
